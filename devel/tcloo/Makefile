# Created by: gahr
# $FreeBSD$

PORTNAME=	tcloo
PORTVERSION=	1.0.4
CATEGORIES=	devel
MASTER_SITES=	http://core.tcl.tk/tcloo/tarball/
DISTNAME=	TclOO+Package-${FOSSIL_CHECKIN}

MAINTAINER=	tcltk@FreeBSD.org
COMMENT=	Implementation of TclOO for Tcl 8.5

FOSSIL_CHECKIN=	0a6e9f1ea3
WRKSRC=		${WRKDIR}/${DISTNAME:S/+/_/}
USES+=		tcl:85
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--with-tcl=${TCL_LIBDIR} \
		--exec-prefix=${PREFIX}

PLIST_SUB+=	PORTVERSION=${PORTVERSION}

TEST_TARGET=	test

.include <bsd.port.mk>
