# New ports collection Makefile for: 	jackit
# Date created:			14 May 2002
# Whom:				arved
#
# $FreeBSD$

PORTNAME=		jackit
PORTVERSION=		0.99.0
CATEGORIES=		audio
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	jackit
DISTNAME=		jack-audio-connection-kit-${PORTVERSION}

MAINTAINER=		ports@FreeBSD.org
COMMENT=		A low-latency audio server

LIB_DEPENDS=		portaudio.0:${PORTSDIR}/audio/portaudio \
			sndfile.1:${PORTSDIR}/audio/libsndfile

OPTIONS=		DOCS "Build HTML documentation. Requires doxygen/TeX." off

LATEST_LINK=		jack
CONFIGURE_ENV=		LIBS="${PTHREAD_LIBS}" LDFLAGS="-L${LOCALBASE}/lib" \
			CPPFLAGS="-I${LOCALBASE}/include" \
			CFLAGS="${CFLAGS} ${PTHREAD_CFLAGS}"
USE_LIBTOOL_VER=	15
USE_GETOPT_LONG=	yes
USE_REINPLACE=		yes
INSTALLS_SHLIB=		yes
USE_GNOME=		pkgconfig gnometarget gnomehack
ONLY_FOR_ARCHS=		i386 amd64

MAN1=	jackd.1 jackstart.1

.include <bsd.port.pre.mk>

.if exists(${LOCALBASE}/bin/doxygen)
.	if !defined(WITH_GNOKII)
DOCS_OVERRIDE=	yes
WITH_DOCS=	yes
.	endif
.endif

.if defined(WITH_DOCS) || defined(PACKAGE_BUILDING)
BUILD_DEPENDS+=		doxygen:${PORTSDIR}/devel/doxygen
PLIST_SUB+=		DOCS=""
.elseif defined(WITHOUT_DOCS)
CONFIGURE_ENV+=		ac_cv_prog_HAVE_DOXYGEN="false"
PLIST_SUB+=		DOCS="@comment "
.endif

.if (${OSVERSION} > 500000 ) && (${OSVERSION} < 502102 )
BROKEN=		"Does not compile"
.endif

pre-everything::
.if defined(DOCS_OVERRIDE)
	@${ECHO_MSG}
	@${ECHO_MSG} "**********************************************************"
	@${ECHO_MSG} "* Doxygen has been detected, documentation will be built *"
	@${ECHO_MSG} "**********************************************************"
	@${ECHO_MSG}
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

.include <bsd.port.post.mk>
