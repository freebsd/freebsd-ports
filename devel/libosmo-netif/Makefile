# $FreeBSD$

PORTNAME=	libosmo-netif
PORTVERSION=	0.0.4
CATEGORIES=	devel
MASTER_SITES=	http://git.osmocom.org/libosmo-netif/snapshot/ \
		http://chaosophia.net/downloads/osmocom/${PORTNAME}/

MAINTAINER=	koue@chaosophia.net
COMMENT=	Library containing common/shared code regarding network interface

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libosmocore.so:${PORTSDIR}/devel/libosmocore \
		libosmoabis.so:${PORTSDIR}/devel/libosmo-abis

USES=		autoreconf libtool pathfix pkgconfig
PATHFIX_MAKEFILEIN=Makefile.am
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes

post-patch:
	${REINPLACE_CMD} -e 's,endian\.h,sys/endian.h,' \
		-e 's,__BYTE_ORDER,BYTE_ORDER,' \
		-e 's,__LITTLE_ENDIAN,LITTLE_ENDIAN,' \
		-e 's,__BIG_ENDIAN,BIG_ENDIAN,' \
		${WRKSRC}/configure.ac \
		${WRKSRC}/examples/rs232-write.c \
		${WRKSRC}/include/osmocom/netif/amr.h \
		${WRKSRC}/include/osmocom/netif/rtp.h \
		${WRKSRC}/include/osmocom/netif/osmux.h \
		${WRKSRC}/src/rtp.c
	${ECHO_CMD} ${PORTVERSION} > ${WRKSRC}/.tarball-version

.include <bsd.port.mk>
