# Created by: Lev Serebryakov <lev@serebryakov.spb.ru>
# $FreeBSD$

PORTEPOCH=	1
PKGNAMEPREFIX=	mingw32-

MAINTAINER=	cyberbotx@cyberbotx.com
COMMENT=	GNU Binutils for Windows cross-development

MASTERDIR=	${.CURDIR}/../binutils
PLIST=		${.CURDIR}/pkg-plist

BUTARGET=	${PKGNAMEPREFIX:S/-$//}

INFO=		as bfd binutils gprof ld
INFO_PATH=	${BUTARGET}/info

.include "${MASTERDIR}/Makefile"
