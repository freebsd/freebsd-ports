# New ports collection Makefile for: 	jackit
# Date created:			14 May 2002
# Whom:				arved
#
# $FreeBSD$

PORTNAME=		jackit
PORTVERSION=		0.94.0
PORTREVISION=		4
CATEGORIES=		audio
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	jackit
DISTNAME=		jack-audio-connection-kit-${PORTVERSION}

MAINTAINER=		arved@FreeBSD.org
COMMENT=		JACK is a low-latency audio server

LIB_DEPENDS=		portaudio.0:${PORTSDIR}/audio/portaudio \
			sndfile.1:${PORTSDIR}/audio/libsndfile

CONFIGURE_ENV=		LIBS="${PTHREAD_LIBS}" LDFLAGS="-L${LOCALBASE}/lib" \
			CPPFLAGS="-I${LOCALBASE}/include" CFLAGS="${CFLAGS} ${PTHREAD_CFLAGS}"
GNU_CONFIGURE=		yes
USE_GETOPT_LONG=	yes
USE_REINPLACE=		yes
INSTALLS_SHLIB=		yes
USE_GNOME=		pkgconfig gnometarget gnomehack
ONLY_FOR_ARCHS=		i386 amd64

MAN1=	jackd.1 jackstart.1

.include <bsd.port.pre.mk>

.if (${OSVERSION} > 500000) && (${OSVERSION} < 502102)
BROKEN=		"Does not compile"
.endif

post-patch:
	${REINPLACE_CMD} -e "s,-lpthread,${PTHREAD_LIBS},"  \
		${WRKSRC}/configure ${WRKSRC}/libjack/Makefile.in \
		${WRKSRC}/jackd/Makefile.in \
		${WRKSRC}/example-clients/Makefile.in ${WRKSRC}/jack.pc.in
	${REINPLACE_CMD} -e "s,-lrt,," ${WRKSRC}/libjack/Makefile.in \
		${WRKSRC}/jackd/Makefile.in \
		${WRKSRC}/example-clients/Makefile.in
	${REINPLACE_CMD} -e "s,-ldl,," ${WRKSRC}/jackd/Makefile.in \
		${WRKSRC}/example-clients/Makefile.in
	${CP} ${FILESDIR}/Makefile.in ${WRKSRC}/drivers/oss

.include <bsd.port.post.mk>
