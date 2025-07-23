PORTNAME=	libbs2b
DISTVERSION=	3.1.0
PORTREVISION=	8
CATEGORIES=	audio
MASTER_SITES=	SF/bs2b/${PORTNAME}/${DISTVERSION}

PATCH_SITES=	https://github.com/alexmarsev/${PORTNAME}/commit/
PATCHFILES=	5ca2d59888df047f1e4b028e3a2fd5be8b5a7277.patch:-p1

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Bauer Stereophonic-to-Binaural DSP
WWW=		https://bs2b.sourceforge.net/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libsndfile.so:audio/libsndfile

USES=		gmake libtool localbase pkgconfig tar:bzip2
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes

INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
