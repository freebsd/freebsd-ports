# New ports collection makefile for:	gkrellmms
# Date Created:		Jun 22 2000
# Whom:			Hajimu UMEMOTO <ume@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gkrellmms
PORTVERSION=	2.0
CATEGORIES=	audio
MASTER_SITES=	http://gkrellm.luon.net/files/

MAINTAINER=	ume@FreeBSD.org

LIB_DEPENDS=	xmms.3:${PORTSDIR}/audio/xmms
BUILD_DEPENDS=	${X11BASE}/include/gkrellm2/gkrellm.h:${PORTSDIR}/sysutils/gkrellm2
RUN_DEPENDS=	gkrellm:${PORTSDIR}/sysutils/gkrellm2

WRKSRC=		${WRKDIR}/gkrellmms2-${PORTVERSION}

USE_X_PREFIX=	yes

MAKE_ENV+=	PLUGIN_DIR=${PREFIX}/libexec/gkrellm2/plugins

.include <bsd.port.mk>
