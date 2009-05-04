# New ports collection makefile for:	rrdtool
# Date created:				20 July 1999
# Whom:					Dmitry Sivachenko <dima@Chg.RU>
#
# $FreeBSD$
#

PORTNAME=	rrdtool
PORTVERSION=	1.3.7
CATEGORIES=	databases graphics
MASTER_SITES=	http://oss.oetiker.ch/rrdtool/pub/

MAINTAINER=	bg1tpt@gmail.com
COMMENT=	Round Robin Database Tools

LIB_DEPENDS=	freetype.9:${PORTSDIR}/print/freetype2 \
		cairo.2:${PORTSDIR}/graphics/cairo \
		png.5:${PORTSDIR}/graphics/png \
		xml2.5:${PORTSDIR}/textproc/libxml2 \
		pangocairo-1\.0.0:${PORTSDIR}/x11-toolkits/pango

CONFLICTS=	rrdtool-1.0*

USE_AUTOTOOLS=	libtool:15
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
WANT_PERL=	yes
USE_GNOME=	gnomehack

CONFIGURE_ARGS=	--disable-tcl

PORTDOCS=	*
PORTEXAMPLES=	4charts.pl bigtops.pl cgi-demo.cgi minmax.pl piped-demo.pl \
		perftest.pl shared-demo.pl stripes.pl

OPTIONS=	PYTHON_MODULE	"Build PYTHON bindings" off \
		RUBY_MODULE	"Build RUBY bindings" off \
		PERL_MODULE	"Build PERL module" on \
		DEJAVU		"Use DejaVu fonts (requires X11)" off \
		MMAP		"Use mmap in rrd_update" on

.include <bsd.port.pre.mk>

.if defined(WITH_PYTHON_MODULE)
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

.if defined(WITH_RUBY_MODULE)
USE_RUBY=	yes
.include "${PORTSDIR}/Mk/bsd.ruby.mk"
PLIST_SUB+=	WITH_RUBY=""
CONFIGURE_ARGS+=	--enable-ruby
.else
CONFIGURE_ARGS+=	--disable-ruby
PLIST_SUB+=	WITH_RUBY="@comment "
.endif

.if !defined(WITHOUT_PERL_MODULE)
USE_PERL5=	yes
CONFIGURE_ARGS+=	--enable-perl --enable-perl-site-install
PLIST_SUB+=	WITH_PERL=""
.else
CONFIGURE_ARGS+=	--disable-perl
PLIST_SUB+=	WITH_PERL="@comment "
.endif

.if defined(WITHOUT_MMAP)
CONFIGURE_ARGS+=	--disable-mmap
.endif

.if exists(${LOCALBASE}/lib/X11/fonts/dejavu) || defined(WITH_DEJAVU)
RUN_DEPENDS=	${LOCALBASE}/lib/X11/fonts/dejavu:${PORTSDIR}/x11-fonts/dejavu
.endif

CPPFLAGS+=	-I${LOCALBASE}/include -I${LOCALBASE}/include/freetype2
LDFLAGS+=	-L${LOCALBASE}/lib
CFLAGS:=	${CFLAGS:N-ffast-math}
CONFIGURE_ENV+=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"

MAN1=		bin_dec_hex.1 cdeftutorial.1 rpntutorial.1 rrd-beginners.1 \
		rrdbuild.1 rrdcgi.1 rrdcreate.1 rrddump.1 rrdfetch.1 rrdfirst.1 \
		rrdgraph.1 rrdgraph_data.1 rrdgraph_examples.1 rrdgraph_graph.1 \
		rrdgraph_rpn.1 rrdinfo.1 rrdlast.1 rrdresize.1 rrdrestore.1 \
		rrdthreads.1 rrdtool.1 rrdtune.1 rrdtutorial.1 rrdupdate.1 \
		rrdxport.1 rrdlastupdate.1

.if !defined(WITHOUT_PERL_MODULE)
MAN3=		RRDp.3 RRDs.3
MAN3PREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}
.endif

post-extract:
.if defined(NOPORTDOCS)
	@${REINPLACE_CMD} -e 's/install-idocDATA install-ihtmlDATA//g' \
		-e 's/^	cd .* rrdtool.html index.html/	#/' \
		${WRKSRC}/doc/Makefile.in
.endif
.if defined(NOPORTEXAMPLES)
	@${REINPLACE_CMD} -e 's|SUBDIRS = $$(PO) src examples doc bindings|SUBDIRS = $$(PO) src doc bindings|' \
		${WRKSRC}/Makefile.in
.endif

post-install:
.if !defined(BATCH)
	@${ECHO_MSG} ""
	@${ECHO_MSG} "############################################################################"
	@${ECHO_MSG} "# See ${PREFIX}/share/examples/rrdtool for some demonstration code        #"
	@${ECHO_MSG} "############################################################################"
.endif

.include <bsd.port.post.mk>
