# Created by: Hajimu UMEMOTO <ume@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gkrellmms
PORTVERSION=	0.5.8
PORTREVISION=	10
CATEGORIES=	audio
MASTER_SITES=	http://gkrellm.luon.net/files/

MAINTAINER=	ume@FreeBSD.org
COMMENT=	GKrellM XMMS Plugin

DEPRECATED=	GKrellM 1.X is no longer being developed, consider using 2.X.
EXPIRATION_DATE=2014-06-30

LIB_DEPENDS=	libxmms.so:${PORTSDIR}/multimedia/xmms
BUILD_DEPENDS=	${LOCALBASE}/include/gkrellm/gkrellm.h:${PORTSDIR}/sysutils/gkrellm
RUN_DEPENDS=	gkrellm:${PORTSDIR}/sysutils/gkrellm

WRKSRC=		${WRKDIR}/${PORTNAME}

PLIST_FILES=	libexec/gkrellm/plugins/gkrellmms.so
USE_GNOME=	imlib

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/libexec/gkrellm/plugins
	${INSTALL_DATA} ${WRKSRC}/gkrellmms.so \
	    ${STAGEDIR}${PREFIX}/libexec/gkrellm/plugins

.include <bsd.port.mk>
