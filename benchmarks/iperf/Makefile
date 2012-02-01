# New ports collection makefile for:	iperf
# Date Created:				20 May 2001
# Whom:					Pete Fritchman <petef@databits.net>
#
# $FreeBSD$
#

PORTNAME=	iperf
PORTVERSION=	2.0.5
CATEGORIES=	benchmarks
MASTER_SITES=	SF/${PORTNAME}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	A tool to measure maximum TCP and UDP bandwidth

OPTIONS=	IPV6	"Enable support to IPv6" on \
		THREADS	"Enable threads support" on

GNU_CONFIGURE=	yes

MAN1=		iperf.1
PLIST_FILES=	bin/iperf
PORTDOCS=	*

.include <bsd.port.options.mk>

.if defined(WITHOUT_IPV6)
CONFIGURE_ARGS+=--disable-ipv6
.else
CATEGORIES+=	ipv6
.endif

.if defined(WITHOUT_THREADS)
CONFIGURE_ARGS+=--disable-threads
.else
LDFLAGS+=	${PTHREAD_LIBS}
.endif

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}/
	${INSTALL_DATA} ${WRKSRC}/README ${WRKSRC}/doc/*.gif ${WRKSRC}/doc/*.html ${DOCSDIR}/
.endif

.include <bsd.port.mk>
