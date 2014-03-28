# Created by: Hajimu UMEMOTO <ume@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gkrellmms
PORTVERSION=	0.5.8
PORTREVISION=	9
CATEGORIES=	audio
MASTER_SITES=	http://gkrellm.luon.net/files/

MAINTAINER=	ume@FreeBSD.org
COMMENT=	GKrellM XMMS Plugin

DEPRECATED=	Abandonware, please consider using multimedia/audacious instead
EXPIRATION_DATE=	2014-04-27

LIB_DEPENDS=	libxmms.so:${PORTSDIR}/multimedia/xmms
BUILD_DEPENDS=	${LOCALBASE}/include/gkrellm/gkrellm.h:${PORTSDIR}/sysutils/gkrellm
RUN_DEPENDS=	gkrellm:${PORTSDIR}/sysutils/gkrellm

WRKSRC=		${WRKDIR}/${PORTNAME}

PLIST_FILES=	libexec/gkrellm/plugins/gkrellmms.so
USE_GNOME=	imlib
NO_STAGE=	yes

.include <bsd.port.mk>
