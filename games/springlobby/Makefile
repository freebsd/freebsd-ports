# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	springlobby
PORTVERSION=	0.180
PORTREVISION=	3
CATEGORIES=	games net
MASTER_SITES=	http://www.springlobby.info/tarballs/ \
		http://mirror.amdmi3.ru/distfiles/

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Cross-platform lobby client for the Spring RTS project

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	spring:${PORTSDIR}/games/spring
LIB_DEPENDS=	libcurl.so:${PORTSDIR}/ftp/curl \
		libboost_thread.so:${PORTSDIR}/devel/boost-libs

USES=		cmake pkgconfig compiler:c++11-lib tar:bzip2
CMAKE_ARGS=	-DwxWidgets_CONFIG_EXECUTABLE="${WX_CONFIG}" \
		-DENABLE_DEBUG_REPORT=FALSE
USE_WX=		2.8+
WX_UNICODE=	yes

PORTDOCS=	*

OPTIONS_DEFINE=	SOUND NLS NOTIFY DOCS
OPTIONS_DEFAULT=SOUND NOTIFY
OPTIONS_SUB=	yes

SOUND_DESC=	Enable sound notifications
NOTIFY_DESC=	Enable libnotify support for popup status messages

NLS_CMAKE_ON=		-DOPTION_TRANSLATION_SUPPORT:BOOL=ON
NLS_CMAKE_OFF=		-DOPTION_TRANSLATION_SUPPORT:BOOL=OFF
NLS_USES=		gettext

SOUND_CMAKE_ON=		-DOPTION_SOUND:BOOL=ON
SOUND_CMAKE_OFF=	-DOPTION_SOUND:BOOL=OFF
SOUND_LIB_DEPENDS=	libalure.so:${PORTSDIR}/audio/alure
SOUND_USES=		openal:al

NOTIFY_CMAKE_ON=	-DOPTION_NOTIFY=ON
NOTIFY_CMAKE_OFF=	-DOPTION_NOTIFY=OFF
NOTIFY_LIB_DEPENDS=	libnotify.so:${PORTSDIR}/devel/libnotify

.include <bsd.port.options.mk>

.if ${OSVERSION} < 901000
IGNORE=		does not build (no strtoll(3) support)
.endif

.include <bsd.port.mk>
