PORTNAME=	ittapi
PORTVERSION=	3.24.4
DISTVERSIONPREFIX=	v
CATEGORIES=	devel

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Instrumentation and Tracing Technology and Just-In-Time API
WWW=		https://github.com/intel/ittapi

LICENSE=	BSD3CLAUSE GPLv2
LICENSE_COMB=	dual
LICENSE_FILE_BSD3CLAUSE=${WRKSRC}/LICENSES/BSD-3-Clause.txt
LICENSE_FILE_GPLv2=	${WRKSRC}/LICENSES/GPL-2.0-only.txt

ONLY_FOR_ARCHS=	amd64 i386
ONLY_FOR_ARCHS_REASON=	invokes x86 assembly

USE_GITHUB=	yes
GH_ACCOUNT=	intel

USES=		cmake
CMAKE_ARGS=	-DITT_API_IPT_SUPPORT:BOOL=ON

# Note: Rust support is not yet enabled in this port
OPTIONS_DEFINE=		FORTRAN
FORTRAN_CMAKE_BOOL=	ITT_API_FORTRAN_SUPPORT

.include <bsd.port.mk>
