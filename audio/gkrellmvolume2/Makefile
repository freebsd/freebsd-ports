# New ports collection makefile for:	gkrellmvolume
# Date Created:		Jun 22 2000
# Whom:			Hajimu UMEMOTO <ume@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gkrellmvolume
PORTVERSION=	2.1.4
CATEGORIES=	audio
MASTER_SITES=	http://gkrellm.luon.net/files/
DISTNAME=	gkrellm-volume-${PORTVERSION}

MAINTAINER=	ume@FreeBSD.org

BUILD_DEPENDS=	${X11BASE}/include/gkrellm2/gkrellm.h:${PORTSDIR}/sysutils/gkrellm2
RUN_DEPENDS=	gkrellm:${PORTSDIR}/sysutils/gkrellm2

WRKSRC=		${WRKDIR}/gkrellm-volume

USE_X_PREFIX=	yes

MAKE_ENV+=	PLUGIN_DIR=${PREFIX}/libexec/gkrellm2/plugins

.include <bsd.port.mk>
