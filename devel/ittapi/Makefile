PORTNAME=	ittapi
PORTVERSION=	3.26.1
DISTVERSIONPREFIX=	v
CATEGORIES=	devel

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Instrumentation and Tracing Technology and Just-In-Time API
WWW=		https://github.com/intel/ittapi

LICENSE=	BSD3CLAUSE GPLv2
LICENSE_COMB=	dual
LICENSE_FILE_BSD3CLAUSE=${WRKSRC}/LICENSES/BSD-3-Clause.txt
LICENSE_FILE_GPLv2=	${WRKSRC}/LICENSES/GPL-2.0-only.txt

ONLY_FOR_ARCHS=	amd64 i386
ONLY_FOR_ARCHS_REASON=	invokes x86 assembly

USES=		cmake
CMAKE_ARGS=	-DITT_API_IPT_SUPPORT:BOOL=ON

USE_GITHUB=	yes
GH_ACCOUNT=	intel

# Note: Rust support is not yet enabled in this port
OPTIONS_DEFINE=		FORTRAN
FORTRAN_CMAKE_BOOL=	ITT_API_FORTRAN_SUPPORT
FORTRAN_USES=		fortran
FORTRAN_CMAKE_ON=	-DCMAKE_Fortran_COMPILER=${FC}
FORTRAN_BROKEN=		See https://github.com/intel/ittapi/issues/166

pre-configure:
	${REINPLACE_CMD} -e 's|-O2|${CFLAGS}|;s|-module|-Mmodules|'	\
		${WRKSRC}/CMakeLists.txt

.include <bsd.port.mk>
