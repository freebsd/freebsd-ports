# New ports collection makefile for:	gkrellmvolume
# Date Created:		Jun 22 2000
# Whom:			Hajimu UMEMOTO <ume@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gkrellmvolume
PORTVERSION=	0.8
PORTREVISION=	5
CATEGORIES=	audio
MASTER_SITES=	http://gkrellm.luon.net/files/
DISTNAME=	volume-${PORTVERSION}

MAINTAINER=	ume@FreeBSD.org
COMMENT=	GKrellM volume plugin

BUILD_DEPENDS=	${LOCALBASE}/include/gkrellm/gkrellm.h:${PORTSDIR}/sysutils/gkrellm
RUN_DEPENDS=	gkrellm:${PORTSDIR}/sysutils/gkrellm

WRKSRC=		${WRKDIR}/volume

PLIST_FILES=	libexec/gkrellm/plugins/volume.so
USE_GNOME=	imlib

.include <bsd.port.mk>
