# Created by: Dmitry Sivachenko <dima@Chg.RU>
# $FreeBSD$

PORTNAME=	rrdtool
PORTVERSION=	1.4.8
CATEGORIES=	databases graphics
MASTER_SITES=	http://oss.oetiker.ch/rrdtool/pub/

MAINTAINER=	sylvio@FreeBSD.org
COMMENT=	Round Robin Database Tools

LICENSE=	GPLv2

LIB_DEPENDS=	libfreetype.so:${PORTSDIR}/print/freetype2 \
		libcairo.so:${PORTSDIR}/graphics/cairo \
		libpng15.so:${PORTSDIR}/graphics/png \
		libxml2.so:${PORTSDIR}/textproc/libxml2 \
		libpangocairo-1.0.so:${PORTSDIR}/x11-toolkits/pango

CONFLICTS=	rrdtool-1.0* rrdtool-1.2*

USE_RC_SUBR=	rrdcached
USE_AUTOTOOLS=	libtool
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
USES=		gmake pkgconfig
USE_GNOME=	gnomehack intltool

CONFIGURE_ARGS=	--disable-tcl

PORTDOCS=	*
PORTEXAMPLES=	4charts.pl bigtops.pl cgi-demo.cgi minmax.pl perftest.pl \
		piped-demo.pl shared-demo.pl stripes.pl

OPTIONS_DEFINE=	DEJAVU JSON MMAP PERL_MODULE PYTHON_MODULE RUBY_MODULE EXAMPLES DOCS
OPTIONS_DEFAULT=	MMAP PERL_MODULE
DEJAVU_DESC=		Use DejaVu fonts (requires X11)
JSON_DESC=		Support of json export
MMAP_DESC=		Use mmap in rrd_update
PERL_MODULE_DESC=	Build PERL module
PYTHON_MODULE_DESC=	Build PYTHON bindings
RUBY_MODULE_DESC=	Build RUBY bindings

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MPYTHON_MODULE}
USE_PYTHON=	yes
INSTALLS_EGGINFO=yes
PYDISTUTILS_EGGINFO=py_rrdtool-0.2.1-${PYTHON_VERSION:S/thon//}.egg-info
.include "${PORTSDIR}/Mk/bsd.python.mk"
PLIST_SUB+=	WITH_PYTHON=""
CONFIGURE_ARGS+=	--enable-python
.else
CONFIGURE_ARGS+=	--disable-python
PLIST_SUB+=	WITH_PYTHON="@comment "
.endif

.if ${PORT_OPTIONS:MRUBY_MODULE}
USE_RUBY=	yes
.include "${PORTSDIR}/Mk/bsd.ruby.mk"
PLIST_SUB+=	WITH_RUBY=""
CONFIGURE_ARGS+=	--enable-ruby
.else
CONFIGURE_ARGS+=	--disable-ruby
PLIST_SUB+=	WITH_RUBY="@comment "
.endif

.if ${PORT_OPTIONS:MPERL_MODULE}
USES+=		perl5
CONFIGURE_ARGS+=	--enable-perl --enable-perl-site-install
PLIST_SUB+=	WITH_PERL=""
.else
CONFIGURE_ARGS+=	--disable-perl
PLIST_SUB+=	WITH_PERL="@comment "
.endif

.if ! ${PORT_OPTIONS:MMMAP}
CONFIGURE_ARGS+=	--disable-mmap
.endif

.if ${PORT_OPTIONS:MJSON}
EXTRA_PATCHES+=		${FILESDIR}/thirdparty-json.diff
.endif

.if exists(${LOCALBASE}/lib/X11/fonts/dejavu) || ${PORT_OPTIONS:MDEJAVU}
RUN_DEPENDS+=	${LOCALBASE}/lib/X11/fonts/dejavu:${PORTSDIR}/x11-fonts/dejavu
.endif

CPPFLAGS+=	-I${LOCALBASE}/include -I${LOCALBASE}/include/freetype2
##LDFLAGS+=	-L${LOCALBASE}/lib
CFLAGS:=	${CFLAGS:N-ffast-math}

post-extract:
	@${REINPLACE_CMD} -e 's/^POD3/#POD3/' ${WRKSRC}/doc/Makefile.in
.if ! ${PORT_OPTIONS:MDOCS}
	@${REINPLACE_CMD} -e 's/[[:space:]]install-idocDATA//g' \
		-e 's/[[:space:]]install-ihtmlDATA//g' \
		-e 's/^[[:space:]].*cd .* rrdtool.html index.html/	#/' \
		${WRKSRC}/doc/Makefile.in
.endif
.if ! ${PORT_OPTIONS:MEXAMPLES}
	${REINPLACE_CMD} -e '/^SUBDIRS = /s| examples | |' \
		${WRKSRC}/Makefile.in
.endif

post-install:
.if !defined(BATCH) && ${PORT_OPTIONS:MEXAMPLES}
	@${ECHO_MSG} ""
	@${ECHO_MSG} "############################################################################"
	@${ECHO_MSG} "# See ${EXAMPLESDIR} for some demonstration code        #"
	@${ECHO_MSG} "############################################################################"
.endif

.include <bsd.port.mk>
