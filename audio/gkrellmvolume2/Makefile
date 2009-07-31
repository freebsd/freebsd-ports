# New ports collection makefile for:	gkrellmvolume
# Date Created:		Jun 22 2000
# Whom:			Hajimu UMEMOTO <ume@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gkrellmvolume
PORTVERSION=	2.1.13
PORTREVISION=	6
CATEGORIES=	audio
MASTER_SITES=	http://gkrellm.luon.net/files/
DISTNAME=	gkrellm-volume-${PORTVERSION}

MAINTAINER=	ume@FreeBSD.org
COMMENT=	GKrellM volume plugin

BUILD_DEPENDS=	${LOCALBASE}/include/gkrellm2/gkrellm.h:${PORTSDIR}/sysutils/gkrellm2
RUN_DEPENDS=	gkrellm:${PORTSDIR}/sysutils/gkrellm2

LATEST_LINK=	gkrellmvolume2
WRKSRC=		${WRKDIR}/gkrellm-volume

PLIST_FILES=	libexec/gkrellm2/plugins/volume.so \
		share/locale/de/LC_MESSAGES/gkrellm-volume.mo \
		share/locale/es/LC_MESSAGES/gkrellm-volume.mo \
		share/locale/fr/LC_MESSAGES/gkrellm-volume.mo \
		share/locale/nl/LC_MESSAGES/gkrellm-volume.mo \
		share/locale/pl/LC_MESSAGES/gkrellm-volume.mo \
		share/locale/ru/LC_MESSAGES/gkrellm-volume.mo

USE_GMAKE=	yes

MAKE_ENV+=	PLUGIN_DIR=${PREFIX}/libexec/gkrellm2/plugins \
		LOCALEDIR=${PREFIX}/share/locale \
		enable_nls=1

.include <bsd.port.mk>
