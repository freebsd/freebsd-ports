# $FreeBSD$

PORTNAME=	trustedqsl
PORTVERSION=	2.2.1
CATEGORIES=	comms hamradio
MASTER_SITES=	http://www.arrl.org/files/file/LoTW%20Instructions/ \
		LOCAL/shurd
DISTNAME=	tqsl-${PORTVERSION}

MAINTAINER=	hamradio@FreeBSD.org
COMMENT=	Amateur Radio Station electronic trusted logbook

LICENSE=	ARRL
LICENSE_NAME=	American Radio Relay League, Inc. All rights reserved.
LICENSE_FILE=	${WRKSRC}/LICENSE.txt
LICENSE_PERMS=	dist-mirror pkg-mirror auto-accept

LIB_DEPENDS=	libcurl.so:ftp/curl \
		libexpat.so:textproc/expat2

USE_BDB=	5+

PKGMESSAGE=	${WRKDIR}/pkg-message

USES=		cmake compiler:c++11-lib pkgconfig
CMAKE_ARGS=	-DBDB_PREFIX=${LOCALBASE}
USE_WX=		2.8+
USE_LDCONFIG=	yes
USE_OPENSSL=	yes

OPTIONS_DEFINE=	GEN_CRQ LOAD_CERT STATION_LOC CONVERTER
GEN_CRQ_DESC=	Build gen_crq
LOAD_CERT_DESC=	Build load_cert
STATION_LOC_DESC=	Build station_loc
CONVERTER_DESC=	Build converter

GEN_CRQ_CMAKE_ON=	-DBUILD_GENCRQ=ON
LOAD_CERT_CMAKE_ON=	-DBUILD_LOADCERT=ON
STATION_LOC_CMAKE_ON=	-DBUILD_STATIONLOC=ON
CONVERTER_CMAKE_ON=	-DBUILD_CONVERTER=ON

OPTIONS_SUB=	yes

post-stage-GEN_CRQ-on:
	${INSTALL_PROGRAM} ${WRKSRC}/src/gen_crq ${STAGEDIR}${PREFIX}/bin
post-stage-LOAD_CERT-on:
	${INSTALL_PROGRAM} ${WRKSRC}/src/load_cert ${STAGEDIR}${PREFIX}/bin
post-stage-STATION_LOC-on:
	${INSTALL_PROGRAM} ${WRKSRC}/src/station_loc ${STAGEDIR}${PREFIX}/bin
post-stage-CONVERTER-on:
	${INSTALL_PROGRAM} ${WRKSRC}/src/converter ${STAGEDIR}${PREFIX}/bin

post-patch:
	@${SED} -e 's:%%PREFIX%%:${PREFIX}:g' \
		${FILESDIR}/pkg-message > ${WRKDIR}/pkg-message

.include <bsd.port.mk>
