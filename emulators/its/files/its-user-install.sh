#! /bin/sh

# $FreeBSD$

# 1) zcat the PI fs image into a user's directory (the compressed
#    image location is also configurable via "make install")
#
# 2) copy or lndir the /usr/local/share/klh10-ks-its/* (this location
#    is immutable) bits into a user's directory
#
# 3) generate the klh-kn-its-freebsd .ini file for the user
#
# 4) generate ~/.itsrc file for its(1) command so that multple users
#    can use its(1) with different filesystem images.

umask 022

# remove symlinks in cleanup()?

cleanup() {
    rm -f $KLH10_HOME/@PI-IMG@
    echo its-install-user: Terminating.
    exit 1
}

trap cleanup 1 2 3 15

validate_ip() {
    echo $1 | grep -q -s '[^0-9\.]'
    if [ $? != 1 ]; then
	echo its-install-user: IP address must be digits and periods only.
	return 1
    fi
    echo $1 | grep -q -s '\..*\..*\.'
    if [ $? != 0 ]; then
	echo its-install-user: IP address must have at least three periods.
	return 1
    fi
    echo $1 | grep -q -s '\..*\..*\..*\.'
    if [ $? = 0 ]; then
	echo its-install-user: IP address must not exceed three periods.
	return 1
    fi
    echo $1 | grep -q -s '\.\.'
    if [ $? = 0 ]; then
	echo its-install-user: IP address must not have consecutive periods.
	return 1
    fi
    OLDIFS="$IFS"
    IFS=.
    set $1
    for i in $* ; do
	if [ $i -gt 255 ]; then
	    echo its-install-user: Octets of IP address must not exceed 255.
	    IFS="$OLDIFS"
	    return 1 
	fi
    done
    IFS="$OLDIFS"
    return 0
}

in_network=false
for i in `groups`; do
    if [ $i = network ]; then
	in_network=true
	break
    fi
done

if [ `whoami` = root ]; then
    in_network=true
fi

if [ $in_network = false ]; then
    echo WARNING: You must be in group network in order to run a networked ITS.
    echo WARNING: You may still run a non-networked ITS.
fi

if [ ! -d @KLH-SHARE@ ]; then
    echo its-install-user: Can\'t find the emulator directory.
    cleanup
fi

cd @KLH-SHARE@

if [ ! -r @PI-IMG@.bz2 ]; then
    echo its-install-user: The compressed PI disk image is missing.
    cleanup
fi

valid_input=false
while [ $valid_input = false ]; do
    KLH10_HOME=~/klh10-its-home
    echo Where do you want to install the 170MB filesystem image\?
    echo -n "[default: $KLH10_HOME]: "
    read ans
    if [ "$ans" != "" ]; then
	KLH10_HOME=$ans
    fi

    if [ -e $KLH10_HOME -a ! -d $KLH10_HOME ]; then
	echo There already is a non-directory $KLH10_HOME in the filesystem.
	continue
    fi
    if [ ! -d $KLH10_HOME ]; then
	echo -n "$KLH10_HOME is not an existing directory.  Create it? (y/n) "
	read yorn
	case "$yorn" in
	y|Y)
	    if ! mkdir -p $KLH10_HOME ; then
		echo its-install-user: Can\'t make the target directory.
		cleanup
	    else
		valid_input=true
	    fi
	;;
	n|N)
	    echo Type the interupt key to quit or try again.
	;;
	*)
	    echo "I do not recognize your answer. ($yorn)"
	;;
	esac
    elif [ ! -w $KLH10_HOME ]; then
	if ! chmod u+w $KLH10_HOME || chmod g+w $KLH10_HOME; then
	    echo its-install-user: Can\'t write in $KLH10_HOME
	elif [ ! -w $KLH10_HOME ]; then
		echo its-install-user: Can\'t write in $KLH10_HOME
	else
	    valid_input=true
	fi
    else
	valid_input=true
    fi
done

echo Extracting @PI-IMG@.bz2 into $KLH10_HOME
bzcat @PI-IMG@.bz2 > $KLH10_HOME/@PI-IMG@

if [ $? != 0 ]; then
    echo its-install-user: What a mess--the extract failed.
    cleanup
fi

echo Linking up the emulator support files.
for i in *; do
    case $i in
    @PI-IMG@.bz2)  # exclusions
    ;;
    *)
        rm -f $KLH10_HOME/$i && ln -s @KLH-SHARE@/$i $KLH10_HOME
        if [ $? != 0 ]; then
	    echo its-install-user: Failed to make symlinks.
	    cleanup
	fi
    ;;
    esac
done
cd @KLH-LIBEX@
for i in *; do
    rm -f $KLH10_HOME/$i && ln -s @KLH-LIBEX@/$i $KLH10_HOME
    if [ $? != 0 ]; then
	echo its-install-user: Failed to make symlinks.
	cleanup
    fi
done
cd $KLH10_HOME

EM_IP=10.134.198.236
valid_input=false
while [ $valid_input = false ]; do
    echo -n "What is the IP address for the emulated PDP-10? [$EM_IP]: "
    read ans
    if [ "$ans" != "" ]; then
	if validate_ip $ans ; then
	    valid_input=true
	    EM_IP=$ans
	fi
    else
	valid_input=true
    fi
done

GW_IP=10.0.0.1
valid_input=false
while [ $valid_input = false ]; do
    echo -n "What is the IP address for the gateway' [$GW_IP]: "
    read ans
    if [ "$ans" != "" ]; then
	if validate_ip $ans ; then
	    valid_input=true
	    GW_IP=$ans
	fi
    else
	valid_input=true
    fi
done

sed -e "s;@IPADDR@;$EM_IP;g" \
    -e "s;@GWADDR@;$GW_IP;g" \
    -e "s;@KLH-HOME@;$KLH10_HOME;g" \
    < klh10-kn-freebsd.ini.in > klh10-kn-freebsd.ini
if [ $? != 0 ]; then
    echo its-install-user: Failed to generate ini file.
    cleanup
fi
rm -f klh10-kn-freebsd.ini.in

rm -f ~/itsrc
echo KLH10_HOME=$KLH10_HOME > ~/.itsrc
echo PI_IMAGE=$KLH10_HOME/@PI-IMG@ >> ~/.itsrc
if [ $? != 0 ]; then
    echo its-install-user: Failed to generate rc file.
    cleanup
fi
