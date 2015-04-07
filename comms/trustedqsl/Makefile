# $FreeBSD$

PORTNAME=	trustedqsl
PORTVERSION=	2.0.3
PORTREVISION=	2
CATEGORIES=	comms hamradio
MASTER_SITES=	SF/${PORTNAME}/TrustedQSL/v${PORTVERSION}/
DISTNAME=	tqsl-${PORTVERSION}

MAINTAINER=	hamradio@FreeBSD.org
COMMENT=	Amateur Radio Station electronic trusted logbook

LICENSE=	ARRL
LICENSE_NAME=	American Radio Relay League, Inc. All rights reserved.
LICENSE_FILE=	${WRKSRC}/LICENSE.txt
LICENSE_PERMS=	dist-mirror pkg-mirror auto-accept

LIB_DEPENDS=	libcurl.so:${PORTSDIR}/ftp/curl

USE_BDB=	5+

PKGMESSAGE=	${WRKDIR}/pkg-message

USES=		cmake compiler:features pkgconfig
CMAKE_ARGS=	-DBDB_PREFIX=${LOCALBASE}
USE_WX=		2.8+
WX_UNICODE=	yes
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

.include <bsd.port.options.mk>

post-stage:
.if ${PORT_OPTIONS:MGEN_CRQ}
	${INSTALL_PROGRAM} ${WRKSRC}/src/gen_crq ${STAGEDIR}${PREFIX}/bin
.endif
.if ${PORT_OPTIONS:MLOAD_CERT}
	${INSTALL_PROGRAM} ${WRKSRC}/src/load_cert ${STAGEDIR}${PREFIX}/bin
.endif
.if ${PORT_OPTIONS:MSTATION_LOC}
	${INSTALL_PROGRAM} ${WRKSRC}/src/station_loc ${STAGEDIR}${PREFIX}/bin
.endif
.if ${PORT_OPTIONS:MCONVERTER}
	${INSTALL_PROGRAM} ${WRKSRC}/src/converter ${STAGEDIR}${PREFIX}/bin
.endif

post-patch:
	@${SED} -e 's:%%PREFIX%%:${PREFIX}:g' \
		${FILESDIR}/pkg-message > ${WRKDIR}/pkg-message

.include <bsd.port.mk>
