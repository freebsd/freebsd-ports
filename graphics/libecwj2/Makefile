# New ports collection makefile for:	libecwj2
# Date created:		3 August 2010
# Whom:			glebius@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	libecwj2
PORTVERSION=	3.3
CATEGORIES=	graphics
MASTER_SITES=
DISTFILES=	ecw_jpeg_2000_sdk_3_3_source.zip

MAINTAINER=	glebius@FreeBSD.org
COMMENT=	Erdas ECW and JPEG2000 support library

RESTRICTED=	Registration required to download sources
NO_CDROM=	${RESTRICTED}

USE_ZIP=	yes
USE_AUTOTOOLS=	libtool:22 autoconf:262
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes

.include <bsd.port.pre.mk>

pre-fetch:
.if !exists(${DISTDIR}/${DISTFILES})
	@${ECHO_MSG} Due to licensing restrictions the sources must be fetched manually.
	@${ECHO_MSG} You need to register at ERDAS website and download
	@${ECHO_MSG}
	@${ECHO_MSG} ${DISTFILES}
	@${ECHO_MSG}
	@${ECHO_MSG} from http://www.ermapper.com/Products/ERDASProductInformation/tabid/84/currentid/1142/default.aspx, and put it into ${DISTDIR}
	@${ECHO_MSG}
	@exit 1
.endif

post-extract:
	cd ${WRKDIR} && \
		${EXTRACT_CMD} ImageCompressionSDKSourceCode3.3Setup_20070509.zip

post-patch:
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g' ${WRKSRC}/configure.in

.include <bsd.port.post.mk>
