# Created by: lev@FreeBSD.org
# $FreeBSD$

PORTNAME=	py3c
PORTVERSION=	1.0
CATEGORIES=	devel

MAINTAINER=	lev@FreeBSD.org
COMMENT=	Py3c helps you port C extensions to Python 3

LICENSE=	MIT

USES=		gmake

USE_GITHUB=	yes
GH_ACCOUNT=	encukou
GH_TAGNAME=	v${PORTVERSION}

NO_BUILD=	yes

do-install:
	@${MAKE_CMD}                              \
	 prefix=${PREFIX}                         \
	 pkgconfigdir=${PREFIX}/libdata/pkgconfig \
	 DESTDIR=${STAGEDIR}                      \
	 -C ${WRKSRC}                             \
	 install

.include <bsd.port.mk>
