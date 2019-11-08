# $FreeBSD$

PORTNAME=	iccxml
PORTVERSION=	0.9.8
CATEGORIES=	graphics
MASTER_SITES=	SF/${PORTNAME}/IccXML-Src/${DISTNAME}
DISTNAME=	IccXML-${PORTVERSION}

MAINTAINER=	bsam@FreeBSD.org
COMMENT=	Tools for reading and writing the ICC profile contents as XML files

LIB_DEPENDS=	libSampleICC.so:graphics/sampleicc

USES=		gmake gnome libtool pathfix pkgconfig
GNU_CONFIGURE=	yes
USE_GNOME=	libxml2
USE_LDCONFIG=	yes

.include <bsd.port.mk>
