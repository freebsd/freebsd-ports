# New ports collection makefile for:	hamlib
# Date created:			30 April 2003
# Whom:				Sebastian Yepes <esn@x123.info>
#
# $FreeBSD$
#

PORTNAME=	hamlib
PORTVERSION=	1.2.2
CATEGORIES=	comms
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	esn@x123.info
COMMENT=	Shared libraries for Amateur Radio Equipment Control Applications

USE_PERL5=	yes
USE_INC_LIBTOOL_VER=	15
USE_GNOME=	pkgconfig gnomehack
INSTALLS_SHLIB=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" LIBS="-L${LOCALBASE}/lib"

MAN1=		rigctl.1 rigmem.1 rigswr.1 rotctl.1
MAN8=		rpc.rigd.8 rpc.rotd.8

.if defined(WITH_PYTHON)
USE_PYTHON=	yes
.endif

.include <bsd.port.pre.mk>

.if defined(WITH_XML)
USE_GNOME+=	libxml2
PLIST_SUB+=	XML=""
.else
CONFIGURE_ARGS+=	--disable-xmltest
PLIST_SUB+=	XML="@comment "
.endif

.if defined(WITH_TCL)
LIB_DEPENDS+=	tcl84.1:${PORTSDIR}/lang/tcl84
CONFIGURE_ARGS+=	--with-tcl=${LOCALBASE}/lib/tcl8.4 --with-tcl-binding
PLIST_SUB+=	TCL=""
.else
CONFIGURE_ARGS+=	--without-tcl-binding
PLIST_SUB+=	TCL="@comment "
.endif

.if defined(WITH_PYTHON)
BUILD_DEPENDS+=		swig1.3:${PORTSDIR}/devel/swig13
CONFIGURE_ARGS+=	--with-python-binding
PLIST_SUB+=	PYTHON=""
.else
CONFIGURE_ARGS+=	--without-python-binding
PLIST_SUB+=	PYTHON="@comment "
.endif

.if defined(WITH_RIGMATRIX)
LIB_DEPENDS+=	gd.4:${PORTSDIR}/graphics/gd
CONFIGURE_ARGS+=	--with-rigmatrix
PLIST_SUB+=	RIGMATRIX=""
.else
CONFIGURE_ARGS+=	--without-with-rigmatrix
PLIST_SUB+=	RIGMATRIX="@comment "
.endif

.if defined(WITH_GNURADIO)
CONFIGURE_ARGS+=	--with-gnuradio
PLIST_SUB+=	GNURADIO=""
.else
CONFIGURE_ARGS+=	--without-gnuradio
LIST_SUB+=	GNURADIO="@comment "
.endif

pre-everything::
.if !defined(WITH_TCL) || !defined(WITH_PYTHON) || !defined(WITH_RIGMATRIX)
	@${ECHO_MSG} "You can specify the following command lines:"
	@${ECHO_MSG} ""
.endif
.if !defined(WITH_XML)
	@${ECHO_MSG} "WITH_XML=yes		for XML support"
.endif
.if !defined(WITH_TCL)
	@${ECHO_MSG} "WITH_TCL=yes		for TCL Binding support"
.endif
.if !defined(WITH_PYTHON)
	@${ECHO_MSG} "WITH_PYTHON=yes		for PYTHON Binding support"
.endif
.if !defined(WITH_RIGMATRIX)
	@${ECHO_MSG} "WITH_RIGMATRIX=yes	for RigMatrix support"
.endif
#.if !defined(WITH_GNURADIO)
#	@${ECHO_MSG} "WITH_GNURADIO=yes		for GNURadio support"
#.endif
	@${ECHO_MSG} ""

.include <bsd.port.post.mk>
