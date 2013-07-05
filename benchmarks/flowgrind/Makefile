# Created by: Lars Eggert <lars@eggert.org>
# $FreeBSD$

PORTNAME=	flowgrind
PORTVERSION=	0.6.0
PORTREVISION=	2
CATEGORIES=	benchmarks
MASTER_SITES=	https://launchpad.net/flowgrind/trunk/${PORTNAME}-0.6/+download/

MAINTAINER=	lars@eggert.org
COMMENT=	Measure throughput and other metrics for TCP

LIB_DEPENDS=	xmlrpc++:${PORTSDIR}/net/xmlrpc-c \
		gsl:${PORTSDIR}/math/gsl
BUILD_DEPENDS=	${LOCALBASE}/lib/libpcap.so:${PORTSDIR}/net/libpcap

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-debug
FETCH_ARGS=	-pRr

MAN1=		flowgrind-stop.1 \
		flowgrind.1 \
		flowgrindd.1

.include <bsd.port.pre.mk>
.include <bsd.port.post.mk>
