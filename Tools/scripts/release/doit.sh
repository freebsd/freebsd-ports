#!/bin/sh
# $FreeBSD$

pathtoports=$1
dir=`dirname $0`
if [ "X$dir" = "X." ]; then
  dir=`pwd`
fi

##############################################################################
#
# Tweak these parameters to match your configuration and make sure to check
# that the disc information in config is correct.
#
# You'll also want to place a recent copy of print-cdrom-packages.sh in the
# $scripts directory.
#

  ports="$dir/ports"
  dists="$ports/distfiles"
   logs="$dir/gen"
   pkgs="$ports/packages/All"
scripts="$dir"
   xdep_re="^XFree86-3.3.6_1[0-9]$"
#indexfile="INDEX-5"
indexfile="INDEX"
#
##############################################################################

test -d $logs || mkdir -p $logs

if [ ! -d "$ports" ]; then
  if [ -z "$pathtoports" ]; then
    echo "Missing path to ports/packages toree to process for setup.sh."
    exit 1
  fi
  $scripts/setup.sh $pathtoports
  echo ""
  echo "Make sure you tweak $dir/config to suit your needs."
  echo ""
fi

if [ ! -f "$logs/restricted.sh" ]; then
  echo "===> restricted list generation started at $(date)"
  (cd $ports; PORTSDIR=$ports make ECHO_MSG=/usr/bin/true \
    clean-restricted-list > $logs/restricted.sh)
  echo "===> restricted list generation ended at $(date)"
  echo $(grep -c '^#' $logs/restricted.sh) "ports in $logs/restricted.sh"
fi

if [ ! -f "$logs/.restricted.done" ]; then
  echo "===> cleaning restricted files"
  sh $logs/restricted.sh
  touch $logs/.restricted.done
fi

if [ ! -f "$logs/cdrom.sh" ]; then
  echo "===> cdrom list generation started at $(date)"
  (cd $ports; PORTSDIR=$ports make ECHO_MSG=/usr/bin/true \
    clean-for-cdrom-list > $logs/cdrom.sh)
  echo "===> cdrom list generation ended at $(date)"
  echo $(grep -c '^#' $logs/cdrom.sh) "ports in $logs/cdrom.sh"
fi

if [ ! -f "$logs/.cdrom.done" ]; then
  echo "===> cleaning non-CDROM-able files"
  sh $logs/cdrom.sh
  touch $logs/.cdrom.done
fi

if [ ! -f "$logs/$indexfile" ]; then
  echo "===> copying INDEX file from $ports/$indexfile"
  $scripts/scrubindex.pl $pkgs $ports/$indexfile > $logs/INDEX
  $scripts/checkdeps.pl $pkgs $logs/INDEX | sort -u | \
    sed -e 's/^/missing dependency: /'
fi

echo -n "Create a list of needed files for each disc? [y] "
read ans
if [ X$ans != Xn -a X$ans != XN ]; then
  >$logs/need.ALL
  for disc in `cat config | grep -v '#' | sed -e 's/[ 	].*//'`; do
    echo "disc $disc" >> $logs/need.ALL
    $scripts/print-cdrom-packages.sh `echo $disc | sed -e 's/^disc//'` \
      $ports | grep -Ev $xdep_re | tee $logs/need.$disc >> $logs/need.ALL
  done
fi

echo -n "Populate the discs now? [y] "
read ans
if [ X$ans != Xn -a X$ans != XN ]; then
  for disc in `ls -d disc? 2>/dev/null`; do
    echo "===> deleting $disc"
    rm -rf $disc
  done
  if [ -d "scratch" ]; then
    echo "===> deleting scratch"
    rm -rf scratch
  fi
  echo "Calling oneshot.pl config $logs/need.ALL $logs/INDEX $ports $pkgs/../ $dists"
  $scripts/oneshot.pl config $logs/need.ALL $logs/INDEX $ports $pkgs/../ $dists
  for disc in `ls -d disc? 2>/dev/null`; do
    echo "===> cleaning $disc"
    if [ -d "$disc/packages/All" ]; then
      $scripts/checkdeps.pl $disc/packages/All $disc/packages/INDEX | \
        sort -u | sed -e 's/^/missing package: /'
      (
        cd $disc/packages/All; \
        $scripts/scrubindex.pl . ../INDEX > ../INDEX.new; \
        mv ../INDEX.new ../INDEX; \
        find . -name '*.tgz' | xargs /sbin/md5 > CHECKSUM.MD5; \
      )
    fi
    du -ck $disc | grep total
  done
fi

echo -n "Make sure the 'needed' packages made it on the right disc(s)? [y] "
read ans
if [ X$ans != Xn -a X$ans != XN ]; then
  for disc in `ls -d disc? 2>/dev/null`; do
    echo "===> checking $disc"
    > $logs/have.$disc
    if [ -d "$disc/packages/All" ]; then
      ( cd $disc/packages/All && find . -name '*.tgz' | \
        sed -e 's/\.tgz//' -e 's/^\.\///' | sort) > \
        $logs/have.$disc
    fi
    diff -u $logs/have.$disc $logs/need.$disc | grep -e '^\+' | \
      grep -v -e '^\+* ' | sed -e 's/\+//' > $logs/missing.$disc
    if [ -s $logs/missing.$disc ]; then
      echo "===>  missing required packages on $disc"
      cat $logs/missing.$disc
    fi
  done
fi
