# New ports collection makefile for:	streamtuner-python
# Date created:			03 Mar 2002
# Whom:				Jean-Yves Lefort <jylefort@brutele.be>
#
# $FreeBSD$
#

PORTNAME=		python
PORTVERSION=		0.0.2
CATEGORIES=		audio www
MASTER_SITES=		http://streamtuner.sourceforge.net/streamtuner/
PKGNAMEPREFIX=		streamtuner-
DISTNAME=		${PKGNAMEPREFIX}${PORTNAME}-${PORTVERSION}

MAINTAINER=		jylefort@brutele.be
COMMENT=		A streamtuner plugin providing a Python interpreter

BUILD_DEPENDS=		${X11BASE}/include/streamtuner/streamtuner.h:${PORTSDIR}/audio/streamtuner
RUN_DEPENDS=		${X11BASE}/bin/streamtuner:${PORTSDIR}/audio/streamtuner

USE_X_PREFIX=		yes
GNU_CONFIGURE=		yes
USE_PYTHON=		yes
USE_LIBTOOL=		yes
#INSTALLS_SHLIB=	not needed, the libs are plugins for streamtuner only

.include <bsd.port.mk>
