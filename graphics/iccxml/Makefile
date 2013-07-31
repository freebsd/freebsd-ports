# $FreeBSD$

PORTNAME=	iccxml
PORTVERSION=	0.9.6
CATEGORIES=	graphics
MASTER_SITES=	SF/${PORTNAME}/IccXML-Src/${DISTNAME}
DISTNAME=	IccXML-${PORTVERSION}

MAINTAINER=	bsam@FreeBSD.org
COMMENT=	Tools for reading and writing the ICC profile contents as XML files

LIB_DEPENDS=	SampleICC:${PORTSDIR}/graphics/sampleicc

USES=		gmake pkgconfig
GNU_CONFIGURE=	yes
USE_GNOME=	libxml2
USE_LDCONFIG=	yes

CONFIGURE_ENV+=	PKG_CONFIG_PATH=${PREFIX}/libdata/pkgconfig

post-patch:
		@${REINPLACE_CMD} 's:(libdir)/pkgconfig:(prefix)/libdata/pkgconfig:g' \
			${WRKSRC}/Makefile.in

.include <bsd.port.mk>
