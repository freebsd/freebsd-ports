# Created by: Sergey A. Osokin <osa@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libhoard
PORTVERSION=	3.10
PORTREVISION=	1
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
BROKEN_powerpc64=	Does not build: Error: instruction address is not a multiple of 4
BROKEN_sparc64=		Does not build

USE_CXXSTD=	gnu++98
USE_LDCONFIG=	yes
WRKSRC=		${WRKDIR}/Hoard/src

ALL_TARGET=	freebsd

PLIST_FILES=	lib/libhoard.so lib/libhoard.so.1

do-install:
	${INSTALL_LIB} ${WRKSRC}/libhoard.so ${STAGEDIR}${PREFIX}/lib/libhoard.so.1
	${LN} -sf libhoard.so.1 ${STAGEDIR}${PREFIX}/lib/libhoard.so

.include <bsd.port.mk>
