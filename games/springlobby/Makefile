# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	springlobby
PORTVERSION=	0.180
PORTREVISION=	22
CATEGORIES=	games net
MASTER_SITES=	http://www.springlobby.info/tarballs/ \
		http://mirror.amdmi3.ru/distfiles/

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Cross-platform lobby client for the Spring RTS project

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	spring:games/spring
LIB_DEPENDS=	libcurl.so:ftp/curl \
		libboost_thread.so:devel/boost-libs

USES=		cmake compiler:c++11-lib pkgconfig tar:bzip2
CMAKE_ARGS=	-DwxWidgets_CONFIG_EXECUTABLE="${WX_CONFIG}" \
		-DENABLE_DEBUG_REPORT=FALSE
USE_WX=		2.8+

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
SOUND_LIB_DEPENDS=	libalure.so:audio/alure
SOUND_USES=		openal:al

NOTIFY_CMAKE_ON=	-DOPTION_NOTIFY=ON
NOTIFY_CMAKE_OFF=	-DOPTION_NOTIFY=OFF
NOTIFY_LIB_DEPENDS=	libnotify.so:devel/libnotify

.include <bsd.port.mk>
