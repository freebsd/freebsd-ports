# New ports collection makefile for:	gkrellmms
# Date Created:		Jun 22 2000
# Whom:			Hajimu UMEMOTO <ume@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gkrellmms
PORTVERSION=	2.1.13
PORTREVISION=	1
#PORTREVISION=	0
CATEGORIES=	audio
MASTER_SITES=	http://gkrellm.luon.net/files/

MAINTAINER=	ume@FreeBSD.org
COMMENT=	GKrellM XMMS Plugin

LIB_DEPENDS=	xmms.4:${PORTSDIR}/multimedia/xmms
BUILD_DEPENDS=	${X11BASE}/include/gkrellm2/gkrellm.h:${PORTSDIR}/sysutils/gkrellm2
RUN_DEPENDS=	gkrellm:${PORTSDIR}/sysutils/gkrellm2

LATEST_LINK=	gkrellmms2
WRKSRC=		${WRKDIR}/gkrellmms

USE_X_PREFIX=	yes
USE_GMAKE=	yes

MAKE_ENV+=	PLUGIN_DIR=${PREFIX}/libexec/gkrellm2/plugins \
		LOCALEDIR=${PREFIX}/share/locale \
		enable_nls=1

.include <bsd.port.mk>
