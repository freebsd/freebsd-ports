# Created by: Mikolaj Golub <to.my.trociny@gmail.com>
# $FreeBSD$

PORTNAME=	lmdbg
PORTVERSION=	1.2.0
CATEGORIES=	devel
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	trociny@FreeBSD.org
COMMENT=	Lightweight malloc debugger

LICENSE=	MIT

BUILD_DEPENDS=	mk-configure>=0.24:${PORTSDIR}/devel/mk-configure
LIB_DEPENDS=	Judy:${PORTSDIR}/devel/judy
RUN_DEPENDS=	runawk:${PORTSDIR}/lang/runawk \
		${LOCALBASE}/bin/pipestatus:${PORTSDIR}/devel/pipestatus

USE_LDCONFIG=	yes

MKCMAKE?=	${LOCALBASE}/bin/mkcmake

PORTDOCS=	LICENSE NEWS README TODO

MKCMAKE_ENV+=	CPPFLAGS=-I${LOCALBASE}/include
MKCMAKE_ENV+=	LDFLAGS=-L${LOCALBASE}/lib

INSTALL_TARGET=	install install-doc

do-build:
	${SETENV} ${MKCMAKE_ENV} ${MKCMAKE} -C ${WRKSRC}

do-install:
	${SETENV} ${MKCMAKE_ENV} DESTDIR=${STAGEDIR} \
		${MKCMAKE} -C ${WRKSRC} ${INSTALL_TARGET}

.include <bsd.port.mk>
