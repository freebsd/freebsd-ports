# $FreeBSD$

PORTNAME=	libosmo-netif
PORTVERSION=	0.0.6
CATEGORIES=	devel
MASTER_SITES=	http://git.osmocom.org/libosmo-netif/snapshot/ \
		http://chaosophia.net/downloads/osmocom/${PORTNAME}/

MAINTAINER=	koue@chaosophia.net
COMMENT=	Library containing common/shared code regarding network interface

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libosmocore.so:devel/libosmocore \
		libosmoabis.so:devel/libosmo-abis

BROKEN_mips=	Does not build: undefined reference to __bswap_16
BROKEN_mips64=	Does not build: undefined reference to __bswap_16
BROKEN_powerpc64=	Does not build
BROKEN_sparc64=	Does not build: undefined reference to __bswap_16

USES=		autoreconf libtool pathfix pkgconfig
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes

post-patch:
	${ECHO_CMD} ${PORTVERSION} > ${WRKSRC}/.tarball-version

.include <bsd.port.mk>
