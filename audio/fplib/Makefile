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

LIB_DEPENDS=	libcurl.so:${PORTSDIR}/ftp/curl \
		libfftw3.so:${PORTSDIR}/math/fftw3 \
		libfftw3f.so:${PORTSDIR}/math/fftw3-float \
		libmad.so:${PORTSDIR}/audio/libmad \
		libsamplerate.so:${PORTSDIR}/audio/libsamplerate \
		libtag.so:${PORTSDIR}/audio/taglib

MAKE_JOBS_UNSAFE=	yes
USE_LDCONFIG=	yes
USES=		cmake localbase tar:xz

.include <bsd.port.mk>
