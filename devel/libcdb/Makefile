# $FreeBSD$

PORTNAME=	libcdb
PORTVERSION=	g2019052401
CATEGORIES=	devel

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Constant database library

USES=		compiler:c11 gmake libtool:build

USE_GITHUB=	yes
GH_ACCOUNT=	rmind
GH_PROJECT=	libcdb
GH_TAGNAME=	1d3440d
WRKSRC_SUBDIR=	src
USE_LDCONFIG=	yes
MAKE_ENV=	DESTDIR=${STAGEDIR}${PREFIX} \
		INCDIR=${LOCALBASE}/include \
		LIBDIR=${LOCALBASE}/lib

.include <bsd.port.mk>
