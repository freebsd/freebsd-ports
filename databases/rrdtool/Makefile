# Created by: Dmitry Sivachenko <dima@Chg.RU>
# $FreeBSD$

PORTNAME=	rrdtool
PORTVERSION=	1.7.0
PORTREVISION=	1
CATEGORIES=	databases graphics
MASTER_SITES=	http://oss.oetiker.ch/rrdtool/pub/

MAINTAINER=	zeising@FreeBSD.org
COMMENT=	Round Robin Database Tools

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

CONFLICTS=	rrdtool12-*

CONFIGURE_ARGS=	--disable-tcl
CPPFLAGS+=	-I${LOCALBASE}/include -I${LOCALBASE}/include/freetype2
USE_RC_SUBR=	rrdcached
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
USES=		gmake groff libtool pathfix pkgconfig shebangfix
USE_GNOME=	glib20 libxml2
INSTALL_TARGET=	install-strip

PORTEXAMPLES=	cgi-demo.cgi

OPTIONS_DEFINE=	DEJAVU GRAPH MMAP NLS PERL PYTHON \
		RUBY EXAMPLES DOCS
OPTIONS_DEFAULT=DEJAVU GRAPH MMAP PERL
OPTIONS_SUB=	yes
GRAPH_DESC=	Enable the rrdtool graph command (needs cairo)
DEJAVU_DESC=	Use DejaVu fonts (requires X11)
MMAP_DESC=	Use mmap in rrd_update
PERL_DESC=	Build PERL module
PYTHON_DESC=	Build PYTHON bindings
RUBY_DESC=	Build RUBY bindings

DEJAVU_RUN_DEPENDS=	dejavu>0:x11-fonts/dejavu
GRAPH_CONFIGURE_OFF=	--disable-rrdcgi --disable-rrd_graph
GRAPH_LIB_DEPENDS=	libfreetype.so:print/freetype2 \
			libpng.so:graphics/png
GRAPH_USE=		GNOME=cairo,pango
GRAPH_USES=		gnome
MMAP_CONFIGURE_ENABLE=	mmap
NLS_CONFIGURE_ENABLE=	nls
NLS_USE=		GNOME=intltool
NLS_USES=		gettext
PERL_CONFIGURE_OFF=	--disable-perl
PERL_CONFIGURE_ON=	--enable-perl --enable-perl-site-install
PERL_USES=		perl5
PYTHON_CONFIGURE_ENABLE=python
PYTHON_USES=		python
RUBY_CONFIGURE_ENABLE=	ruby
RUBY_USE=		RUBY=yes

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MPERL}
SHEBANG_FILES=	examples/rrdcached/rrdcached-size.pl
PORTEXAMPLES+=	4charts.pl bigtops.pl minmax.pl perftest.pl \
		piped-demo.pl shared-demo.pl stripes.pl \
		rrdcached/RRDCached.pm rrdcached/rrdcached-size.pl
.endif
.if ${PORT_OPTIONS:MPYTHON}
SHEBANG_FILES+=	examples/stripes.py
PORTEXAMPLES+=	stripes.py
.endif

post-extract:
	@${REINPLACE_CMD} -E 's|(^rrdcached_LDADD = librrd_th.la)|\1 $$\(ALL_LIBS\)|' \
		${WRKSRC}/src/Makefile.in

	@${REINPLACE_CMD} -E 's|(^rrdtool_LDADD = librrd.la)|\1 $$\(ALL_LIBS\)|' \
		${WRKSRC}/src/Makefile.in

post-extract-DOCS-off:
	@${REINPLACE_CMD} -e '/^SUBDIRS = /s| doc | |' \
		${WRKSRC}/Makefile.in

post-extract-EXAMPLES-off:
	@${REINPLACE_CMD} -e '/^SUBDIRS = /s| examples | |' \
		${WRKSRC}/Makefile.in

post-install-EXAMPLES-on:
.if !defined(BATCH)
	@${ECHO_MSG} ""
	@${ECHO_MSG} "############################################################################"
	@${ECHO_MSG} "# See ${EXAMPLESDIR} for some demonstration code        #"
	@${ECHO_MSG} "############################################################################"
.endif

post-install-PERL-on:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/RRDs/RRDs.so

post-install-PERL-off:
	${RM} ${STAGEDIR}${EXAMPLESDIR}/*.pl
	${RM} -r ${STAGEDIR}${EXAMPLESDIR}/rrdcached

post-install-PYTHON-on:
	${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/rrdtool.so

post-install-PYTHON-off:
	${RM} ${STAGEDIR}${EXAMPLESDIR}/stripes.py

post-install-RUBY-on:
	${STRIP_CMD} ${STAGEDIR}${RUBY_SITEARCHLIBDIR}/RRD.so

.include <bsd.port.mk>
