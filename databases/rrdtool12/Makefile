# Created by: Jeremy Chadwick <koitsu@FreeBSD.org>

PORTNAME=	rrdtool
PORTVERSION=	1.2.30
PORTREVISION=	8
CATEGORIES=	databases graphics
MASTER_SITES=	http://oss.oetiker.ch/rrdtool/pub/
PKGNAMESUFFIX=	12

MAINTAINER=	beat@FreeBSD.org
COMMENT=	Round Robin Database Tools v1.2

LIB_DEPENDS=	libfreetype.so:print/freetype2 \
		libart_lgpl_2.so:graphics/libart_lgpl \
		libpng.so:graphics/png

CONFLICTS_INSTALL=	rrdtool # include/rrd.h

USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
USES=		cpe gmake libtool
CPE_VENDOR=	${PORTNAME}_project

CONFIGURE_ARGS=	--disable-tcl --disable-python

OPTIONS_DEFINE=	RUBY PERL DOCS EXAMPLES
OPTIONS_DEFAULT=	PERL

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MRUBY}
USE_RUBY=	yes
PLIST_SUB+=	WITH_RUBY=""
CONFIGURE_ARGS+=	--enable-ruby
.else
CONFIGURE_ARGS+=	--disable-ruby
PLIST_SUB+=	WITH_RUBY="@comment "
.endif

.if ${PORT_OPTIONS:MPERL}
USES+=		perl5
USE_PERL5=	run build
CONFIGURE_ARGS+=	--enable-perl --enable-perl-site-install
PLIST_SUB+=	WITH_PERL=""
.else
CONFIGURE_ARGS+=	--disable-perl
PLIST_SUB+=	WITH_PERL="@comment "
.endif

CPPFLAGS+=	-I${LOCALBASE}/include -I${LOCALBASE}/include/libart-2.0 -I${LOCALBASE}/include/freetype2
LDFLAGS+=	-L${LOCALBASE}/lib
CFLAGS:=	${CFLAGS:N-ffast-math}

post-extract:
.if empty(PORT_OPTIONS:MDOCS)
	@${REINPLACE_CMD} -e 's/install-idocDATA install-ihtmlDATA//g' \
		-e 's/^	cd .* rrdtool.html index.html/	#/' \
		${WRKSRC}/doc/Makefile.in
.endif
.if empty(PORT_OPTIONS:MEXAMPLES)
	${REINPLACE_CMD} -e '/^SUBDIRS = /s| examples | |' \
		${WRKSRC}/Makefile.in
.endif

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/librrd.so.2
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/librrd_th.so.2
.if !defined(BATCH) && empty(PORT_OPTIONS:MEXAMPLES)
	@${ECHO_MSG} ""
	@${ECHO_MSG} "############################################################################"
	@${ECHO_MSG} "# See ${PREFIX}/share/examples/rrdtool for some demonstration code        #"
	@${ECHO_MSG} "############################################################################"
.endif

.include <bsd.port.mk>
