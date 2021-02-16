# $FreeBSD$

PORTNAME=	iccxml
PORTVERSION=	0.9.8
CATEGORIES=	graphics
MASTER_SITES=	SF/${PORTNAME}/IccXML-Src/${DISTNAME}
DISTNAME=	IccXML-${PORTVERSION}

MAINTAINER=	bsam@FreeBSD.org
COMMENT=	Tools for reading and writing the ICC profile contents as XML files

BROKEN_FreeBSD_13=	IccProfileXml.cpp:512:12: error: cannot initialize return object of type 'bool' with an rvalue of type 'nullptr_t'
BROKEN_FreeBSD_14=	IccProfileXml.cpp:512:12: error: cannot initialize return object of type 'bool' with an rvalue of type 'nullptr_t'

LIB_DEPENDS=	libSampleICC.so:graphics/sampleicc

USES=		gmake gnome libtool pathfix pkgconfig
GNU_CONFIGURE=	yes
USE_GNOME=	libxml2
USE_LDCONFIG=	yes

.include <bsd.port.mk>
