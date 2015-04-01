# Created by: Koop Mast <kwm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	vsqlite
PORTVERSION=	0.3.13
CATEGORIES=	databases

MAINTAINER=	kwm@FreeBSD.org
COMMENT=	Well designed and portable SQLite3 Wrapper for C++

LICENSE=	BSD3CLAUSE

LIB_DEPENDS=	libboost_random.so:${PORTSDIR}/devel/boost-libs

USE_GITHUB=	yes
GH_ACCOUNT=	vinzenz
GH_PROJECT=	vsqlite--
GH_TAGNAME=	1bc5a98
GH_COMMIT=	1bc5a98

USES=		autoreconf compiler:c++0x libtool
GNU_CONFIGURE=	yes
USE_SQLITE=	3
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.mk>
