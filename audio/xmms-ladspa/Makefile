# New ports collection Makefile for: 	xmms-ladspa
# Date created:			11 May 2002
# Whom:				Tilman Linneweh <arved@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	xmms-ladspa
PORTVERSION=	0.6
CATEGORIES=	audio
MASTER_SITES=	http://www.ecs.soton.ac.uk/~njl98r/code/ladspa/
DISTNAME=	xmms_ladspa-${PORTVERSION}

MAINTAINER=	arved@FreeBSD.org

BUILD_DEPENDS=	${LOCALBASE}/include/ladspa.h:${PORTSDIR}/audio/ladspa
LIB_DEPENDS=	xmms.3:${PORTSDIR}/audio/xmms

WRKSRC=		${WRKDIR}/xmms_ladspa
USE_X_PREFIX=	yes
USE_GNOMENG=	yes
USE_GNOME=	gtk12

do-install:
	@${INSTALL_DATA} ${WRKSRC}/ladspa.so ${PREFIX}/lib/xmms/Effect/

.include <bsd.port.mk>
