PORTNAME=	flowgrind
PORTVERSION=	0.8.2
DISTVERSIONPREFIX=	${PORTNAME}-
PORTREVISION=	4
CATEGORIES=	benchmarks

MAINTAINER=	dbaio@FreeBSD.org
COMMENT=	Measure throughput and other metrics for TCP
WWW=		https://flowgrind.github.io

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libgsl.so:math/gsl \
		libxmlrpc.so:net/xmlrpc-c \
		libcurl.so:ftp/curl \
		libwwwxml.so:www/libwww \
		libuuid.so:misc/libuuid \
		libexpat.so:textproc/expat2

USES=		autoreconf ssl

USE_GITHUB=	yes

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
CONFIGURE_ENV=	LIBS="${LIBS} -lpcap"

.include <bsd.port.mk>
