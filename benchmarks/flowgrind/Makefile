# Created by: Lars Eggert <lars@eggert.org>
# $FreeBSD$

PORTNAME=	flowgrind
PORTVERSION=	0.8.0
DISTVERSIONPREFIX=	${PORTNAME}-
PORTREVISION=	5
CATEGORIES=	benchmarks

MAINTAINER=	dbaio@FreeBSD.org
COMMENT=	Measure throughput and other metrics for TCP

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libgsl.so:math/gsl \
		libxmlrpc.so:net/xmlrpc-c \
		libcurl.so:ftp/curl \
		libwwwxml.so:www/libwww \
		libuuid.so:misc/e2fsprogs-libuuid

USES=		autoreconf ssl

USE_GITHUB=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	LIBS="${LIBS} -lpcap"

.include <bsd.port.mk>
