# Created by: Lars Eggert <lars@eggert.org>
# $FreeBSD$

PORTNAME=	flowgrind
PORTVERSION=	0.6.1
PORTREVISION=	1
CATEGORIES=	benchmarks
MASTER_SITES=	https://launchpad.net/flowgrind/trunk/${PORTNAME}-0.6.1/+download/

MAINTAINER=	lars@eggert.org
COMMENT=	Measure throughput and other metrics for TCP

LIB_DEPENDS=	libxmlrpc++.so:${PORTSDIR}/net/xmlrpc-c \
		libgsl.so:${PORTSDIR}/math/gsl \
		libpcap.so.1:${PORTSDIR}/net/libpcap

USES=		tar:bzip2
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-debug

.include <bsd.port.mk>
