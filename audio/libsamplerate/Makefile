# New ports collection makefile for:	libsamplerate
# Date created:				2 February 2003
# Whom:			<dmagda+libsamplerate@ee.ryerson.ca>
#
# $FreeBSD$
#

PORTNAME=	libsamplerate
PORTVERSION=	0.1.8
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	http://www.mega-nerd.com/SRC/

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	Secret Rabbit Code: a Sample Rate Converter for audio

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS+=	sndfile.1:${PORTSDIR}/audio/libsndfile \
		fftw3.5:${PORTSDIR}/math/fftw3

USE_GNOME=	gnomehack pkgconfig
USE_AUTOTOOLS=	libtool
USE_LDCONFIG=	yes
MAKE_ARGS=	htmldocdir=${PREFIX}/share/doc/libsamplerate

pre-install:
.if defined(NOPORTDOCS)
	@${REINPLACE_CMD} -e 's/SUBDIRS = M4 src doc examples tests/SUBDIRS = M4 src examples tests/' ${WRKSRC}/Makefile
.endif

.include <bsd.port.mk>
