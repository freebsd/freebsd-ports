# New ports collection makefile for:	streamtuner-xiph
# Date created:			31 Jan 2004
# Whom:				Jean-Yves Lefort <jylefort@brutele.be>
#
# $FreeBSD$
#

PORTNAME=		streamtuner-xiph
PORTVERSION=		0.0.1
PORTREVISION=	1
CATEGORIES=		audio www
MASTER_SITES=		${MASTER_SITE_SAVANNAH}
MASTER_SITE_SUBDIR=	streamtuner

MAINTAINER=		jylefort@brutele.be
COMMENT=		A dir.xiph.org plugin for streamtuner

BUILD_DEPENDS=		${X11BASE}/include/streamtuner/streamtuner.h:${PORTSDIR}/audio/streamtuner
RUN_DEPENDS=		${X11BASE}/bin/streamtuner:${PORTSDIR}/audio/streamtuner

USE_X_PREFIX=		yes
USE_LIBTOOL_VER=	15

CONFIGURE_ENV=		CPPFLAGS="-I${LOCALBASE}/include" \
			LDFLAGS="-L${LOCALBASE}/lib"

.include <bsd.port.mk>
