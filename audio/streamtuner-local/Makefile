# New ports collection makefile for:	streamtuner-local
# Date created:			18 Jul 2002
# Whom:				Jean-Yves Lefort <jylefort@brutele.be>
#
# $FreeBSD$
#

PORTNAME=		local
PORTVERSION=		0.2.0
CATEGORIES=		audio www
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	streamtuner
PKGNAMEPREFIX=		streamtuner-
DISTNAME=		${PKGNAMEPREFIX}${PORTNAME}-${PORTVERSION}

MAINTAINER=		jylefort@brutele.be

BUILD_DEPENDS=		${X11BASE}/include/streamtuner/streamtuner.h:${PORTSDIR}/audio/streamtuner
RUN_DEPENDS=		${X11BASE}/bin/streamtuner:${PORTSDIR}/audio/streamtuner
LIB_DEPENDS=		id3-3.8:${PORTSDIR}/audio/id3lib

USE_X_PREFIX=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS=		--with-id3lib=${LOCALBASE}

.include <bsd.port.mk>
