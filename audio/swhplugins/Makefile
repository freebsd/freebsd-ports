# New ports collection Makefile for: 	swhplugins
# Date created:			12 May 2002
# Whom:				Tilman Linneweh <arved@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=		swhplugins
PORTVERSION=		0.3.0
CATEGORIES=		audio
MASTER_SITES=		http://plugin.org.uk/releases/${PORTVERSION}/
DISTNAME=		swh-plugins-${PORTVERSION}

MAINTAINER=		arved@FreeBSD.org

BUILD_DEPENDS=		${LOCALBASE}/include/ladspa.h:${PORTSDIR}/audio/ladspa
LIB_DEPENDS=		fftw.2:${PORTSDIR}/math/fftw

USE_AUTOMAKE_VER=	14
AUTOMAKE_ARGS=		--add-missing --foreign
INSTALLS_SHLIB=		yes
USE_REINPLACE=		yes
USE_GMAKE=		yes
CONFIGURE_TARGET=
CONFIGURE_ARGS+=--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

pre-extract:
	@${ECHO_CMD} "NOTE: This port does not build all \
			Plugins, due to missing lrintf() function on FreeBSD"

.include <bsd.port.mk>
