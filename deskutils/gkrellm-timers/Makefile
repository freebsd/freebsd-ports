# New ports collection makefile for:	gkrellm-timers
# Date created:		Thu Oct 12 19:20:17 CEST 2006
# Whom:			Tobias Roth <ports@fsck.ch>
#
# $FreeBSD$
#

PORTNAME=	timers
PORTVERSION=	1.3
PORTREVISION=	3
CATEGORIES=	deskutils
MASTER_SITES=	http://triq.net/gkrellm_timers/ \
		http://depot.fsck.ch/mirror/distfiles/
PKGNAMEPREFIX=	gkrellm-
DISTNAME=	gkrellm_${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@fsck.ch
COMMENT=	GKrellM2 plugin that allows the setting of countdowns

BUILD_DEPENDS=	${LOCALBASE}/include/gkrellm2/gkrellm.h:${PORTSDIR}/sysutils/gkrellm2
RUN_DEPENDS=	gkrellm:${PORTSDIR}/sysutils/gkrellm2

USE_GNOME=	gtk20

PLIST_FILES=	libexec/gkrellm2/plugins/gkrellm_timers.so
#WRKSRC=		${WRKDIR}/gkrellm_${PORTNAME}

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/gkrellm_${PORTNAME}.so \
		${PREFIX}/libexec/gkrellm2/plugins/

.include <bsd.port.mk>
