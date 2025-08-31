PORTNAME=	maxcso
DISTVERSIONPREFIX=	v
DISTVERSION=	1.13.0-36
DISTVERSIONSUFFIX=	-g961f232c
CATEGORIES=	archivers

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	Fast ISO to CSO compressor for PSP and PS2 emulators
WWW=		https://github.com/unknownbrackets/maxcso

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/LICENSE.md

LIB_DEPENDS=	libdeflate.so:archivers/libdeflate \
		liblz4.so:archivers/liblz4 \
		libuv.so:devel/libuv \
		libzopfli.so:archivers/zopfli

USES=		compiler:c++11-lang gmake pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	unknownbrackets

MAKE_ARGS=	USE_EXTERNAL_LIBDEFLATE=1

PLIST_FILES=	bin/${PORTNAME} \
		share/man/man1/${PORTNAME}.1.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${STAGEDIR}${PREFIX}/share/man/man1/

.include <bsd.port.mk>
