PORTNAME=	maim
DISTVERSIONPREFIX=	v
DISTVERSION=	5.8.0
PORTREVISION=	2
CATEGORIES=	graphics

MAINTAINER=	0mp@FreeBSD.org
COMMENT=	Screenshot utility with performance improvements over scrot
WWW=		https://github.com/naelstrof/maim

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${LOCALBASE}/include/glm/glm.hpp:math/glm
LIB_DEPENDS=	libicuuc.so:devel/icu \
		libpng.so:graphics/png \
		libslopy.so:x11/slop \
		libwebp.so:graphics/webp

USES=		cmake compiler:c++17-lang gl jpeg xorg
USE_GITHUB=	yes
GH_ACCOUNT=	naelstrof
USE_GL=		gl
USE_XORG=	ice sm x11 xcomposite xext xfixes xrandr xrender

CMAKE_ARGS=	-DSLOP_LIBRARIES=${LOCALBASE}/lib/libslopy.so

PLIST_FILES=	bin/${PORTNAME} \
		share/man/man1/${PORTNAME}.1.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 \
		${STAGEDIR}${PREFIX}/share/man/man1

.include <bsd.port.mk>
