# New ports collection makefile for:	streamtuner-python
# Date created:			03 Mar 2002
# Whom:				Jean-Yves Lefort <jylefort@brutele.be>
#
# $FreeBSD$
#

PORTNAME=		streamtuner-python
PORTVERSION=		0.0.3
CATEGORIES=		audio www
MASTER_SITES=		${MASTER_SITE_SAVANNAH}
MASTER_SITE_SUBDIR=	streamtuner

MAINTAINER=		jylefort@brutele.be
COMMENT=		A streamtuner plugin providing a Python interpreter

BUILD_DEPENDS=		${X11BASE}/include/streamtuner/streamtuner.h:${PORTSDIR}/audio/streamtuner
RUN_DEPENDS=		${X11BASE}/bin/streamtuner:${PORTSDIR}/audio/streamtuner

USE_X_PREFIX=		yes
USE_LIBTOOL_VER=	15
USE_PYTHON=		yes

CONFIGURE_ENV=		CPPFLAGS="-I${LOCALBASE}/include" \
			LDFLAGS="-L${LOCALBASE}/lib"

.include <bsd.port.mk>
