# $FreeBSD$

PORTNAME=	libcdb
PORTVERSION=	g2020082801
CATEGORIES=	devel

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Constant database library

USES=		compiler:c11 gmake libtool:build

USE_GITHUB=	yes
GH_ACCOUNT=	rmind
GH_PROJECT=	libcdb
GH_TAGNAME=	a187cec
WRKSRC_SUBDIR=	src
USE_LDCONFIG=	yes
MAKE_ENV=	DESTDIR=${STAGEDIR}${PREFIX} \
		INCDIR=${LOCALBASE}/include \
		LIBDIR=${LOCALBASE}/lib

.include <bsd.port.mk>
