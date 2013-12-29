# Created by: Koop Mast <kwm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	vsqlite
PORTVERSION=	0.3.12
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

USE_AUTOTOOLS=	libtool autoconf automake
USE_SQLITE=	3
USE_LDCONFIG=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

pre-configure:
	@cd ${WRKSRC} && ${SH} autogen.sh

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libvsqlitepp.so.3

.include <bsd.port.mk>
