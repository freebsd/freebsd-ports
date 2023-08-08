PORTNAME=	OSKAR
DISTVERSION=	2.8.3
PORTREVISION=	4
CATEGORIES=	astro

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	SKA Radio telescope simulator
WWW=		https://github.com/OxfordSKA/OSKAR

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=		amd64 i386 powerpc powerpc64 powerpc64le
ONLY_FOR_ARCHS_REASON=	gccfeatures.h:54:4: This code has only been tested on x86 and powerpc platforms
BROKEN_FreeBSD_12_powerpc64=	fails to compile: oskar_convert_cirs_relative_directions_to_enu_directions.c:67:29: 'csinl' undeclared (first use in this function)

LIB_DEPENDS=	libcfitsio.so:astro/cfitsio \
		libhdf5.so:science/hdf5 \
		libsz.so:science/libaec

USES=		cmake localbase:ldflags python qt:5 shebangfix
.if !exists(/usr/include/omp.h)
USES+=		compiler:gcc-c++11-lib
.else
USES+=		compiler:c++11-lang
.endif
USE_QT=		core gui network widgets buildtools:build qmake:build
USE_LDCONFIG=	yes

SHEBANG_FILES=	apps/oskar_convert_cst_to_scalar.py
USE_GITHUB=	yes
GH_ACCOUNT=	OxfordSKA

CMAKE_ARGS=	-DFREEBSD_FILESDIR:STRING=${FILESDIR}

.include <bsd.port.mk>
