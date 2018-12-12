# $FreeBSD$

PORTNAME=		maxcso
DISTVERSIONPREFIX=	v
DISTVERSION=		1.10.0
PORTREVISION=	1
CATEGORIES=		archivers

MAINTAINER=	greg@unrelenting.technology
COMMENT=	Fast ISO to CSO compressor for PSP and PS2 emulators

LICENSE=	ISCL

LIB_DEPENDS=	libuv.so:devel/libuv \
		liblz4.so:archivers/liblz4 \
		libzopfli.so:archivers/zopfli

USES=		gmake pkgconfig compiler:c++11-lang

USE_GITHUB=	yes
GH_ACCOUNT=	unknownbrackets

PLIST_FILES=	bin/${PORTNAME}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
