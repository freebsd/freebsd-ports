# New ports collection Makefile for: 	xmms-ladspa
# Date created:			11 May 2002
# Whom:				Tilman Linneweh <arved@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	xmms-ladspa
PORTVERSION=	1.0
CATEGORIES=	audio
MASTER_SITES=	http://www.ecs.soton.ac.uk/~njl98r/code/ladspa/
DISTNAME=	xmms_ladspa-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	"XMMS Plugin that provides LADSPA Plugins to XMMS"

BUILD_DEPENDS=	${LOCALBASE}/include/ladspa.h:${PORTSDIR}/audio/ladspa
LIB_DEPENDS=	xmms.4:${PORTSDIR}/multimedia/xmms
PLIST_FILES=	lib/xmms/Effect/ladspa.so

USE_X_PREFIX=	yes
USE_GNOME=	gtk12

do-install:
	@${INSTALL_DATA} ${WRKSRC}/ladspa.so ${PREFIX}/lib/xmms/Effect/

.include <bsd.port.mk>
