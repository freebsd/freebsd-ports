# Created by: lon_kamikaze@gmx.de
# $FreeBSD$

PORTNAME=	freehdl
PORTVERSION=	0.0.7
PORTREVISION=	4
CATEGORIES=	cad
MASTER_SITES=	http://freehdl.seul.org/~enaroska/

MAINTAINER=	kamikaze@bsdforen.de
COMMENT=	Free VHDL simulator

USES=		gmake pathfix libtool makeinfo perl5 pkgconfig
USE_LDCONFIG=	yes
USE_GCC=	any
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	SYSTEM_LIBTOOL=${FALSE}
INSTALL_TARGET=	install-strip

# Bug 219297: GCC 6 changed its default from -std=gnu++03 to -std=gnu++14, and
# this port's code is not compatible with C++11. Since the project looks
# abandoned upstream, it makes more sense to just continue building with an
# older C++ standard.
USE_CXXSTD=	gnu++03

INFO=		fire

.include <bsd.port.mk>
