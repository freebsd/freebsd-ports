# ports collection makefile for:   fluidsynth
# Date created:        27 Nov 2003
# Whom:                Juha Nygard <juha.nygard1@netikka.fi>
#
# $FreeBSD$
#

PORTNAME=	fluidsynth
PORTVERSION=	1.0.3
CATEGORIES=	audio
MASTER_SITES=	http://resonance.org/~josh/fluidsynth/

MAINTAINER=	juha.nygard1@netikka.fi
COMMENT=	Real-time software synthesizer based on the SoundFont 2 specifications

INSTALLS_SHLIB=	yes
USE_GMAKE=	yes
USE_GNOME=	pkgconfig
USE_GETOPT_LONG=	yes
USE_LIBTOOL=	yes
USE_REINPLACE=	yes
CONFIGURE_ENV=	CPPFLAGS="${PTHREAD_CFLAGS}" LIBS="${PTHREAD_LIBS}"

MAN1=		fluidsynth.1

post-patch:
	@${REINPLACE_CMD} -e 's|-O2||' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|[(]libdir[)]/pkgconfig|(prefix)/libdata/pkgconfig|' ${WRKSRC}/Makefile.in

.include <bsd.port.mk>
