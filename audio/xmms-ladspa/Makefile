# Created by: Tilman Linneweh <arved@FreeBSD.org>
# $FreeBSD$

PORTNAME=	xmms-ladspa
PORTVERSION=	1.1
PORTREVISION=	4
CATEGORIES=	audio
MASTER_SITES=	http://www.ecs.soton.ac.uk/~njl98r/code/ladspa/ \
		LOCAL/arved
DISTNAME=	xmms_ladspa-${PORTVERSION}

MAINTAINER=	arved@FreeBSD.org
COMMENT=	XMMS Plugin that provides LADSPA Plugins to XMMS

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${LOCALBASE}/include/ladspa.h:audio/ladspa
LIB_DEPENDS=	libxmms.so:multimedia/xmms

PLIST_FILES=	lib/xmms/Effect/ladspa.so

USE_GNOME=	gtk12

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/xmms/Effect/
	${INSTALL_DATA} ${WRKSRC}/ladspa.so ${STAGEDIR}${PREFIX}/lib/xmms/Effect/

.include <bsd.port.mk>
