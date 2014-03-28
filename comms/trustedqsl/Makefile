# $FreeBSD$

PORTNAME=	trustedqsl
PORTVERSION=	2.0
PORTREVISION=	2
CATEGORIES=	comms hamradio
MASTER_SITES=	SF/${PORTNAME}/TrustedQSL/v${PORTVERSION}/
DISTNAME=	tqsl-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	db@FreeBSD.org
COMMENT=	Amateur Radio Station electronic trusted logbook

LICENSE=	BSD

LIB_DEPENDS=	libdb-5.so:${PORTSDIR}/databases/db5 \
		libcurl.so:${PORTSDIR}/ftp/curl

PKGMESSAGE=	${WRKDIR}/pkg-message

USES=		cmake compiler:features pkgconfig
USE_WX=		2.8+
WX_UNICODE=	yes
USE_LDCONFIG=	yes

post-patch:
	@${SED} -e 's:%%PREFIX%%:${PREFIX}:g' \
		${FILESDIR}/pkg-message > ${WRKDIR}/pkg-message

.include <bsd.port.mk>
