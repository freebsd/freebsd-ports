# New ports collection makefile for:	streamtuner-local
# Date created:			18 Jul 2002
# Whom:				Jean-Yves Lefort <jylefort@brutele.be>
#
# $FreeBSD$
#

PORTNAME=		streamtuner-local
PORTVERSION=		0.3.0
CATEGORIES=		audio www
MASTER_SITES=		http://streamtuner.sourceforge.net/streamtuner/

MAINTAINER=		jylefort@brutele.be
COMMENT=		A streamtuner plugin for local music access

BUILD_DEPENDS=		${X11BASE}/include/streamtuner/streamtuner.h:${PORTSDIR}/audio/streamtuner
RUN_DEPENDS=		${X11BASE}/bin/streamtuner:${PORTSDIR}/audio/streamtuner
LIB_DEPENDS=		id3tag:${PORTSDIR}/audio/libid3tag \
			vorbis:${PORTSDIR}/audio/libvorbis

USE_X_PREFIX=		yes
USE_LIBTOOL_VER=	15

CONFIGURE_ENV=		CPPFLAGS="-I${LOCALBASE}/include" \
			LDFLAGS="-L${LOCALBASE}/lib"

.include <bsd.port.mk>
