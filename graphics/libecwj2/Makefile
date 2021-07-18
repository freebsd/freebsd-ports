# Created by: glebius@FreeBSD.org

PORTNAME=	libecwj2
PORTVERSION=	3.3
PORTREVISION=	3
CATEGORIES=	graphics
MASTER_SITES=	http://glebi.us/tmp/403/
DISTFILES=	ecw_jpeg_2000_sdk_3_3_source.zip

MAINTAINER=	glebius@FreeBSD.org
COMMENT=	Erdas ECW and JPEG2000 support library

# Converted from RESTRICTED
LICENSE=	libecwj2
LICENSE_NAME=	libecwj2
LICENSE_TEXT=	Registration required to download sources,\
		but sources no longer available on ERDAS website
LICENSE_PERMS=	auto-accept

USES=		gmake libtool zip
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip

post-extract:
	(cd ${WRKDIR} && \
		${EXTRACT_CMD} ImageCompressionSDKSourceCode3.3Setup_20070509.zip)
	${TOUCH} ${WRKSRC}/Source/NCSBuildGnu/NCSGnuConfig.h.in

.include <bsd.port.mk>
