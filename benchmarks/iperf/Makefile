# Created by: Pete Fritchman <petef@databits.net>
# $FreeBSD$

PORTNAME=	iperf
PORTVERSION=	2.0.9
CATEGORIES=	benchmarks
MASTER_SITES=	SF/${PORTNAME}2

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Tool to measure maximum TCP and UDP bandwidth

LICENSE=	BSD2CLAUSE

OPTIONS_DEFINE=	DOCS IPV6 THREADS
OPTIONS_DEFAULT=THREADS

GNU_CONFIGURE=	yes

PLIST_FILES=	bin/iperf \
		man/man1/iperf.1.gz
PORTDOCS=	*

IPV6_CATEGORIES=	ipv6
IPV6_CONFIGURE_ENABLE=	ipv6
THREADS_CONFIGURE_ENABLE=	threads
THREADS_LDFLAGS=	-lpthread

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}/
	cd ${WRKSRC}/ && ${INSTALL_DATA} README doc/*.gif doc/*.html ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
