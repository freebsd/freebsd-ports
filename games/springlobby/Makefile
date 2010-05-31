# New ports collection makefile for:	springlobby
# Date created:		02 Sep 2009
# Whom:			Dmitry Marakasov <amdmi3@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	springlobby
PORTVERSION=	0.80
PORTREVISION=	1
CATEGORIES=	games net
MASTER_SITES=	http://www.springlobby.info/tarballs/ \
		http://mirror.amdmi3.ru/distfiles/

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Cross-platform lobby client for the Spring RTS project

RUN_DEPENDS=	spring:${PORTSDIR}/games/spring
LIB_DEPENDS=	curl.6:${PORTSDIR}/ftp/curl

USE_BZIP2=	yes
USE_CMAKE=	yes
CMAKE_ARGS=	-DwxWidgets_CONFIG_EXECUTABLE="${WX_CONFIG}" \
		-DENABLE_DEBUG_REPORT=FALSE
USE_WX=		2.8+
MAKE_JOBS_SAFE=	yes

PORTDOCS=	*

OPTIONS=	TORRENT	"Support automatic content downloads via torrent" on \
		SOUND	"Enable sound" on

.include <bsd.port.options.mk>

.if !defined(WITHOUT_NLS)
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.else
CMAKE_ARGS+=	-DOPTION_TRANSLATION_SUPPORT:BOOL=OFF
PLIST_SUB+=	NLS="@comment "
.endif

.if !defined(WITHOUT_TORRENT)
LIB_DEPENDS+=	torrent-rasterbar.5:${PORTSDIR}/net-p2p/libtorrent-rasterbar-14
.else
CMAKE_ARGS+=	-DOPTION_TORRENT_SYSTEM:BOOL=OFF
.endif

.if !defined(WITHOUT_SOUND)
USE_OPENAL=		al
.else
CMAKE_ARGS+=	-DOPTION_SOUND:BOOL=OFF
.endif

post-patch:
.if defined(NOPORTDOCS)
	@${REINPLACE_CMD} -e '/install.*FILES.*share\/doc/ d' \
		${WRKSRC}/CMakeLists.txt
.endif

.include <bsd.port.mk>
