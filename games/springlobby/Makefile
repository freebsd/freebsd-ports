# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	springlobby
PORTVERSION=	0.143
PORTREVISION=	2
CATEGORIES=	games net
MASTER_SITES=	http://www.springlobby.info/tarballs/ \
		http://mirror.amdmi3.ru/distfiles/

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Cross-platform lobby client for the Spring RTS project

RUN_DEPENDS=	spring:${PORTSDIR}/games/spring
LIB_DEPENDS=	curl:${PORTSDIR}/ftp/curl

USE_BZIP2=	yes
USES=		cmake
CMAKE_ARGS=	-DwxWidgets_CONFIG_EXECUTABLE="${WX_CONFIG}" \
		-DENABLE_DEBUG_REPORT=FALSE
USE_WX=		2.8+
WX_UNICODE=	yes
MAKE_JOBS_SAFE=	yes

PORTDOCS=	*

OPTIONS_DEFINE=	TORRENT SOUND DOCS NLS
OPTIONS_DEFAULT=	TORRENT SOUND
TORRENT_DESC=	Support automatic content downloads via torrent
SOUND_DESC=	Enable sound

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
PLIST_SUB+=	NLS=""
.else
CMAKE_ARGS+=	-DOPTION_TRANSLATION_SUPPORT:BOOL=OFF
PLIST_SUB+=	NLS="@comment "
.endif

.if ${PORT_OPTIONS:MTORRENT}
LIB_DEPENDS+=	torrent-rasterbar:${PORTSDIR}/net-p2p/libtorrent-rasterbar-15
.else
CMAKE_ARGS+=	-DOPTION_TORRENT_SYSTEM:BOOL=OFF
.endif

.if ${PORT_OPTIONS:MSOUND}
USE_OPENAL=		al
.else
CMAKE_ARGS+=	-DOPTION_SOUND:BOOL=OFF
.endif

post-patch:
	@${REINPLACE_CMD} -e '/<curl\/types.h>/d' \
		${WRKSRC}/src/utils/curlhelper.h \
		${WRKSRC}/src/utils/downloader.cpp
.if ! ${PORT_OPTIONS:MDOCS}
	@${REINPLACE_CMD} -e '/install.*FILES.*share\/doc/ d' \
		${WRKSRC}/CMakeLists.txt
.endif

.include <bsd.port.mk>
