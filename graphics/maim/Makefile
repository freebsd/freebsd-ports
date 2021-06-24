PORTNAME=	maim
DISTVERSIONPREFIX=	v
DISTVERSION=	5.7.4
CATEGORIES=	graphics

MAINTAINER=	0mp@FreeBSD.org
COMMENT=	Screenshot utility with performance improvements over scrot

LICENSE=	GPLv3

BUILD_DEPENDS=	${LOCALBASE}/include/glm/glm.hpp:math/glm
LIB_DEPENDS=	libicuuc.so:devel/icu \
		libImlib2.so:graphics/imlib2 \
		libpng.so:graphics/png \
		libslopy.so.7.5:x11/slop

USES=		cmake compiler:c++11-lang gl jpeg xorg
USE_GITHUB=	yes
GH_ACCOUNT=	naelstrof
USE_GL=		gl glut
USE_XORG=	ice sm x11 xcomposite xext xfixes xrandr xrender

CMAKE_ARGS=	-DSLOP_LIBRARIES=${LOCALBASE}/lib/libslopy.so

PLIST_FILES=	bin/${PORTNAME} \
		share/man/man1/${PORTNAME}.1.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 \
		${STAGEDIR}${MAN1PREFIX}/share/man/man1

.include <bsd.port.mk>
