# New ports collection makefile for:	streamtuner-local
# Date created:			18 Jul 2002
# Whom:				Jean-Yves Lefort <jylefort@brutele.be>
#
# $FreeBSD$
#

PORTNAME=		local
PORTVERSION=		0.2.1
CATEGORIES=		audio www
MASTER_SITES=		http://streamtuner.sourceforge.net/streamtuner/
PKGNAMEPREFIX=		streamtuner-
DISTNAME=		${PKGNAMEPREFIX}${PORTNAME}-${PORTVERSION}

MAINTAINER=		jylefort@brutele.be
COMMENT=		A plugin for streamtuner that browses a local MP3 repository

BUILD_DEPENDS=		${X11BASE}/include/streamtuner/streamtuner.h:${PORTSDIR}/audio/streamtuner
RUN_DEPENDS=		${X11BASE}/bin/streamtuner:${PORTSDIR}/audio/streamtuner
LIB_DEPENDS=		id3-3.8:${PORTSDIR}/audio/id3lib

USE_X_PREFIX=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS=		--with-id3lib=${LOCALBASE}

.include <bsd.port.mk>
