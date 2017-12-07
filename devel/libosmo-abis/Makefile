# $FreeBSD$

PORTNAME=	libosmo-abis
PORTVERSION=	0.4.0
CATEGORIES=	devel
MASTER_SITES=	http://git.osmocom.org/libosmo-abis/snapshot/ \
		http://chaosophia.net/downloads/osmocom/${PORTNAME}/

MAINTAINER=	koue@chaosophia.net
COMMENT=	Shared code regarding the A-bis interface between BTS and BSC

LICENSE=	AGPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libosmocore.so:devel/libosmocore \
		libtalloc.so:devel/talloc \
		libortp.so:net/ortp

USES=		autoreconf gmake libtool pathfix pkgconfig
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes

post-patch:
	${ECHO_CMD} ${PORTVERSION} > ${WRKSRC}/.tarball-version

.include <bsd.port.mk>
