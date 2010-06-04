#-*- mode: Fundamental; tab-width: 4; -*-
# ex:ts=4
#
# bsd.commands.mk - Common commands used within the ports infrastructure
#
# Created by: Gabor Kovesdan <gabor@FreeBSD.org>
#
# $FreeBSD$
#
# DO NOT COMMIT CHANGES TO THIS FILE BY YOURSELF, EVEN IF YOU DID NOT GET
# A RESPONSE FROM THE MAINTAINER(S) WITHIN A REASONABLE TIMEFRAME! ALL
# UNAUTHORISED CHANGES WILL BE UNCONDITIONALLY REVERTED!
#

COMMANDS_Include_MAINTAINER=		portmgr@FreeBSD.org

.if !defined(_COMMANDSMKINCLUDED)

_COMMANDSMKINCLUDED=     yes

AWK?=		/usr/bin/awk
BASENAME?=	/usr/bin/basename
BRANDELF?=	/usr/bin/brandelf
BZCAT?=		/usr/bin/bzcat
BZIP2_CMD?=	/usr/bin/bzip2
CAT?=		/bin/cat
CHGRP?=		/usr/bin/chgrp
CHMOD?=		/bin/chmod
CHOWN?=		/usr/sbin/chown
CHROOT?=	/usr/sbin/chroot
COMM?=		/usr/bin/comm
CP?=		/bin/cp
CPIO?=		/usr/bin/cpio
CUT?=		/usr/bin/cut
DC?=		/usr/bin/dc
DIALOG?=	/usr/bin/dialog
DIFF?=		/usr/bin/diff
DIRNAME?=	/usr/bin/dirname
EGREP?=		/usr/bin/egrep
EXPR?=		/bin/expr
FALSE?=		false				# Shell builtin
FILE?=		/usr/bin/file
FIND?=		/usr/bin/find
FLEX?=		/usr/bin/flex
FMT?=		/usr/bin/fmt
GMAKE?=		gmake
GREP?=		/usr/bin/grep
GUNZIP_CMD?=	/usr/bin/gunzip -f
GZCAT?=		/usr/bin/gzcat
GZIP?=		-9
GZIP_CMD?=	/usr/bin/gzip -nf ${GZIP}
HEAD?=		/usr/bin/head
ID?=		/usr/bin/id
IDENT?=		/usr/bin/ident
LDCONFIG?=	/sbin/ldconfig
LN?=		/bin/ln
LS?=		/bin/ls
MKDIR?=		/bin/mkdir -p
MKTEMP?=	/usr/bin/mktemp
MOUNT?=		/sbin/mount
MOUNT_DEVFS?=	${MOUNT} -t devfs devfs
# XXX: this is a work-around for an obscure bug where
# mount -t nullfs returns zero status on errors within
# a make target
MOUNT_NULLFS?=	/sbin/mount_nullfs
MV?=		/bin/mv
OBJCOPY?=	/usr/bin/objcopy
OBJDUMP?=	/usr/bin/objdump
PASTE?=		/usr/bin/paste
PAX?=		/bin/pax
PRINTF?=	/usr/bin/printf
PW?=		/usr/sbin/pw
REALPATH?=	/bin/realpath
RM?=		/bin/rm
RMDIR?=		/bin/rmdir
SED?=		/usr/bin/sed
SETENV?=	/usr/bin/env
SH?=		/bin/sh
SORT?=		/usr/bin/sort
STRIP_CMD?=	/usr/bin/strip
SU_CMD?=	/usr/bin/su root -c
SYSCTL?=	/sbin/sysctl
TAIL?=		/usr/bin/tail
TEST?=		test				# Shell builtin
TR?=		LANG=C /usr/bin/tr
TRUE?=		true				# Shell builtin
UMOUNT?=	/sbin/umount
UNAME?=		/usr/bin/uname
UNMAKESELF_CMD?=	${LOCALBASE}/bin/unmakeself
UNZIP_CMD?=	${LOCALBASE}/bin/unzip
WHICH?=		/usr/bin/which
XARGS?=		/usr/bin/xargs
XMKMF?=		${LOCALBASE}/bin/xmkmf -a
YACC?=		/usr/bin/yacc

.if exists(/usr/bin/xz)
XZ_CMD?=	/usr/bin/xz
.else
XZ_CMD?=	${LOCALBASE}/bin/xz
.endif

.if exists(/sbin/md5)
MD5?=		/sbin/md5
.else
MD5?=		md5
.endif
.if exists(/sbin/sha256)
SHA256?=	/sbin/sha256
.elif exists(${LOCALBASE}/sbin/sha256)
SHA256?=	${LOCALBASE}/sbin/sha256
.else
SHA256?=	NO
.endif

# ECHO is defined in /usr/share/mk/sys.mk, which can either be "echo",
# or "true" if the make flag -s is given.  Use ECHO_CMD where you mean
# the echo command.
ECHO_CMD?=	echo				# Shell builtin

# Used to print all the '===>' style prompts - override this to turn them off.
ECHO_MSG?=	${ECHO_CMD}

.if exists(${LOCALBASE}/sbin/pkg_info)
PKG_CMD?=	${LOCALBASE}/sbin/pkg_create
PKG_ADD?=	${LOCALBASE}/sbin/pkg_add
PKG_DELETE?=	${LOCALBASE}/sbin/pkg_delete
PKG_INFO?=	${LOCALBASE}/sbin/pkg_info
PKG_VERSION?=	${LOCALBASE}/sbin/pkg_version
.else
PKG_CMD?=	/usr/sbin/pkg_create
PKG_ADD?=	/usr/sbin/pkg_add
PKG_DELETE?=	/usr/sbin/pkg_delete
PKG_INFO?=	/usr/sbin/pkg_info
PKG_VERSION?=	/usr/sbin/pkg_version
.endif

.endif
