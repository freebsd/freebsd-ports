# New ports collection makefile for:	gkrellmms
# Date Created:		Jun 22 2000
# Whom:			Hajimu UMEMOTO <ume@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gkrellmms
PORTVERSION= 	0.5.4
CATEGORIES=	audio
MASTER_SITES=	http://gkrellm.luon.net/files/

MAINTAINER=	ume@FreeBSD.org

LIB_DEPENDS=	xmms.1:${PORTSDIR}/audio/xmms \
		gtk12.2:${PORTSDIR}/x11-toolkits/gtk12 \
		gdk_imlib.5:${PORTSDIR}/graphics/imlib
BUILD_DEPENDS=	${X11BASE}/include/gkrellm/gkrellm.h:${PORTSDIR}/sysutils/gkrellm
RUN_DEPENDS=	gkrellm:${PORTSDIR}/sysutils/gkrellm

USE_X_PREFIX=	yes
GTK_CONFIG?=	${X11BASE}/bin/gtk12-config
MAKE_ENV=	GTK_CONFIG="${GTK_CONFIG}"

WRKSRC=		${WRKDIR}/${PORTNAME}

.include <bsd.port.mk>
