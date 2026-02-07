PORTNAME=	iccxml
PORTVERSION=	0.9.8
PORTREVISION=	3
CATEGORIES=	graphics
MASTER_SITES=	SF/${PORTNAME}/IccXML-Src/${DISTNAME}
DISTNAME=	IccXML-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tools for reading and writing the ICC profile contents as XML files
WWW=		http://iccxml.sourceforge.net/

LIB_DEPENDS=	libSampleICC.so:graphics/sampleicc

USES=		gmake gnome libtool pathfix pkgconfig
USE_CXXSTD=	c++14
USE_GNOME=	libxml2
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes

INSTALL_TARGET=	install-strip

post-patch:
	@${REINPLACE_CMD} -e 's,return NULL,return false,' \
		${WRKSRC}/IccLibXML/IccProfileXml.cpp

.include <bsd.port.mk>
