# Created by: gahr
# $FreeBSD$

PORTNAME=	tcloo
PORTVERSION=	1.0
CATEGORIES=	devel
MASTER_SITES=	SF/tcl/TclOO%20Package/${PORTVERSION}/
DISTNAME=	TclOO${PORTVERSION}

MAINTAINER=	tcltk@FreeBSD.org
COMMENT=	Implementation of TclOO for Tcl 8.5

USE_TCL=	85
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--with-tcl=${TCL_LIBDIR} \
		--exec-prefix=${PREFIX}

PLIST_SUB+=	PORTVERSION=${PORTVERSION}

MANN=	class.n \
	copy.n \
	define.n \
	my.n \
	next.n \
	object.n \
	ooInfo.n \
	self.n
MAN3=	Class.3 \
	Method.3 \
	OOInitStubs.3

NO_STAGE=	yes
.include <bsd.port.mk>
