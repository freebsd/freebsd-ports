# $FreeBSD$

PORTNAME=	cpptest
PORTVERSION=	2.0.0
CATEGORIES=	devel

MAINTAINER=	fernape@FreeBSD.org
COMMENT=	Unit testing framework for handling automated tests in C++

LICENSE=	LGPL3

USES=		autoreconf compiler:c++11-lang gmake libtool pathfix
USE_GITHUB=	yes
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
MAKE_ARGS=	CC=${CC} CCC=${CXX}

.include <bsd.port.mk>
