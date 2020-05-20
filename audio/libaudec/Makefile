# $FreeBSD$

PORTNAME=	libaudec
DISTVERSIONPREFIX=	v
DISTVERSION=	0.2.2
CATEGORIES=	audio devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Wrapper library over ffmpeg, sndfile and libsamplerate

LICENSE=	AGPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libsamplerate.so:audio/libsamplerate \
		libsndfile.so:audio/libsndfile

USES=		compiler:c11 meson pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	alex-tee
USE_LDCONFIG=	yes

MESON_ARGS=	-Dbuild-tests=false

PLIST_FILES=	bin/audec \
		include/audec/audec.h \
		lib/libaudec.so \
		libdata/pkgconfig/audec.pc

.include <bsd.port.mk>
