PORTNAME=	springlobby
PORTVERSION=	0.273
CATEGORIES=	games net
MASTER_SITES=	https://springlobby.springrts.com/dl/stable/

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Cross-platform lobby client for the Spring RTS project

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

IGNORE_FreeBSD_12=	not supported by spring engine
ONLY_FOR_ARCHS=		amd64
ONLY_FOR_ARCHS_REASON=	spring engine only supports amd64

RUN_DEPENDS=	spring:games/spring
LIB_DEPENDS=	libcurl.so:ftp/curl \
		libboost_thread.so:devel/boost-libs \
		libjsoncpp.so:devel/jsoncpp \
		libminizip.so:archivers/minizip \
		libpng.so:graphics/png

USES=		cmake compiler:c++17-lang pkgconfig ssl tar:bzip2
CMAKE_ARGS=	-DwxWidgets_CONFIG_EXECUTABLE="${WX_CONFIG}" \
		-DPRD_JSONCPP_INTERNAL=OFF \
		-Wno-dev
USE_WX=		3.0+

PORTDOCS=	*

OPTIONS_DEFINE=	SOUND NLS NOTIFY DOCS
OPTIONS_DEFAULT=SOUND NOTIFY
OPTIONS_SUB=	yes

SOUND_DESC=	Enable sound notifications
NOTIFY_DESC=	Enable libnotify support for popup status messages

NLS_CMAKE_BOOL=		OPTION_TRANSLATION_SUPPORT
NLS_USES=		gettext

SOUND_CMAKE_BOOL=	OPTION_SOUND
SOUND_LIB_DEPENDS=	libalure.so:audio/alure
SOUND_USES=		openal:al

NOTIFY_CMAKE_BOOL=	OPTION_NOTIFY
NOTIFY_LIB_DEPENDS=	libnotify.so:devel/libnotify
NOTIFY_USES=		gnome
NOTIFY_USE=		GNOME=glib20

# make sure bundled depends are not used
post-patch:
.for lib in minizip jsoncpp libgit2
	@${RM} -r ${WRKSRC}/src/downloader/lib/src/lib/${lib}
.endfor

.include <bsd.port.mk>
