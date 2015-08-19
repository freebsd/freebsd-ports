# Created by: Dima Sivachenko <dima@chg.ru>
# $FreeBSD$

PORTNAME=	polygraph
PORTVERSION=	4.3.2
PORTREVISION=	1
CATEGORIES=	benchmarks www
MASTER_SITES=	http://www.web-polygraph.org/downloads/srcs/ \
		http://people.bsdgroup.de/~as/freebsd/distfiles/
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Benchmarking tool for Web proxies

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		shebangfix tar:tgz
SHEBANG_FILES=	tools/*.pl
USE_GCC=	any
GNU_CONFIGURE=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

CONFLICTS=	ltrace-0*

OPTIONS_DEFINE=	GNUPLOT OPENSSL PERL ZLIB

GNUPLOT_DESC=	GNUPlot for full reporting functionality
OPENSSL_DESC=	Enable SSL/HTTPS support
PERL_DESC=	Install Perl for PolyGraph tools
ZLIB_DESC=	Enable HTTP compression support

OPTIONS_DEFAULT=	OPENSSL ZLIB

GNUPLOT_RUN_DEPENDS=	 gnuplot:${PORTSDIR}/math/gnuplot

OPENSSL_USE=		OPENSSL=yes
PERL_USES=		perl5
PERL_USE=		PERL5=run
ZLIB_CONFIGURE_WITH=	zlib=/usr

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MOPENSSL}
CONFIGURE_ARGS+=	--with-ssl=${OPENSSLBASE}
.endif

.include <bsd.port.mk>
