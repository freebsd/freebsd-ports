# Created by: Vasil Dimov <vd@FreeBSD.org>

PORTNAME=	libpano13
DISTVERSION=	2.9.20
CATEGORIES=	graphics java
MASTER_SITES=	SF/panotools/${PORTNAME}/${PORTNAME}-${DISTVERSION}

MAINTAINER=	fuz@fuz.su
COMMENT=	Cross-platform library behind Panorama Tools and other photo stitchers

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libpng.so:graphics/png \
		libtiff.so:graphics/tiff

CMAKE_ON=	CMAKE_DISABLE_FIND_PACKAGE_GnuTar

USES=		cmake cpe jpeg libtool pathfix pkgconfig
CPE_VENDOR=	${PORTNAME}_project
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	DOCS JAVA STATIC
OPTIONS_SUB=	yes

JAVA_USE=		java=yes
JAVA_CMAKE_BOOL=	SUPPORT_JAVA_PROGRAMS
JAVA_VARS=		JAVA_OS=native

post-install-STATIC-off:
	${RM} ${STAGEDIR}${PREFIX}/lib/libpano13.a

.include <bsd.port.mk>
