# New ports collection makefile for:	linpsk
# Date created:				29 May 2005
# Whom:					Søren Straarup <xride@x12.dk>
#
# $FreeBSD$
#

PORTNAME=	linpsk
PORTVERSION=	0.8.1
PORTREVISION=	6
CATEGORIES=	comms hamradio
MASTER_SITES=	SF

MAINTAINER=	xride@FreeBSD.org
COMMENT=	A qt psk31 client

LIB_DEPENDS=	fftw3:${PORTSDIR}/math/fftw3 \
		portaudio:${PORTSDIR}/audio/portaudio
RUN_DEPENDS=	${LOCALBASE}/lib/X11/fonts/bitstream-vera/fonts.dir:${PORTSDIR}/x11-fonts/bitstream-vera

USE_PERL5_BUILD=yes
USE_QT_VER=	3
USE_GMAKE=	yes
GNU_CONFIGURE=	yes

CPPFLAGS+=	-I${LOCALBASE}/include ${PTHREAD_CFLAGS}
LDFLAGS+=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
CONFIGURE_ARGS=	--with-qtdir=${LOCALBASE} --prefix=${PREFIX}

SUB_FILES=	pkg-message

post-patch:
	@${REINPLACE_CMD} -e 's|-lpthread||' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|/usr/X11R6|${LOCALBASE}|g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|-I$$(top_srcdir)/src/portaudio||' \
		${WRKSRC}/src/Makefile.in \
		${WRKSRC}/src/interfaces/Makefile.in
	@${REINPLACE_CMD} -e \
		's|$$(top_builddir)/src/portaudio/libportaudio\.a|-lportaudio|; \
		 /^SUBDIRS =/ s|portaudio||' \
		${WRKSRC}/src/Makefile.in
	@${REINPLACE_CMD} -e \
		's|-O2|${CXXFLAGS}|; \
		 /^install-exec-am/ s|install-libLIBRARIES||' \
		${WRKSRC}/src/interfaces/Makefile.in

post-install:
	${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${FILESDIR}/LinPSKConfig.xml ${EXAMPLESDIR}
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
