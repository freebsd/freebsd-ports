# $FreeBSD$

PORTNAME=	OSKAR
DISTVERSION=	2.7.6
PORTREVISION=	1
CATEGORIES=	astro

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	SKA Radio telescope simulator

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=		amd64 i386 powerpc powerpc64 powerpc64le
ONLY_FOR_ARCHS_REASON=	gccfeatures.h:54:4: This code has only been tested on x86 and powerpc platforms
BROKEN_FreeBSD_12_powerpc64=	fails to compile: oskar_convert_cirs_relative_directions_to_enu_directions.c:67:29: 'csinl' undeclared (first use in this function)

LIB_DEPENDS=	libcfitsio.so:astro/cfitsio

USES=		cmake compiler:c++11-lang localbase:ldflags python qt:5 \
		shebangfix
SHEBANG_FILES=	apps/oskar_convert_cst_to_scalar.py
USE_GITHUB=	yes
GH_ACCOUNT=	OxfordSKA
USE_QT=		core gui network widgets buildtools_build qmake_build
USE_LDCONFIG=	yes

CMAKE_ARGS=	-DFREEBSD_FILESDIR:STRING=${FILESDIR}

.include <bsd.port.mk>
