# Created by: Dima Sivachenko <dima@chg.ru>
# $FreeBSD$

PORTNAME=	polygraph
PORTVERSION=	4.3.2
CATEGORIES=	benchmarks www
MASTER_SITES=	http://www.web-polygraph.org/downloads/srcs/ \
		http://people.bsdgroup.de/~as/freebsd/distfiles/
DISTNAME=	${PORTNAME}-${PORTVERSION}-src
EXTRACT_SUFX=	.tgz

MAINTAINER=	as@bsdgroup.de
COMMENT=	A benchmarking tool for Web proxies

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GCC=	4.2+
GNU_CONFIGURE=	yes
WRKSRC=	${WRKDIR}/${PORTNAME}-${PORTVERSION}

CONFLICTS=	ltrace-0*

OPTIONS_DEFINE=	GNUPLOT OPENSSL PERL ZLIB

GNUPLOT_DESC=	GNUPlot for full reporting functionality
OPENSSL_DESC=	Enable SSL/HTTPS support
PERL_DESC=	Install Perl for PolyGraph tools
ZLIB_DESC=	Enable HTTP compression support

OPTIONS_DEFAULT=	OPENSSL ZLIB

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MGNUPLOT}
RUN_DEPENDS+=	 gnuplot:${PORTSDIR}/math/gnuplot
.endif

.if ${PORT_OPTIONS:MOPENSSL}
USE_OPENSSL=	yes
CONFIGURE_ARGS+=	--with-ssl=${OPENSSLBASE}
.else
CONFIGURE_ARGS+=	--without-ssl
.endif

.if ${PORT_OPTIONS:MPERL}
USES+=		perl5
USE_PERL5=	run
.endif

.if ${PORT_OPTIONS:MZLIB}
CONFIGURE_ARGS+=	--with-zlib=/usr
.else
CONFIGURE_ARGS+=	--without-zlib
.endif

MAN1=	polygraph-aka.1 polygraph-beepmon.1 polygraph-cdb.1 \
	polygraph-client.1 polygraph-cmp-lx.1 polygraph-distr-test.1 \
	polygraph-dns-cfg.1 polygraph-lr.1 polygraph-ltrace.1 \
	polygraph-lx.1 polygraph-pgl-test.1 polygraph-pgl2acl.1 \
	polygraph-pgl2eng.1 polygraph-pgl2ips.1 polygraph-pgl2ldif.1 \
	polygraph-pmix2-ips.1 polygraph-pmix3-ips.1 polygraph-polymon.1 \
	polygraph-polyprobe.1 polygraph-polyrrd.1 polygraph-pop-test.1 \
	polygraph-reporter.1 polygraph-rng-test.1 polygraph-server.1 \
	polygraph-udp2tcpd.1 polygraph-webaxe4-ips.1

MAN7=	polygraph.7

.include <bsd.port.mk>
