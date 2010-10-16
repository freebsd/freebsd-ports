# New ports collection makefile for:	libecwj2
# Date created:		3 August 2010
# Whom:			glebius@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	libecwj2
PORTVERSION=	3.3
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	glebius
DISTFILES=	ecw_jpeg_2000_sdk_3_3_source.zip

MAINTAINER=	glebius@FreeBSD.org
COMMENT=	Erdas ECW and JPEG2000 support library

RESTRICTED=	Registration required to download sources, \
		sources temporary unavailable on ERDAS website
NO_PACKAGE=	${RESTRICTED}
NO_CDROM=	${RESTRICTED}

USE_ZIP=	yes
USE_AUTOTOOLS=	libtool:22 autoconf:268
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes

post-extract:
	cd ${WRKDIR} && \
		${EXTRACT_CMD} ImageCompressionSDKSourceCode3.3Setup_20070509.zip

post-patch:
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g' ${WRKSRC}/configure.in

.include <bsd.port.mk>
