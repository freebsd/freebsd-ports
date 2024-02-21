PORTNAME=	openjpeg
PORTVERSION=	1.5.2
DISTVERSIONPREFIX=	version.
PORTREVISION=	3
CATEGORIES=	graphics
PKGNAMESUFFIX=	15

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Open-source JPEG 2000 codec
WWW=		https://www.openjpeg.org/

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	liblcms2.so:graphics/lcms2 \
		libpng.so:graphics/png \
		libtiff.so:graphics/tiff

USES=		cmake cpe

USE_LDCONFIG=	yes

PORTDOCS=	CHANGES LICENSE

PLIST_SUB=	PORTVERSION=${PORTVERSION} VER=${PORTVERSION:R}

GH_ACCOUNT=	uclouvain
USE_GITHUB=	yes

CPE_VENDOR=	uclouvain

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
