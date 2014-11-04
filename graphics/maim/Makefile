# $FreeBSD$

PORTNAME=	maim
PORTVERSION=	2.3.31
CATEGORIES=	graphics

MAINTAINER=	neel@neelc.org
COMMENT=	Screenshot utility with performance improvements  over scrot

LICENSE=	GPLv3

USE_GITHUB=	yes
GH_ACCOUNT=	naelstrof
GH_PROJECT=	maim
GH_TAGNAME=	v${PORTVERSION}
GH_COMMIT=	6888fa9

USES=		cmake
USE_GCC=	yes
USE_EFL=	imlib2
USE_XORG=	x11 xrandr xfixes
PLIST_FILES=	bin/${PORTNAME}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/maim ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
