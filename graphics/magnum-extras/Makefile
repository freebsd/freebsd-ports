PORTNAME=	magnum-extras
DISTVERSIONPREFIX=	v
DISTVERSION=	2020.06-519
DISTVERSIONSUFFIX=	-gef760a4
CATEGORIES=	graphics

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Magnum Graphics: Extras
WWW=		https://magnum.graphics/ \
		https://github.com/mosra/magnum-extras

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libCorradeUtility.so:devel/corrade \
		libMagnum.so:graphics/magnum

USES=		cmake compiler:c++14-lang gl sdl
USE_GL=		gl opengl
USE_SDL=	sdl2
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	mosra
GH_TUPLE=	mosra:toolchains:2243706:t/toolchains

CMAKE_ARGS=	-DLIB_SUFFIX:STRING=""

CMAKE_ON=	\
		MAGNUM_WITH_PLAYER \
		MAGNUM_WITH_UI \
		MAGNUM_WITH_UI_GALLERY

.include <bsd.port.mk>
