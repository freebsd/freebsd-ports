# New ports collection makefile for:	libsamplerate
# Date created:				2 February 2003
# Whom:			<dmagda+libsamplerate@ee.ryerson.ca>
#
# $FreeBSD$
#

PORTNAME=	libsamplerate
PORTVERSION=	0.1.2
CATEGORIES=	audio
MASTER_SITES=	http://www.mega-nerd.com/SRC/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Secret Rabbit Code: a Sample Rate Converter for audio

LIB_DEPENDS=	sndfile.1:${PORTSDIR}/audio/libsndfile \
		fftw3.3:${PORTSDIR}/math/fftw3

USE_GNOME=	gnomehack gnometarget pkgconfig
USE_LIBTOOL_VER=	15
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--disable-gcc-pipe
INSTALLS_SHLIB=	yes

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/*.css ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/*.html ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/*.png ${DOCSDIR}
.endif

.include <bsd.port.mk>
