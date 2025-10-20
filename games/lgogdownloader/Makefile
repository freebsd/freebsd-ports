PORTNAME=	lgogdownloader
DISTVERSION=	3.17
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	https://github.com/Sude-/${PORTNAME}/releases/download/v${DISTVERSION}/

MAINTAINER=	Alexander88207@protonmail.com
COMMENT=	Unofficial downloader for GOG.com
WWW=		https://sites.google.com/site/gogdownloader

LICENSE=	WTFPL
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libboost_date_time.so:devel/boost-libs \
		libboost_filesystem.so:devel/boost-libs \
		libboost_iostreams.so:devel/boost-libs \
		libboost_program_options.so:devel/boost-libs \
		libboost_regex.so:devel/boost-libs \
		libboost_thread.so:devel/boost-libs \
		libcurl.so:ftp/curl \
		libjsoncpp.so:devel/jsoncpp \
		librhash.so:security/rhash \
		libtidy5.so:www/tidy-html5 \
		libtinyxml2.so:textproc/tinyxml2

USES=		cmake pkgconfig

CMAKE_ARGS=	-DTIDY_LIBRARY=${LOCALBASE}/lib/libtidy5.so

PLIST_FILES=	bin/${PORTNAME} \
		share/man/man1/${PORTNAME}.1.gz

OPTIONS_DEFINE=		QT_GUI
QT_GUI_DESC=		Qt GUI Support
QT_GUI_BUILD_DEPENDS=	vulkan-headers>0:graphics/vulkan-headers
QT_GUI_USES=		gl qt:6
QT_GUI_USE=		GL=opengl QT=base,declarative,positioning,webchannel,webengine
QT_GUI_CMAKE_BOOL=	USE_QT_GUI

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
