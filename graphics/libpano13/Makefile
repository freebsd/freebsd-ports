PORTNAME=	libpano13
DISTVERSION=	2.9.22
PORTREVISION=	11
CATEGORIES=	graphics java
MASTER_SITES=	SF/panotools/${PORTNAME}/${PORTNAME}-${DISTVERSION}

MAINTAINER=	fuz@FreeBSD.org
COMMENT=	Cross-platform library behind Panorama Tools and other photo stitchers
WWW=		https://panotools.sourceforge.net/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libpng.so:graphics/png \
		libtiff.so:graphics/tiff

USES=		cmake:testing cpe jpeg pathfix perl5 pkgconfig
CPE_VENDOR=	${PORTNAME}_project
USE_LDCONFIG=	yes
USE_PERL5=	build	# for pod2man

WRKSRC=		${WRKDIR}/libpano13-${DISTVERSION}

OPTIONS_DEFINE=	DOCS JAVA SUITESPARSE
OPTIONS_DEFAULT=	SUITESPARSE
SUITESPARSE_DESC=	Use math/suitesparse for faster operation
OPTIONS_SUB=	yes
JAVA_USES=	java
JAVA_CMAKE_BOOL=	SUPPORT_JAVA_PROGRAMS
JAVA_VARS=	JAVA_OS=native
SUITESPARSE_LIB_DEPENDS= \
		libcholmod.so:math/suitesparse-cholmod \
		libspqr.so:math/suitesparse-spqr
SUITESPARSE_CMAKE_BOOL=	USE_SPARSE_LEVMAR

.include <bsd.port.mk>
