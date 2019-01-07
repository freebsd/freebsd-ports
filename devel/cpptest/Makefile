# $FreeBSD$

PORTNAME=	cpptest
PORTVERSION=	2.0.0
CATEGORIES=	devel

MAINTAINER=	fernape@FreeBSD.org
COMMENT=	Unit testing framework for handling automated tests in C++

LICENSE=	LGPL3

USES=		autoreconf gmake libtool pathfix
USE_GITHUB=	yes
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
MAKE_ARGS=	CC=${CC} CCC=${CXX}

#pre-configure:
#	@cd ${WRKSRC} && ./autogen.sh

.include <bsd.port.mk>
