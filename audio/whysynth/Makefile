# Created by: trasz <trasz@pin.if.uz.zgora.pl>

PORTNAME=	whysynth
PORTVERSION=	20120903
PORTREVISION=	4
CATEGORIES=	audio
MASTER_SITES=	http://smbolton.com/whysynth/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Versatile softsynth implemented as a DSSI plugin

LICENSE=	GPLv2 LGPL21
LICENSE_COMB=	multi

BUILD_DEPENDS=	${LOCALBASE}/include/dssi.h:audio/dssi \
		${LOCALBASE}/include/ladspa.h:audio/ladspa
LIB_DEPENDS=	libdssialsacompat.so:audio/libdssialsacompat \
		liblo.so:audio/liblo \
		libjack.so:audio/jack \
		libfftw3.so:math/fftw3 \
		libfftw3f.so:math/fftw3-float

USES=		gmake gnome libtool pkgconfig tar:bzip2
GNU_CONFIGURE=	yes
USE_GNOME=	gtk20

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

post-patch:
	@${REINPLACE_CMD} -e 's|-finline-limit=5000||g' ${WRKSRC}/configure

.include <bsd.port.mk>
