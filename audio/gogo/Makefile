# New ports collection makefile for:   gogo no coder
# Version required:    2.22
# Date created:        01 July 1999
# Whom:                Yukihiro Nakai <Nacai@iname.com>
#
# $FreeBSD$
#

DISTNAME=	gogo222
PKGNAME=	gogo-2.22
CATEGORIES=	audio
MASTER_SITES=	http://www.kurims.kyoto-u.ac.jp/~shigeo/soft/gogo2/src/

MAINTAINER=	nakai@FreeBSD.org

# More than version 0.98
BUILD_DEPENDS=	nasm:${PORTSDIR}/devel/nasm

USE_GMAKE=	yes
MAKEFILE=	makefile.unx
ALL_TARGET=	gogo
.if(!defined(KANJI))
MAKE_ENV+=	DONT_USE_KANJI=-DNO_KANJI
.endif
RESTRICTED=	Condition is not clear

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gogo ${PREFIX}/bin

.include <bsd.port.mk>
