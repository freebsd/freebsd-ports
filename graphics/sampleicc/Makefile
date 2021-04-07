PORTNAME=	sampleicc
PORTVERSION=	1.6.8
PORTREVISION=	1
CATEGORIES=	graphics devel
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}%20tar/SampleIcc-${PORTVERSION}/
DISTNAME=	SampleICC-${PORTVERSION}

MAINTAINER=	office@FreeBSD.org
COMMENT=	Library for reading, writing, manipulating, and applying ICC profiles

LICENSE=	ICC
LICENSE_NAME=	The ICC Software License, Version 0.2
LICENSE_FILE=	${WRKSRC}/COPYING
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

LIB_DEPENDS=	libtiff.so:graphics/tiff

GNU_CONFIGURE=	yes
USES=	libtool pathfix
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip
CONFIGURE_ARGS=	--with-tifflib=${LOCALBASE}

.include <bsd.port.mk>
