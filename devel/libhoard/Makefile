PORTNAME=	libhoard
DISTVERSION=	3.13
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	https://github.com/emeryberger/Hoard/releases/download/${DISTVERSION}/
DISTNAME=	hoard-release

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Fast, scalable, and memory-efficient allocator for MP
WWW=		http://www.hoard.org/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/../COPYING

BROKEN_mips=		no spin lock implementation is available for this platform
BROKEN_mips64=		no spin lock implementation is available for this platform

WRKSRC=		${WRKDIR}/Hoard/src
MAKEFILE=	GNUmakefile
USES=		gmake compiler:c++14-lang
USE_LDCONFIG=	yes

ALL_TARGET=	freebsd
CXXFLAGS+=	-D_GLIBCXX_USE_NOEXCEPT=noexcept -Wl,-soname=libhoard.so.1

PLIST_FILES=	lib/libhoard.so lib/libhoard.so.1

do-install:
	${INSTALL_LIB} ${WRKSRC}/libhoard.so ${STAGEDIR}${PREFIX}/lib/libhoard.so.1
	${LN} -sf libhoard.so.1 ${STAGEDIR}${PREFIX}/lib/libhoard.so

.include <bsd.port.mk>
