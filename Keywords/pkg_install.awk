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
##
#  @shell bin/shell
# ->
#  @comment begin @shell bin/shell
#  @exec cp /etc/shells /etc/shells.bak; (grep -v %D/%F /etc/shells.bak; echo %D/%F) >/etc/shells; rm -f /etc/shells.bak
#  @unexec cp /etc/shells /etc/shells.bak; (grep -v %D/%F /etc/shells.bak) >/etc/shells; rm -f /etc/shells.bak
#  @comment end @shell bin/shell

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

$1 == "@shell" {
	shell_file=$2
	print "@comment begin " $0
	print shell_file
	print "@exec cp /etc/shells /etc/shells.bak; (grep -v %D/%F /etc/shells.bak; echo %D/%F) >/etc/shells; rm -f /etc/shells.bak"
	print "@unexec cp /etc/shells /etc/shells.bak; (grep -v %D/%F /etc/shells.bak) >/etc/shells; rm -f /etc/shells.bak"
	print "@comment end " $0
	next
}

# Print everything else as-is
{
  print $0
}
