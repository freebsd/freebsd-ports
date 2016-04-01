# Created by: trasz <trasz@pin.if.uz.zgora.pl>
# $FreeBSD$

PORTNAME=	specimen
DISTVERSION=	0.5.2-rc3
PORTREVISION=	10
CATEGORIES=	audio
MASTER_SITES=	http://zhevny.com/specimen/files/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	MIDI controllable audio sampler

# Between 0.109.0 and earlier versions there was an api change in JACK.
# However, the library version number was not changed.  The line above
# is supposed to work around that.

BUILD_DEPENDS=	jackit>=0.109.2:audio/jack
LIB_DEPENDS=	libjack.so:audio/jack \
		liblash.so:audio/lash \
		libsamplerate.so:audio/libsamplerate \
		libsndfile.so:audio/libsndfile \
		libphat.so:x11-toolkits/phat

USES=		gmake pkgconfig
USE_GNOME=	libgnomecanvas libxml2
GNU_CONFIGURE=	yes
LDFLAGS+=	-lm

DESKTOP_ENTRIES="Specimen" "" "${DATADIR}/pixmaps/specimen.png" \
		"${PORTNAME}" "" ""

post-patch:
	@${REINPLACE_CMD} -e \
		's|-Werror|| ; \
		 s|-O3|$$CFLAGS|' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e \
		's|-l\.\.|-I..|' ${WRKSRC}/src/gui/Makefile.in

.include <bsd.port.mk>
