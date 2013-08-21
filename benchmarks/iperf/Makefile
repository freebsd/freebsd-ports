# Created by: Pete Fritchman <petef@databits.net>
# $FreeBSD$

PORTNAME=	iperf
PORTVERSION=	2.0.5
CATEGORIES=	benchmarks
MASTER_SITES=	SF/${PORTNAME}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Tool to measure maximum TCP and UDP bandwidth

LICENSE=	BSD

OPTIONS_DEFINE=	DOCS IPV6 THREADS
OPTIONS_DEFAULT=THREADS

GNU_CONFIGURE=	yes

MAN1=		iperf.1
PLIST_FILES=	bin/iperf
PORTDOCS=	*

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MIPV6}
CATEGORIES+=	ipv6
CONFIGURE_ARGS+=--enable-ipv6
.else
CONFIGURE_ARGS+=--disable-ipv6
.endif

.if ${PORT_OPTIONS:MTHREADS}
CONFIGURE_ARGS+=--enable-threads
LDFLAGS+=	${PTHREAD_LIBS}
.else
CONFIGURE_ARGS+=--disable-threads
.endif

post-install:
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}/
	cd ${WRKSRC}/ && ${INSTALL_DATA} README doc/*.gif doc/*.html ${DOCSDIR}/
.endif

.include <bsd.port.mk>
