# Created by: Tilman Linneweh <arved@FreeBSD.org>
# $FreeBSD$

PORTNAME=	xmms-ladspa
PORTVERSION=	1.1
PORTREVISION=	4
CATEGORIES=	audio
MASTER_SITES=	http://www.ecs.soton.ac.uk/~njl98r/code/ladspa/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	arved
DISTNAME=	xmms_ladspa-${PORTVERSION}

MAINTAINER=	arved@FreeBSD.org
COMMENT=	XMMS Plugin that provides LADSPA Plugins to XMMS

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

DEPRECATED=	Abandonware, please consider using multimedia/audacious instead
EXPIRATION_DATE=	2014-04-27

BUILD_DEPENDS=	${LOCALBASE}/include/ladspa.h:${PORTSDIR}/audio/ladspa
LIB_DEPENDS=	libxmms.so:${PORTSDIR}/multimedia/xmms

PLIST_FILES=	lib/xmms/Effect/ladspa.so

USE_GNOME=	gtk12

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/xmms/Effect/
	@${INSTALL_DATA} ${WRKSRC}/ladspa.so ${STAGEDIR}${PREFIX}/lib/xmms/Effect/

.include <bsd.port.mk>
