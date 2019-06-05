# Created by: Edwin Groothuis (edwin@mavetju.org)
# $FreeBSD$

PORTNAME=	dnsperf
PORTVERSION=	2.2.1
DISTVERSIONPREFIX=v
PORTREVISION=	1
CATEGORIES=	dns benchmarks net

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Performance measurement of Domain Name System (DNS) servers

LICENSE=	ISCL

BUILD_DEPENDS=	isc-config.sh:dns/bind914
LIB_DEPENDS=	liblmdb.so:databases/lmdb \
		libjson-c.so:devel/json-c \
		libxml2.so:textproc/libxml2

USES=		autoreconf compiler:c11 gnome iconv libtool ssl
USE_GITHUB=	yes

GH_ACCOUNT=	DNS-OARC
GNU_CONFIGURE=	yes
MAKE_ENV=	INSTALL_PROGRAM="${INSTALL_PROGRAM}" \
		INSTALL_SCRIPT="${INSTALL_SCRIPT}" \
		INSTALL_DATA="${INSTALL_DATA}" \
		INSTALL_MAN="${INSTALL_MAN}"
PLIST_FILES=	bin/dnsperf \
		bin/resperf \
		bin/resperf-report \
		man/man1/dnsperf.1.gz \
		man/man1/resperf.1.gz

.include <bsd.port.mk>
