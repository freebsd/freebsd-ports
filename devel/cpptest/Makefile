# $FreeBSD$

PORTNAME=	cpptest
PORTVERSION=	1.1.2
CATEGORIES=	devel
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	fernape@FreeBSD.org
COMMENT=	Unit testing framework for handling automated tests in C++

LICENSE=	LGPL3

GNU_CONFIGURE=	yes
USES=		gmake libtool pathfix
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes
MAKE_ARGS=	CC=${CC} CCC=${CXX}

.include <bsd.port.mk>
