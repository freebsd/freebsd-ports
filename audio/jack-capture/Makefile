PORTNAME=	jack-capture
DISTVERSION=	0.9.73-38
DISTVERSIONSUFFIX=	-g10cec47
PORTREVISION=	2
CATEGORIES=	audio

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Program for recording soundfiles with Jack
WWW=		https://github.com/kmatheussen/jack_capture

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	bash:shells/bash
LIB_DEPENDS=	libjack.so:audio/jack \
		liblo.so:audio/liblo \
		libmp3lame.so:audio/lame \
		libogg.so:audio/libogg \
		libsndfile.so:audio/libsndfile

USES=		gmake localbase:ldflags pkgconfig

USE_GITHUB=	yes
GH_ACCOUNT=	kmatheussen
GH_PROJECT=	jack_capture

MAKE_ENV=	CFLAGS="${CFLAGS}" LDFLAGS="${LDFLAGS}"

BINARY_ALIAS=	gcc=${CC} g++=${CXX}

PLIST_FILES=	bin/jack_capture

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/jack_capture

.include <bsd.port.mk>
