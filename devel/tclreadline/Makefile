# New ports collection makefile for:	tclreadline
# Date created:		21 September 1999
# Whom:			darius@dons.net.au
#
# $FreeBSD$
#

PORTNAME=	tclreadline
PORTVERSION=	2.1.0
PORTREVISION=	2
CATEGORIES=	devel tcl
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	tclreadline

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GNU readline for TCL

USE_TCL=	80+
USE_AUTOTOOLS=	libtool:15
GNU_CONFIGURE=	yes
INSTALLS_SHLIB=	yes
MANN=		tclreadline.n

PLIST_SUB+=	VERSION="${PORTVERSION}"

CONFIGURE_ARGS=	--with-tcl=${TCL_LIBDIR} --with-tcl-includes=${TCL_INCLUDEDIR}

.include <bsd.port.mk>
