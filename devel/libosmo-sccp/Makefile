# $FreeBSD$

PORTNAME=	libosmo-sccp
PORTVERSION=	0.10.0
CATEGORIES=	devel
MASTER_SITES=	http://git.osmocom.org/libosmo-sccp/snapshot/ \
		http://chaosophia.net/downloads/osmocom/${PORTNAME}/

MAINTAINER=	koue@chaosophia.net
COMMENT=	SCCP network layer protocol implementation

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

DEPRECATED=	Depends on expired devel/libosmo-netif
EXPIRATION_DATE=2020-06-05

LIB_DEPENDS=	libosmocore.so:devel/libosmocore \
		libosmonetif.so:devel/libosmo-netif \
		libtalloc.so:devel/talloc

CONFLICTS_INSTALL=libmtp-[0-9]* # lib/libmtp.a

USES=		autoreconf libtool pathfix pkgconfig
GNU_CONFIGURE=	yes

OPTIONS_DEFINE=	DOCS

post-patch:
	${ECHO_CMD} ${PORTVERSION} > ${WRKSRC}/.tarball-version

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/lib*.so

.include <bsd.port.mk>
