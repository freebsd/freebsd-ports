# New ports collection makefile for:	unrar-iconv
# Date created:				18 Oct 2007
# Whom:					Yarodin <yarodin@gmail.com>
#
# $FreeBSD$
#

PKGNAMESUFFIX=	-iconv

MAINTAINER=	yarodin@gmail.com

MASTERDIR=	${.CURDIR}/../unrar

EXTRA_PATCHES=	${.CURDIR}/files/patch-iconv

USE_ICONV=	yes
MAKE_ENV=	LOCALBASE="${LOCALBASE}"

CONFLICTS=	unrar-[0-9]* zh-unrar-[0-9]*

post-install:
	@${ECHO_MSG} "===> Added iconv support, see new switches:"
	@${ECHO_MSG} "     la, ll and lo at \"unrar -?\""
	@${ECHO_MSG} "===> REMEMBER!!!: Windows rar archives using old DOS encodings as internal encoding."
	@${ECHO_MSG} "     CP866 for russian lang for example."

.include "${MASTERDIR}/Makefile"
