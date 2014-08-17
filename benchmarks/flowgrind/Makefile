# Created by: Lars Eggert <lars@eggert.org>
# $FreeBSD$

PORTNAME=	flowgrind
PORTVERSION=	0.7.1
PORTREVISION=	1
CATEGORIES=	benchmarks

MAINTAINER=	lars@eggert.org
COMMENT=	Measure throughput and other metrics for TCP

LICENSE=	GPLv3

BUILD_DEPENDS=	pcap-config:${PORTSDIR}/net/libpcap
LIB_DEPENDS=	libpcap.so:${PORTSDIR}/net/libpcap \
		libgsl.so:${PORTSDIR}/math/gsl \
		libxmlrpc.so:${PORTSDIR}/net/xmlrpc-c

USE_GITHUB=	yes
GH_ACCOUNT=	${PORTNAME}
GH_TAGNAME=	${PORTNAME}-${PORTVERSION}
GH_COMMIT=	14b0578

USE_AUTOTOOLS=	aclocal autoconf
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-pcap --enable-gsl

post-patch:
	@${RM} -rf ${WRKSRC}/build-aux
	@${REINPLACE_CMD} -e 's|AC_LIB_RPATH||g' ${WRKSRC}/configure.ac

pre-configure:
	cd ${WRKSRC} && ${AUTORECONF} -i

.include <bsd.port.mk>
