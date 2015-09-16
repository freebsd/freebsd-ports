# $FreeBSD$

PORTNAME=	libx86
PORTVERSION=	1.1
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	http://www.codon.org.uk/~mjg59/libx86/downloads/	\
		LOCAL/jkim

MAINTAINER=	jkim@FreeBSD.org
COMMENT=	Hardware-independent library for executing real-mode x86 code

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYRIGHT

ALL_TARGET=	default
MAKE_ARGS=	BACKEND=x86emu
ONLY_FOR_ARCHS=	amd64 i386
PLIST_FILES=	include/libx86.h lib/libx86.a lib/libx86.so lib/libx86.so.1
USE_LDCONFIG=	yes
USES=		gmake

do-install:
	${INSTALL_DATA} ${WRKSRC}/lrmi.h ${STAGEDIR}${PREFIX}/include/libx86.h
	${INSTALL_DATA} ${WRKSRC}/libx86.a ${STAGEDIR}${PREFIX}/lib
	${INSTALL_PROGRAM} ${WRKSRC}/libx86.so.1 ${STAGEDIR}${PREFIX}/lib
	${LN} -sf libx86.so.1 ${STAGEDIR}${PREFIX}/lib/libx86.so

.include <bsd.port.mk>
