# ex:ts=8
# Ports collection makefile for:	dprog
# Date created:			Apr 6, 2004
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	dprog
PORTVERSION=	0.3.1
CATEGORIES=	devel
MASTER_SITES=	http://www.daimi.au.dk/~mailund/dprog/download/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A language for specifying dynamic programming algorithms

LIB_DEPENDS=	popt.0:${PORTSDIR}/devel/popt

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CXXFLAGS} -I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

PLIST_FILES=	bin/dprog include/cxx_dprog.hh lib/libcxx_dprog.a

.include <bsd.port.mk>
