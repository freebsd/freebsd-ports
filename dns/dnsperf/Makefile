# Created by: Edwin Groothuis (edwin@mavetju.org)
# $FreeBSD$

PORTNAME=	dnsperf
PORTVERSION=	2.0.0.0
PORTREVISION=	2
CATEGORIES=	dns benchmarks net
MASTER_SITES=	ftp://ftp.nominum.com/pub/nominum/${PORTNAME}/${PORTVERSION}/
DISTNAME=	${PORTNAME}-src-${PORTVERSION}-1

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Accurate performance metrics of Domain Name Services

BUILD_DEPENDS=	isc-config.sh:dns/bind910

USES=		iconv
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
CFLAGS+=	-I.

OPTIONS_DEFINE=	DOCS

# This is a workaround for broken isc/stat.h.
pre-build:
	${MKDIR} ${WRKSRC}/isc
	${ECHO_CMD} "#include <sys/types.h>" > ${WRKSRC}/isc/stat.h
	${ECHO_CMD} "#include <sys/stat.h>" >> ${WRKSRC}/isc/stat.h

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/doc && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
