# Created by: Sergey A. Osokin <osa@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libhoard
PORTVERSION=	3.10
CATEGORIES=	devel
MASTER_SITES=	https://github.com/emeryberger/Hoard/releases/download/${PORTVERSION}/
DISTNAME=	Hoard-${PORTVERSION}-source

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Fast, scalable, and memory-efficient allocator for MP

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/../COPYING

BROKEN_aarch64=		no spin lock implementation is available for this platform
BROKEN_mips=		no spin lock implementation is available for this platform
BROKEN_mips64=		no spin lock implementation is available for this platform
BROKEN_powerpc64=	Does not build
BROKEN_sparc64=		Does not build

USE_LDCONFIG=	yes
WRKSRC=		${WRKDIR}/Hoard/src

ALL_TARGET=	freebsd

PLIST_FILES=	lib/libhoard.so lib/libhoard.so.1

post-patch:
	${REINPLACE_CMD} 's!g++!${CXX}!; s!-O2!${CFLAGS}!' ${WRKSRC}/Makefile

do-install:
	${STRIP_CMD} ${WRKSRC}/libhoard.so
	${INSTALL_DATA} ${WRKSRC}/libhoard.so ${STAGEDIR}${PREFIX}/lib/libhoard.so.1
	${LN} -sf libhoard.so.1 ${STAGEDIR}${PREFIX}/lib/libhoard.so

.include <bsd.port.mk>
