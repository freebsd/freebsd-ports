# Created by: Edwin Groothuis (edwin@mavetju.org)
# $FreeBSD$

PORTNAME=	dnsperf
PORTVERSION=	2.1.0.0
PORTREVISION=	1
CATEGORIES=	dns benchmarks net
MASTER_SITES=	ftp://ftp.nominum.com/pub/nominum/${PORTNAME}/${PORTVERSION}/
DISTNAME=	${PORTNAME}-src-${PORTVERSION}-1

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Performance measurement of Domain Name System (DNS) servers

LICENSE=	ISCL

BROKEN=		fails to build

BUILD_DEPENDS=	isc-config.sh:dns/bind912
LIB_DEPENDS=	liblmdb.so:databases/lmdb \
		libjson-c.so:devel/json-c

USES=		iconv ssl
USE_GNOME=	libxml2
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
PORTDOCS=	caching-dns-performance.pdf \
		dnsperf.pdf \
		resperf.pdf

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/doc && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
