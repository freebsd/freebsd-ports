# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	fplib
PORTVERSION=	20121001
PORTREVISION=	3
CATEGORIES=	audio
MASTER_SITES=	LOCAL/sunpoet

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Last.fm fingerprint library

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/debian/copyright

LIB_DEPENDS=	libcurl.so:ftp/curl \
		libfftw3.so:math/fftw3 \
		libfftw3f.so:math/fftw3-float \
		libmad.so:audio/libmad \
		libsamplerate.so:audio/libsamplerate \
		libtag.so:audio/taglib

MAKE_JOBS_UNSAFE=	yes
USE_LDCONFIG=	yes
USES=		cmake localbase tar:xz

.include <bsd.port.mk>
