# New ports collection Makefile for:	blop
# Date created:			15 May 2002
# Whom:				Tilman Linneweh <arved@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	blop
PORTVERSION=	0.2.5
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	arved@FreeBSD.org

BUILD_DEPENDS=	${LOCALBASE}/include/ladspa.h:${PORTSDIR}/audio/ladspa
LIB_DEPENDS=	gnugetopt:${PORTSDIR}/devel/libgnugetopt

USE_GMAKE=	yes
USE_AUTOMAKE=	yes
USE_AUTOCONF=	yes
CONFIGURE_ENV=	LIBS="-L${LOCALBASE}/lib"
MAKE_ENV=	LIBS="-L${LOCALBASE}/lib"
CONFIGURE_TARGET=
CONFIGURE_ARGS+=--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
AUTOMAKE_ARGS=	--add-missing

pre-build:
	cd ${WRKSRC}/src; ${GMAKE} sawtooth_data.h square_data.h parabola_data.h

.include <bsd.port.mk>
