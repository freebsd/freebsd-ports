# New ports collection Makefile for:	blop
# Date created:			15 May 2002
# Whom:				Tilman Linneweh <arved@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	blop
PORTVERSION=	0.2.7
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Bandlimited oscillator plugins for LADSPA-aware audio applications

BUILD_DEPENDS=	${LOCALBASE}/include/ladspa.h:${PORTSDIR}/audio/ladspa

USE_GETOPT_LONG=	yes
USE_REINPLACE=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ARGS=	--with-ladspa-prefix="${LOCALBASE}"

post-patch:
	@${REINPLACE_CMD} 's|-pipe -Wall -O3 |\$$CFLAGS |g' ${WRKSRC}/configure
	@${FIND} ${WRKSRC} -name "Makefile.in" | ${XARGS} ${REINPLACE_CMD} -e \
		's|\$$(LIBS)|\$$(LIBS) \$$(LDFLAGS)|g ; \
		 s|-lc | |g'

pre-build:
	cd ${WRKSRC}/src; ${GMAKE} sawtooth_data.h square_data.h parabola_data.h

.include <bsd.port.mk>
