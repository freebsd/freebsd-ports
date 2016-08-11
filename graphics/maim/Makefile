# $FreeBSD$

PORTNAME=	maim
PORTVERSION=	3.4.47
DISTVERSIONPREFIX=	v
CATEGORIES=	graphics

MAINTAINER=	neel@neelc.org
COMMENT=	Screenshot utility with performance improvements over scrot

LICENSE=	GPLv3

BROKEN_powerpc64=	Does not build

LIB_DEPENDS=	libImlib2.so:graphics/imlib2

USE_GITHUB=	yes
GH_ACCOUNT=	naelstrof

USES=		cmake
USE_XORG=	x11 xrandr xfixes
PLIST_FILES=	bin/${PORTNAME} man/man1/${PORTNAME}.1.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/man-src/${PORTNAME}.1.gz ${STAGEDIR}${MAN1PREFIX}/man/man1

.include <bsd.port.mk>
