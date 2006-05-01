# New ports collection makefile for:	hamlib
# Date created:			30 April 2003
# Whom:				Sebastian Yepes <esn@x123.info>
#
# $FreeBSD$
#

PORTNAME=	hamlib
PORTVERSION=	1.2.5
CATEGORIES=	comms hamradio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	db@db.net
COMMENT=	Shared libraries for Amateur Radio Equipment Control Applications

BUILD_DEPENDS=	swig:${PORTSDIR}/devel/swig13

USE_GNOME=	pkgconfig gnomehack
USE_GETOPT_LONG=	yes
USE_PERL5=	yes
USE_PYTHON=	yes
USE_AUTOTOOLS=	autoconf:259 libtool:15
INSTALLS_SHLIB=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" LIBS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--with-perl-binding --with-python=${PYTHON_CMD}
PLIST_SUB=	VER=${PORTVERSION}

MAN1=		rigctl.1 rigmem.1 rigswr.1 rotctl.1
MAN8=		rpc.rigd.8 rpc.rotd.8

OPTIONS	=	PYTHON	"Define if you want PYTHON bindings" OFF \
		TCL	"Define if you want TCL bindings" OFF \
		XML	"Define if you want XML" OFF \
		RIGMATRIX	"Define if you want rigmatrix support" OFF

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
IGNORE=		required Perl 5.6 or newer. Install lang/perl5.8 or lang/perl5 and try again
.endif

.if defined(WITH_XML)
USE_GNOME+=		libxml2
PLIST_SUB+=		XML=""
.else
CONFIGURE_ARGS+=	--disable-xmltest
PLIST_SUB+=		XML="@comment "
.endif

.if defined(WITH_TCL)
LIB_DEPENDS+=		tcl84.1:${PORTSDIR}/lang/tcl84
CONFIGURE_ARGS+=	--with-tcl=${LOCALBASE}/lib/tcl8.4 --with-tcl-binding
PLIST_SUB+=		TCL=""
.else
CONFIGURE_ARGS+=	--without-tcl-binding
PLIST_SUB+=		TCL="@comment "
.endif

.if defined(WITH_PYTHON)
CONFIGURE_ARGS+=	--with-python-binding
PLIST_SUB+=		PYTHON=""
.else
CONFIGURE_ARGS+=	--without-python-binding
PLIST_SUB+=		PYTHON="@comment "
.endif

.if defined(WITH_RIGMATRIX)
LIB_DEPENDS+=		gd.4:${PORTSDIR}/graphics/gd
CONFIGURE_ARGS+=	--with-rigmatrix
PLIST_SUB+=		RIGMATRIX=""
.else
CONFIGURE_ARGS+=	--without-with-rigmatrix
PLIST_SUB+=		RIGMATRIX="@comment "
.endif

.if defined(WITH_GNURADIO)
CONFIGURE_ARGS+=	--with-gnuradio
PLIST_SUB+=		GNURADIO=""
.else
CONFIGURE_ARGS+=	--without-gnuradio
PLIST_SUB+=		GNURADIO="@comment "
.endif

.if defined(WITH_TCL) && defined(WITH_PYTHON)
PLIST_SUB+=		PYTHON_TCL=""
.else
PLIST_SUB+=		PYTHON_TCL="@comment "
.endif

pre-everything::
	@${MAKE} showconfig
	@${ECHO_MSG} "Use make config to set or unset above options"
	@${ECHO_MSG} ""

post-build:
	${PERL5} -pi -e 's/ doc_(perl|site|\$$\(INSTALLDIRS\))_install$$//' \
		${WRKSRC}/bindings/Hamlib-pl.mk

.include <bsd.port.post.mk>
