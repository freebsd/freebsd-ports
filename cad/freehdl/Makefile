PORTNAME=	freehdl
PORTVERSION=	0.0.7
PORTREVISION=	10
CATEGORIES=	cad
MASTER_SITES=	http://freehdl.seul.org/~enaroska/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Free VHDL simulator
WWW=		http://www.freehdl.seul.org/

DEPRECATED=	Upstream vaporized and SF site do not have dists anymore
EXPIRATION_DATE=	2023-11-21

USES=		gmake pathfix libtool makeinfo perl5 pkgconfig
# Bug 219297: GCC 6 changed its default from -std=gnu++98 to -std=gnu++14, and
# this port's code is not compatible with C++11. Since the project looks
# abandoned upstream, it makes more sense to just continue building with an
# older C++ standard.
USE_CXXSTD=	gnu++98
USE_GCC=	yes
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	SYSTEM_LIBTOOL=${FALSE}

INSTALL_TARGET=	install-strip

INFO=		fire

.include <bsd.port.mk>
