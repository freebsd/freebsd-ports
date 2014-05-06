# Created by: Koop Mast <kwm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	vsqlite
PORTVERSION=	0.3.12
PORTREVISION=	3
CATEGORIES=	databases

MAINTAINER=	kwm@FreeBSD.org
COMMENT=	Well designed and portable SQLite3 Wrapper for C++

LICENSE=	BSD3CLAUSE

LIB_DEPENDS=	libboost_random.so:${PORTSDIR}/devel/boost-libs

USE_GITHUB=	yes
GH_ACCOUNT=	vinzenz
GH_PROJECT=	vsqlite--
GH_TAGNAME=	3fa8d32
GH_COMMIT=	3fa8d32

USES=		compiler:c++0x libtool
USE_AUTOTOOLS=	libtoolize aclocal autoconf automake
AUTOMAKE_ARGS=	-a -c -f
USE_SQLITE=	3
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.mk>
