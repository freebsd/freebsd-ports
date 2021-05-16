# Created by: Pete Fritchman <petef@databits.net>

PORTNAME=	iperf
DISTVERSION=	2.1.1-dev
PORTREVISION=	1
CATEGORIES=	benchmarks
MASTER_SITES=	SF/iperf2 \
		LOCAL/sunpoet/iperf/20210422

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Tool to measure maximum TCP and UDP bandwidth

LICENSE=	BSD2CLAUSE

USES=		cpe

GNU_CONFIGURE=	yes

PLIST_FILES=	bin/iperf \
		man/man1/iperf.1.gz
PORTDOCS=	*

CPE_VENDOR=	iperf_project

OPTIONS_DEFINE=	DOCS IPV6 THREADS
OPTIONS_DEFAULT=THREADS

IPV6_CONFIGURE_ENABLE=	ipv6
THREADS_CONFIGURE_ENABLE=	threads
THREADS_LDFLAGS=	-lpthread

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}/
	cd ${WRKSRC}/ && ${INSTALL_DATA} README doc/*.gif doc/*.html ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
