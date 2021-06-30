# Created by: trasz <trasz@pin.if.uz.zgora.pl>

PORTNAME=	openjpeg
PORTVERSION=	1.5.2
DISTVERSIONPREFIX=	version.
PORTREVISION=	1
CATEGORIES=	graphics
PKGNAMESUFFIX=	15

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Open-source JPEG 2000 codec

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	liblcms2.so:graphics/lcms2 \
		libpng.so:graphics/png \
		libtiff.so:graphics/tiff

USES=		cmake cpe

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

PORTDOCS=	CHANGES LICENSE

GH_ACCOUNT=	uclouvain
USE_GITHUB=	yes

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
