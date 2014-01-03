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
		libpcap.so:${PORTSDIR}/net/libpcap

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-debug

MAN1=		flowgrind-stop.1 \
		flowgrind.1 \
		flowgrindd.1

NO_STAGE=	yes
.include <bsd.port.mk>
