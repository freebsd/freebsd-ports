# New ports collection makefile for:	tclreadline
# Date created:		21 September 1999
# Whom:			darius@dons.net.au
#
# $FreeBSD$
#

PORTNAME=	tclreadline
PORTVERSION=	2.1.0
CATEGORIES=	devel tcl80 tcl82
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	tclreadline

MAINTAINER=	darius@dons.net.au
COMMENT=	GNU readline for TCL

USE_INC_LIBTOOL_VER=	13
INSTALLS_SHLIB=	yes
MANN=		tclreadline.n

PLIST_SUB+=	VERSION="${PORTVERSION}"

.include <bsd.port.pre.mk>

.if (!defined(WITH_TCL80) && !defined(WITH_TCL82))
.if exists(${PREFIX}/bin/tclsh8.0)
WITH_TCL80=	yes
.else
WITH_TCL82=	yes
.endif
.endif

.if defined(WITH_TCL80)
LIB_DEPENDS=	tcl80.1:${PORTSDIR}/lang/tcl80
CONFIGURE_ARGS=	--with-tcl=${PREFIX}/lib/tcl8.0 --with-tcl-includes=${PREFIX}/include/tcl8.0
TCLVERMSG=	"Building for Tcl 8.0"
.endif

.if defined(WITH_TCL82)
LIB_DEPENDS=	tcl82.1:${PORTSDIR}/lang/tcl82
CONFIGURE_ARGS=	--with-tcl=${PREFIX}/lib/tcl8.2 --with-tcl-includes=${PREFIX}/include/tcl8.2
TCLVERMSG=	"Building for Tcl 8.2"
.endif

pre-fetch:
	@${ECHO} ${TCLVERMSG}
	@${ECHO} "Define WITH_TCL80, or WITH_TCL82"
	@${ECHO} "To compile against a different version of TCL"

.include <bsd.port.post.mk>
