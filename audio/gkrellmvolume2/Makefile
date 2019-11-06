# Created by: Hajimu UMEMOTO <ume@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gkrellmvolume
PORTVERSION=	2.1.13
PORTREVISION=	10
CATEGORIES=	audio
MASTER_SITES=	http://gkrellm.luon.net/files/
PKGNAMESUFFIX=	2
DISTNAME=	gkrellm-volume-${PORTVERSION}

MAINTAINER=	ume@FreeBSD.org
COMMENT=	GKrellM volume plugin

BROKEN=		unfetchable

BUILD_DEPENDS=	${LOCALBASE}/include/gkrellm2/gkrellm.h:sysutils/gkrellm2
RUN_DEPENDS=	gkrellm:sysutils/gkrellm2

WRKSRC=		${WRKDIR}/gkrellm-volume

PLIST_FILES=	libexec/gkrellm2/plugins/volume.so \
		share/locale/de/LC_MESSAGES/gkrellm-volume.mo \
		share/locale/es/LC_MESSAGES/gkrellm-volume.mo \
		share/locale/fr/LC_MESSAGES/gkrellm-volume.mo \
		share/locale/nl/LC_MESSAGES/gkrellm-volume.mo \
		share/locale/pl/LC_MESSAGES/gkrellm-volume.mo \
		share/locale/ru/LC_MESSAGES/gkrellm-volume.mo

USES=		gettext gmake pkgconfig

PLUGIN_DIR=	${STAGEDIR}${PREFIX}/libexec/gkrellm2/plugins

MAKE_ENV+=	PLUGIN_DIR=${PLUGIN_DIR} \
		LOCALEDIR=${STAGEDIR}${PREFIX}/share/locale \
		enable_nls=1

pre-install:
	@${MKDIR} ${PLUGIN_DIR}

.include <bsd.port.mk>
