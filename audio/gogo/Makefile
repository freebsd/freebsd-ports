# New ports collection makefile for:   gogo no coder
# Version required:    2.24c
# Date created:        01 July 1999
# Whom:                Yukihiro Nakai <Nacai@iname.com>
#
# $FreeBSD$
#

DISTNAME=	gogo224c
PKGNAME=	gogo-2.24c
CATEGORIES=	audio
MASTER_SITES=	http://homepage1.nifty.com/herumi/soft/gogo2/src/
EXTRACT_SUFX=	.tgz

MAINTAINER=	nakai@FreeBSD.org

# More than version 0.98
BUILD_DEPENDS=	nasm-0.98:${PORTSDIR}/devel/nasm

USE_GMAKE=	yes
ALL_TARGET=	gogo
.if(!defined(KANJI))
MAKE_ENV+=	DONT_USE_KANJI=-DNO_KANJI
.endif
RESTRICTED=	Condition is not clear

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gogo ${PREFIX}/bin

.include <bsd.port.mk>
