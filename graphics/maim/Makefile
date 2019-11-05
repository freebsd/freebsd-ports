# $FreeBSD$

PORTNAME=	maim
PORTVERSION=	5.5.3
DISTVERSIONPREFIX=	v
PORTREVISION=	2
CATEGORIES=	graphics

MAINTAINER=	neel@neelc.org
COMMENT=	Screenshot utility with performance improvements over scrot

LICENSE=	GPLv3

BUILD_DEPENDS=	${LOCALBASE}/include/glm/glm.hpp:math/glm
LIB_DEPENDS=	libImlib2.so:graphics/imlib2 \
		libicuuc.so:devel/icu \
		libpng.so:graphics/png \
		libslopy.so:x11/slop

USES=		cmake compiler:c++11-lang gl jpeg xorg
USE_GITHUB=	yes
GH_ACCOUNT=	naelstrof
USE_GL=		gl glut
USE_XORG=	ice sm x11 xcomposite xext xfixes xrandr xrender

PLIST_FILES=	bin/${PORTNAME} man/man1/${PORTNAME}.1.gz

CMAKE_ARGS=	-DSLOP_LIBRARIES=${LOCALBASE}/lib/libslopy.so

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${STAGEDIR}${MAN1PREFIX}/man/man1

.include <bsd.port.mk>
