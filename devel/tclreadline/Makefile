# New ports collection makefile for:	tclreadline
# Version required:	1.0
# Date created:		21 September 1999
# Whom:			darius@dons.net.au
#
# $FreeBSD$
#

DISTNAME=	tclreadline-1.0.0
CATEGORIES=	tcl80 tcl82
MASTER_SITES=	http://www.zellner.org/tclreadline/download/

MAINTAINER=	darius@dons.net.au

GNU_CONFIGURE=	yes
MANN=		tclreadline.n

.include <bsd.port.pre.mk>

.if (!exists(${PREFIX}/bin/tclsh8.2) || exists(${PREFIX}/bin/tclsh8.0)) && (defined(FORCE_80))
LIB_DEPENDS=	tcl80.1:${PORTSDIR}/lang/tcl80
CONFIGURE_ARGS=	--with-tcl=${PREFIX}/lib/tcl8.0/ --with-tcl-includes=${PREFIX}/include/tcl8.0
TCLVERMSG=	"Building for Tcl 8.0"
.else
LIB_DEPENDS=	tcl82.1:${PORTSDIR}/lang/tcl82
CONFIGURE_ARGS=	--with-tcl=${PREFIX}/lib/tcl8.2/ --with-tcl-includes=${PREFIX}/include/tcl8.2
TCLVERMSG=	"Building for Tcl 8.2 define FORCE_80 to build for Tcl 8.0"
.endif

pre-fetch:
	@${ECHO} ${TCLVERMSG}

.include <bsd.port.post.mk>
