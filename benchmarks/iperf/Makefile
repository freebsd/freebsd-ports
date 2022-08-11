PORTNAME=	iperf
PORTVERSION=	2.1.7
CATEGORIES=	benchmarks
MASTER_SITES=	SF/iperf2 \
		LOCAL/sunpoet

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Tool to measure maximum TCP and UDP bandwidth

LICENSE=	BSD2CLAUSE

USES=		cpe

GNU_CONFIGURE=	yes

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
