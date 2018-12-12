# Created by: Dima Sivachenko <dima@chg.ru>
# $FreeBSD$

PORTNAME=	polygraph
DISTVERSION=	4.13.0
PORTREVISION=	1
CATEGORIES=	benchmarks www
MASTER_SITES=	http://www.web-polygraph.org/downloads/srcs/
EXTRACT_SUFX=	-src.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Benchmarking tool for Web proxies

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		gmake ncurses shebangfix
SHEBANG_FILES=	tools/*.pl
USE_GCC=	any
GNU_CONFIGURE=	yes

# The port does not build with C++11 or later (bug 219275).
USE_CXXSTD=	gnu++98

CONFLICTS=	ltrace-0*

OPTIONS_DEFINE=		DOCS GNUPLOT GSSAPI LDNS PERL SSL ZLIB
OPTIONS_DEFAULT=	SSL ZLIB

GNUPLOT_DESC=		GNUPlot for full reporting functionality
GNUPLOT_RUN_DEPENDS=	gnuplot:math/gnuplot
GSSAPI_USES=		gssapi:mit
GSSAPI_CONFIGURE_ON=	--with-kerberos=${KRB5CONFIG} ${GSSAPI_CONFIGURE_ARGS}
GSSAPI_CONFIGURE_OFF=	--without-kerberos
LDNS_DESC=		DNS zone file support via libldns
LDNS_LIB_DEPENDS=	libldns.so:dns/ldns
LDNS_CONFIGURE_ON=	--with-ldns=${LOCALBASE}/bin/ldns-config
LDNS_CONFIGURE_OFF=	--without-ldns
SSL_DESC=		SSL/HTTPS support
SSL_USES=		ssl
SSL_CONFIGURE_ON=	--with-ssl=${OPENSSLBASE}
SSL_CONFIGURE_OFF=	--without-ssl
PERL_DESC=		Install Perl for PolyGraph tools
PERL_USES=		perl5
PERL_USE=		perl5=run
ZLIB_DESC=		HTTP compression support
ZLIB_CONFIGURE_ON=	--with-zlib=/usr
ZLIB_CONFIGURE_OFF=	--without-zlib

post-patch:
	@${REINPLACE_CMD} -e \
		'/LICENSE /d' ${WRKSRC}/Makefile.in

.include <bsd.port.mk>
