# $FreeBSD$
#
# MAINTAINER: portmgr@FreeBSD.org
#
# This file handles converting keywords to pkg_install compatible format.
# It will be removed once pkg_install is EOL.
#

#  @sample somefile.conf.sample
# ->
#  @comment begin @sample somefile.conf.sample
#  @unexec if cmp -s %D/etc/somefile.conf %D/etc/somefile.conf.sample; then rm -f %D/etc/somefile.conf; fi
#  etc/somefile.conf.sample
#  @exec if ! [ -f %D/etc/somefile.conf ]; then cp %D/etc/somefile.conf.sample %D/etc/somefile.conf; fi
#  @comment end @sample somefile.conf.sample
# 
$1 == "@sample" {
  sample_file=$2
  # Take out .sample
  target_file=substr(sample_file, 0, length(sample_file) - 7)
  print "@comment begin " $0
  print "@unexec if cmp -s '%D/" target_file "' '%D/" sample_file "'; then rm -f '%D/" target_file "'; fi"
  print sample_file
  print "@exec if ! [ -f '%D/" target_file "' ]; then /bin/cp -p '%D/" sample_file "' '%D/" target_file "'; fi"
  print "@comment end " $0
  next
}
# Print everything else as-is
{
  print $0
}
