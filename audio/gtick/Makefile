# New ports collection makefile for: qsf
# Date created:		10 February 2004
# Whom:			liamfoy@sepulcrum.org
#
# $FreeBSD$
#

PORTNAME=	gtick
PORTVERSION=	0.3.1
PORTREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	http://www.antcom.de/gtick/download/

MAINTAINER=	liamfoy@sepulcrum.org
COMMENT=	A metronome application

LIB_DEPENDS=	sndfile.1:${PORTSDIR}/audio/libsndfile

GNU_CONFIGURE=	yes
USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_GETOPT_LONG=yes
USE_GNOME=	gtk20
USE_REINPLACE=	yes
CONFIGURE_ENV+=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

MAN1=		gtick.1

post-patch:
	@${REINPLACE_CMD} -e 's|machine/soundcard.h|sys/soundcard.h|' ${WRKSRC}/src/dsp.c
	@${REINPLACE_CMD} -e 's|-O3||' ${WRKSRC}/configure

.include <bsd.port.mk>
