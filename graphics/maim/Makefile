# $FreeBSD$

PORTNAME=	maim
PORTVERSION=	3.3.39
CATEGORIES=	graphics

MAINTAINER=	neel@neelc.org
COMMENT=	Screenshot utility with performance improvements over scrot

LICENSE=	GPLv3

USE_GITHUB=	yes
GH_ACCOUNT=	naelstrof
GH_PROJECT=	maim
GH_TAGNAME=	v${PORTVERSION}
GH_COMMIT=	17c3b27

USES=		cmake
USE_EFL=	imlib2
USE_XORG=	x11 xrandr xfixes
PLIST_FILES=	bin/${PORTNAME}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/maim ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
