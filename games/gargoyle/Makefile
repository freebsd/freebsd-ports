PORTNAME=	gargoyle
DISTVERSION=	2023.1
CATEGORIES=	games
DISTNAME=	${GH_PROJECT}-${DISTVERSION}

MAINTAINER=	tobias.rehbein@web.de
COMMENT=	Interactive fiction player supporting all major formats
WWW=		https://ccxvii.net/gargoyle/

LICENSE=	ART10 BSD2CLAUSE BSD3CLAUSE BSD4CLAUSE GPLv2 GPLv3 MIT OFL11
LICENSE_COMB=	multi
LICENSE_FILE=	${WRKSRC}/License.txt

BUILD_DEPENDS=	libxkbcommon>=0.5.0:x11/libxkbcommon \
		vulkan-headers>0:graphics/vulkan-headers
LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libpng.so:graphics/png
RUN_DEPENDS=	libxkbcommon>=0.5.0:x11/libxkbcommon

USES=		cmake desktop-file-utils gl jpeg pkgconfig qt:6 sdl \
		shared-mime-info
USE_GITHUB=	yes
GH_ACCOUNT=	garglk
GH_PROJECT=	${GH_ACCOUNT}
USE_GL=		opengl
USE_QT=		base
USE_SDL=	mixer2

CMAKE_ON=	WITH_QT6

OPTIONS_DEFINE=		SPEECHD
SPEECHD_DESC=		Enable text-to-speech support
SPEECHD_LIB_DEPENDS=	libspeechd.so:accessibility/speech-dispatcher
SPEECHD_USES=		gettext-runtime gnome
SPEECHD_USE=		gnome=glib20
SPEECHD_CMAKE_BOOL=	WITH_TTS

.include <bsd.port.mk>
