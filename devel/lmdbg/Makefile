# Created by: Mikolaj Golub <to.my.trociny@gmail.com>
# $FreeBSD$

PORTNAME=	lmdbg
PORTVERSION=	1.1.0
CATEGORIES=	devel
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	trociny@FreeBSD.org
COMMENT=	Lightweight malloc debugger

LICENSE=	MIT

BUILD_DEPENDS=	mk-configure>=0.23:${PORTSDIR}/devel/mk-configure
LIB_DEPENDS=	Judy:${PORTSDIR}/devel/judy
RUN_DEPENDS=	runawk:${PORTSDIR}/lang/runawk \
		${LOCALBASE}/bin/pipestatus:${PORTSDIR}/devel/pipestatus

USE_LDCONFIG=	yes

MKCMAKE?=	${LOCALBASE}/bin/mkcmake

PORTDOCS=	ChangeLog LICENSE NEWS README TODO

MAN1=		lmdbg-run.1 lmdbg-leaks.1 lmdbg-sysleaks.1 lmdbg-sym.1 lmdbg.1 \
		lmdbg-stat.1 lmdbg-grep.1 lmdbg-sort.1

MKCMAKE_ENV+=	CPPFLAGS=-I${LOCALBASE}/include
MKCMAKE_ENV+=	LDFLAGS=-L${LOCALBASE}/lib

INSTALL_TARGET=	install
.if !defined(NOPORTDOCS)
INSTALL_TARGET+=install-doc
.endif

NO_STAGE=	yes
do-build:
	${SETENV} ${MKCMAKE_ENV} ${MKCMAKE} -C ${WRKSRC}

do-install:
	${SETENV} ${MKCMAKE_ENV} ${MKCMAKE} -C ${WRKSRC} ${INSTALL_TARGET}

.include <bsd.port.mk>
