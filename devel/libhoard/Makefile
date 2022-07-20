PORTNAME=	libhoard
PORTVERSION=	3.13
CATEGORIES=	devel
MASTER_SITES=	https://github.com/emeryberger/Hoard/releases/download/${PORTVERSION}/
DISTNAME=	hoard-release

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Fast, scalable, and memory-efficient allocator for MP

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/../COPYING

BROKEN_mips=		no spin lock implementation is available for this platform
BROKEN_mips64=		no spin lock implementation is available for this platform
BROKEN_sparc64=		Does not build

WRKSRC=		${WRKDIR}/Hoard/src
MAKEFILE=	GNUmakefile
USES=		gmake compiler:c++14-lang
ALL_TARGET=	freebsd
USE_LDCONFIG=	yes

PLIST_FILES=	lib/libhoard.so lib/libhoard.so.1

do-install:
	${INSTALL_LIB} ${WRKSRC}/libhoard.so ${STAGEDIR}${PREFIX}/lib/libhoard.so.1
	${LN} -sf libhoard.so.1 ${STAGEDIR}${PREFIX}/lib/libhoard.so

.include <bsd.port.mk>
