PORTNAME=	vsqlite
PORTVERSION=	0.3.13
PORTREVISION=	20
CATEGORIES=	databases

MAINTAINER=	kwm@FreeBSD.org
COMMENT=	Well designed and portable SQLite3 Wrapper for C++
WWW=		https://github.com/vinzenz/vsqlite--

LICENSE=	BSD3CLAUSE

DEPRECATED=	Abandonware, last release in 2014 and last commit 4 years ago
EXPIRATION_DATE=2024-11-30

LIB_DEPENDS=	libboost_random.so:devel/boost-libs

USE_GITHUB=	yes
GH_ACCOUNT=	vinzenz
GH_PROJECT=	vsqlite--

USES=		autoreconf compiler:c++0x libtool sqlite:3
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.mk>
