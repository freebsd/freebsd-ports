PORTNAME=	trustedqsl
DISTVERSION=	2.8.4
CATEGORIES=	comms hamradio
MASTER_SITES=	https://www.arrl.org/files/file/LoTW%20Instructions/
DISTNAME=	tqsl-${DISTVERSION}

MAINTAINER=	hamradio@FreeBSD.org
COMMENT=	Amateur Radio Station electronic trusted logbook
WWW=		https://lotw.arrl.org/lotw-help/ \
		https://sourceforge.net/projects/trustedqsl/

LICENSE=	ARRL
LICENSE_NAME=	American Radio Relay League, Inc. All rights reserved.
LICENSE_FILE=	${WRKSRC}/LICENSE.txt
LICENSE_PERMS=	dist-mirror pkg-mirror auto-accept

LIB_DEPENDS=	libcurl.so:ftp/curl \
		libexpat.so:textproc/expat2

USES=		cmake compiler:c++11-lib gettext pkgconfig ssl sqlite
USE_LDCONFIG=	yes
USE_WX=		3.2

CMAKE_ARGS=	-DCMAKE_INSTALL_MANDIR:PATH="share/man"

PKGMESSAGE=	${WRKDIR}/pkg-message

OPTIONS_DEFINE=		GEN_CRQ LOAD_CERT STATION_LOC CONVERTER
OPTIONS_SUB=		yes

CONVERTER_DESC=		Build converter
GEN_CRQ_DESC=		Build gen_crq
LOAD_CERT_DESC=		Build load_cert
STATION_LOC_DESC=	Build station_loc

CONVERTER_CMAKE_BOOL=	BUILD_CONVERTER
GEN_CRQ_CMAKE_BOOL=	BUILD_GENCRQ
LOAD_CERT_CMAKE_BOOL=	BUILD_LOADCERT
STATION_LOC_CMAKE_BOOL=	BUILD_STATIONLOC

post-patch:
	@${SED} -e 's:%%PREFIX%%:${PREFIX}:g' \
		${FILESDIR}/pkg-message > ${WRKDIR}/pkg-message

post-install-CONVERTER-on:
	${INSTALL_PROGRAM} ${WRKSRC}/src/converter ${STAGEDIR}${PREFIX}/bin
post-install-GEN_CRQ-on:
	${INSTALL_PROGRAM} ${WRKSRC}/src/gen_crq ${STAGEDIR}${PREFIX}/bin
post-install-LOAD_CERT-on:
	${INSTALL_PROGRAM} ${WRKSRC}/src/load_cert ${STAGEDIR}${PREFIX}/bin
post-install-STATION_LOC-on:
	${INSTALL_PROGRAM} ${WRKSRC}/src/station_loc ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
