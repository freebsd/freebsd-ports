# Created by: Jung-uk Kim <jkim@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libx86
PORTVERSION=	1.1
CATEGORIES=	devel
MASTER_SITES=	http://www.codon.org.uk/~mjg59/libx86/downloads/	\
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	jkim

MAINTAINER=	jkim@FreeBSD.org
COMMENT=	A hardware-independent library for executing real-mode x86 code

PLIST_FILES=	include/libx86.h lib/libx86.a lib/libx86.so.1 lib/libx86.so

USE_GMAKE=	yes
USE_LDCONFIG=	yes
USE_SUBMAKE=	yes
ALL_TARGET=	default
MAKE_ARGS+=	LIBDIR=${PREFIX}/lib
MAKE_ENV+=	BACKEND=x86emu

NO_STAGE=	yes
do-install:
	${INSTALL_DATA} ${WRKSRC}/lrmi.h ${PREFIX}/include/libx86.h
	${INSTALL_DATA} ${WRKSRC}/libx86.a ${PREFIX}/lib
	${INSTALL_PROGRAM} ${WRKSRC}/libx86.so.1 ${PREFIX}/lib
	${LN} -sf ${PREFIX}/lib/libx86.so.1 ${PREFIX}/lib/libx86.so

.include <bsd.port.pre.mk>

ONLY_FOR_ARCHS=	amd64 i386

.include <bsd.port.post.mk>
