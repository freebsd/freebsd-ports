# New ports collection makefile for:	streamtuner-live365
# Date created:			18 Jul 2002
# Whom:				Jean-Yves Lefort <jylefort@brutele.be>
#
# $FreeBSD$
#

PORTNAME=		live365
PORTVERSION=		0.3.2
CATEGORIES=		audio www
MASTER_SITES=		${MASTER_SITE_SAVANNAH}
MASTER_SITE_SUBDIR=	streamtuner/${PKGNAMEPREFIX}${PORTNAME}.pkg/${PORTVERSION}
PKGNAMEPREFIX=		streamtuner-
DISTNAME=		${PKGNAMEPREFIX}${PORTNAME}-${PORTVERSION}

MAINTAINER=		jylefort@brutele.be
COMMENT=		A Live365 plugin for streamtuner

BUILD_DEPENDS=		${X11BASE}/include/streamtuner/streamtuner.h:${PORTSDIR}/audio/streamtuner
RUN_DEPENDS=		${X11BASE}/bin/streamtuner:${PORTSDIR}/audio/streamtuner

USE_X_PREFIX=		yes
GNU_CONFIGURE=		yes

.include <bsd.port.mk>
