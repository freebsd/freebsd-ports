# New ports collection makefile for:	hamlib
# Date created:			30 April 2003
# Whom:				Sebastian Yepes <esn@x123.info>
#
# $FreeBSD$
#

PORTNAME=	hamlib
PORTVERSION=	1.1.4
PORTREVISION=	1
CATEGORIES=	comms
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	esn@x123.info
COMMENT=	Shared libraries for Amateur Radio Equipment Control Applications

USE_PERL5=	yes
USE_LIBTOOL=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" LIBS="-L${LOCALBASE}/lib"

MAN1=		rigctl.1 rotctl.1
MAN8=		rpc.rigd.8 rpc.rotd.8

.include <bsd.port.pre.mk>

.if defined(WITH_TCL)
LIB_DEPENDS=	tcl83.1:${PORTSDIR}/lang/tcl83
CONFIGURE_ARGS+=	--with-tcl=${LOCALBASE}/lib/tcl8.3
PLIST_SUB+=	TCL=""
.else
CONFIGURE_ARGS+=	--without-with-tcl --without-with-tcl-binding
PLIST_SUB+=	TCL="@comment "
.endif

.if defined(WITH_RIGMATRIX)
LIB_DEPENDS=	gd.4:${PORTSDIR}/graphics/gd
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
CONFIGURE_ARGS+=	--without-with-gnuradio
PLIST_SUB+=	GNURADIO="@comment "
.endif

.if defined(WITH_MICROTUNE)
CONFIGURE_ARGS+=	--with-microtune
PLIST_SUB+=	MICROTUNE=""
.else
CONFIGURE_ARGS+=	--without-with-microtune
PLIST_SUB+=	MICROTUNE="@comment "
.endif

pre-everything::
.if !defined(WITH_TCL) || !defined(WITH_RIGMATRIX)
	@${ECHO_MSG} "You can specify the following command lines:"
	@${ECHO_MSG} ""
.endif
.if !defined(WITH_TCL)
	@${ECHO_MSG} "WITH_TCL=yes for TCL support"
.endif
.if !defined(WITH_RIGMATRIX)
	@${ECHO_MSG} "WITH_RIGMATRIX=yes for RigMatrix support"
.endif
#.if !defined(WITH_GNURADIO)
#	@${ECHO_MSG} "WITH_GNURADIO=yes for GNURadio support"
#.endif
#.if !defined(WITH_MICROTUNE)
#	@${ECHO_MSG} "WITH_MICROTUNE=yes for MicroTune support"
#.endif

.include <bsd.port.post.mk>
