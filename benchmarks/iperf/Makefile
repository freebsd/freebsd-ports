# Created by: Pete Fritchman <petef@databits.net>
# $FreeBSD$

PORTNAME=	iperf
PORTVERSION=	2.0.14a
PORTREVISION=	1
CATEGORIES=	benchmarks
MASTER_SITES=	SF/iperf2

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Tool to measure maximum TCP and UDP bandwidth

LICENSE=	BSD2CLAUSE

GNU_CONFIGURE=	yes

PLIST_FILES=	bin/iperf \
		man/man1/iperf.1.gz
PORTDOCS=	*

OPTIONS_DEFINE=	DOCS IPV6 THREADS
OPTIONS_DEFAULT=THREADS

IPV6_CONFIGURE_ENABLE=	ipv6
THREADS_CONFIGURE_ENABLE=	threads
THREADS_LDFLAGS=	-lpthread

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}/
	cd ${WRKSRC}/ && ${INSTALL_DATA} README doc/*.gif doc/*.html ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
