# New ports collection makefile for:   gogo no coder
# Version required:    2.11
# Date created:        01 July 1999
# Whom:                Yukihiro Nakai <Nacai@iname.com>
#
# $FreeBSD$
#

DISTNAME=	gogo211
PKGNAME=	gogo-2.11
CATEGORIES=	audio
MASTER_SITES=	http://www.kurims.kyoto-u.ac.jp/~shigeo/soft/gogo2/src/
EXTRACT_SUFX=	.tgz

MAINTAINER=	nakai@FreeBSD.org

# More than version 0.98
BUILD_DEPENDS=	nasm:${PORTSDIR}/devel/nasm

MAKEFILE=	makefile.unx
ALL_TARGET=	gogo
.if(!defined(KANJI))
MAKE_ENV+=	DONT_USE_KANJI=-DNO_KANJI
.endif
RESTRICTED=	Condition is not clear
NO_WRKSUBDIR=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gogo ${PREFIX}/bin

.include <bsd.port.mk>
