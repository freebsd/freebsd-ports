# $FreeBSD$

PORTNAME=	trustedqsl
PORTVERSION=	2.0.2
CATEGORIES=	comms hamradio
#MASTER_SITES=	SF/${PORTNAME}/TrustedQSL/v${PORTVERSION}/
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	shurd
DISTNAME=	tqsl-${PORTVERSION}

MAINTAINER=	hamradio@FreeBSD.org
COMMENT=	Amateur Radio Station electronic trusted logbook

LICENSE=	ARRL
LICENSE_NAME=	American Radio Relay League, Inc. All rights reserved.
LICENSE_FILE=	${WRKSRC}/LICENSE.txt
LICENSE_PERMS=	dist-mirror pkg-mirror auto-accept

LIB_DEPENDS=	libdb-5.so:${PORTSDIR}/databases/db5 \
		libcurl.so:${PORTSDIR}/ftp/curl

PKGMESSAGE=	${WRKDIR}/pkg-message

USES=		cmake compiler:features pkgconfig
CMAKE_ARGS=	-DBDB_PREFIX=${LOCALBASE}
USE_WX=		2.8+
WX_UNICODE=	yes
USE_LDCONFIG=	yes

post-patch:
	@${SED} -e 's:%%PREFIX%%:${PREFIX}:g' \
		${FILESDIR}/pkg-message > ${WRKDIR}/pkg-message

.include <bsd.port.mk>
