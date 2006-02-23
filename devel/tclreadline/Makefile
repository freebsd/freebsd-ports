# New ports collection makefile for:	tclreadline
# Date created:		21 September 1999
# Whom:			darius@dons.net.au
#
# $FreeBSD$
#

PORTNAME=	tclreadline
PORTVERSION=	2.1.0
PORTREVISION=	1
CATEGORIES=	devel tcl80 tcl82 tcl83 tcl84
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	tclreadline

MAINTAINER=	darius@dons.net.au
COMMENT=	GNU readline for TCL

GNU_CONFIGURE=	yes
INSTALLS_SHLIB=	yes
MANN=		tclreadline.n

PLIST_SUB+=	VERSION="${PORTVERSION}"

.include <bsd.port.pre.mk>

# Try and guess what version of Tcl to build against
.if (!defined(WITH_TCL80) && !defined(WITH_TCL82) && !defined(WITH_TCL83) && !defined(WITH_TCL84))
.if exists(${LOCALBASE}/bin/tclsh8.4)
WITH_TCL84=	yes
.else
.if exists(${LOCALBASE}/bin/tclsh8.3)
WITH_TCL83=	yes
.else
.if exists(${LOCALBASE}/bin/tclsh8.2)
WITH_TCL82=	yes
.else
.if exists(${LOCALBASE}/bin/tclsh8.0)
WITH_TCL80=	yes
.else
WITH_TCL84=	yes
.endif
.endif
.endif
.endif
.endif

.if defined(WITH_TCL80)
LIB_DEPENDS=  tcl80.1:${PORTSDIR}/lang/tcl80
CONFIGURE_ARGS=       --with-tcl=${LOCALBASE}/lib/tcl8.0 --with-tcl-includes=${LOCALBASE}/include/tcl8.0
TCLVERMSG=    "Building for Tcl 8.0"
.endif

.if defined(WITH_TCL82)
LIB_DEPENDS=  tcl82.1:${PORTSDIR}/lang/tcl82
CONFIGURE_ARGS=       --with-tcl=${LOCALBASE}/lib/tcl8.2 --with-tcl-includes=${LOCALBASE}/include/tcl8.2
TCLVERMSG=    "Building for Tcl 8.2"
.endif

.if defined(WITH_TCL83)
LIB_DEPENDS=  tcl83.1:${PORTSDIR}/lang/tcl83
CONFIGURE_ARGS=       --with-tcl=${LOCALBASE}/lib/tcl8.3 --with-tcl-includes=${LOCALBASE}/include/tcl8.3
TCLVERMSG=    "Building for Tcl 8.3"
.endif

.if defined(WITH_TCL84)
LIB_DEPENDS=  tcl84.1:${PORTSDIR}/lang/tcl84
CONFIGURE_ARGS=       --with-tcl=${LOCALBASE}/lib/tcl8.4 --with-tcl-includes=${LOCALBASE}/include/tcl8.4
TCLVERMSG=    "Building for Tcl 8.4"
.endif

pre-fetch:
	@${ECHO} ${TCLVERMSG}
	@${ECHO} "Define WITH_TCL80, WITH_TCL82, WITH_TCL83, or WITH_TCL84"
	@${ECHO} "To compile against a different version of TCL"

.include <bsd.port.post.mk>
