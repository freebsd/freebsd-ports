PORTNAME=	freehdl
PORTVERSION=	0.0.8
PORTREVISION=	1
CATEGORIES=	cad
MASTER_SITES=	SF/qucs/qucs/0.0.16/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Free VHDL simulator
WWW=		http://www.freehdl.seul.org/

LICENSE=	GPLv2

RUN_DEPENDS=	guile:lang/guile

USES=		gmake libtool makeinfo perl5 pkgconfig
# Bug 219297: GCC 6 changed its default from -std=gnu++98 to -std=gnu++14, and
# this port's code is not compatible with C++11. Since the project looks
# abandoned upstream, it makes more sense to just continue building with an
# older C++ standard.
USE_CXXSTD=	gnu++98
USE_GCC=	yes
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
CONFIGURE_ARGS=	SYSTEM_LIBTOOL=${FALSE}

INSTALL_TARGET=	install-strip

INFO=		fire

.include <bsd.port.mk>
