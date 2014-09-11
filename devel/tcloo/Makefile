# Created by: gahr
# $FreeBSD$

PORTNAME=	tcloo
PORTVERSION=	1.0.2
CATEGORIES=	devel
MASTER_SITES=	SF/tcl/TclOO%20Package/${PORTVERSION}/
DISTNAME=	TclOO${PORTVERSION}

MAINTAINER=	tcltk@FreeBSD.org
COMMENT=	Implementation of TclOO for Tcl 8.5

USES+=		tcl:85
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--with-tcl=${TCL_LIBDIR} \
		--exec-prefix=${PREFIX}

PLIST_SUB+=	PORTVERSION=${PORTVERSION}

.include <bsd.port.mk>
