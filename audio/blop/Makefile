# New ports collection Makefile for:	blop
# Date created:			15 May 2002
# Whom:				Tilman Linneweh <arved@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	blop
PORTVERSION=	0.2.6
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Bandlimited oscillator plugins for LADSPA-aware audio applications

BUILD_DEPENDS=	${LOCALBASE}/include/ladspa.h:${PORTSDIR}/audio/ladspa
.if !exists(/usr/include/getopt.h)
LIB_DEPENDS=	gnugetopt:${PORTSDIR}/devel/libgnugetopt
CONFIGURE_ENV+=	LIBS="-L${LOCALBASE}/lib -lgnugetopt"
.endif

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=
CONFIGURE_ARGS+=--build=${MACHINE_ARCH}-portbld-freebsd${OSREL} \
		--with-ladspa-prefix="${LOCALBASE}"

pre-build:
	cd ${WRKSRC}/src; ${GMAKE} sawtooth_data.h square_data.h parabola_data.h

.include <bsd.port.mk>
