PORTNAME=	citus
PORTVERSION=	13.2.0
DISTVERSIONPREFIX=	v
CATEGORIES=	databases
PKGNAMEPREFIX=	pg_

MAINTAINER=	matthew@FreeBSD.org
COMMENT=	Horizontally scale Postgresql using sharding and replication
WWW=		https://www.citusdata.com/

LICENSE=	AGPLv3

USES=		compiler:c11 gmake pgsql:15+ autoreconf ssl

LIB_DEPENDS=	liblz4.so:archivers/liblz4 \
		libzstd.so:archivers/zstd

WANT_PGSQL=	lib server
GNU_CONFIGURE=	yes

OPTIONS_DEFINE=	ANONSTATS

ANONSTATS_DESC=	Enable anonymous statistics collection
ANONSTATS_CONFIGURE_WITH=	libcurl
ANONSTATS_LIB_DEPENDS=		libcurl.so:ftp/curl

USE_GITHUB=	yes
GH_ACCOUNT=	citusdata

INSTALL_TARGET=	install-strip
MAKE_ARGS=	INSTALL="${INSTALL} -c"

.include <bsd.port.mk>
