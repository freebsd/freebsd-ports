PORTNAME=	flowgrind
PORTVERSION=	0.8.2
DISTVERSIONPREFIX=	${PORTNAME}-
PORTREVISION=	2
CATEGORIES=	benchmarks

MAINTAINER=	dbaio@FreeBSD.org
COMMENT=	Measure throughput and other metrics for TCP

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libgsl.so:math/gsl \
		libxmlrpc.so:net/xmlrpc-c \
		libcurl.so:ftp/curl \
		libwwwxml.so:www/libwww \
		libuuid.so:misc/e2fsprogs-libuuid \
		libexpat.so:textproc/expat2

USES=		autoreconf ssl

USE_GITHUB=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	LIBS="${LIBS} -lpcap"

.include <bsd.port.mk>
