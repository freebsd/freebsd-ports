PORTNAME=	libaudec
DISTVERSIONPREFIX=	v
DISTVERSION=	0.3.4
CATEGORIES=	audio devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Wrapper library over ffmpeg, sndfile and libsamplerate

LICENSE=	AGPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libsamplerate.so:audio/libsamplerate \
		libsndfile.so:audio/libsndfile

USES=		compiler:c11 meson pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	zrythm
USE_LDCONFIG=	yes

MESON_ARGS=	-Dtests=false

PLIST_FILES=	bin/audec \
		include/audec/audec.h \
		lib/libaudec.a \
		lib/libaudec.so \
		libdata/pkgconfig/audec.pc

.include <bsd.port.mk>
