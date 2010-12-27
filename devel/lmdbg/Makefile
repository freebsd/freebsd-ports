# New ports collection makefile for:	lmdbg
# Date created:				14 March 2009
# Whom:					Mikolaj Golub <to.my.trociny@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	lmdbg
PORTVERSION=	0.16.0
CATEGORIES=	devel
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	to.my.trociny@gmail.com
COMMENT=	Lightweight malloc debugger

BUILD_DEPENDS=	mk-configure>=0.20:${PORTSDIR}/devel/mk-configure
LIB_DEPENDS=	Judy:${PORTSDIR}/devel/judy
RUN_DEPENDS=	runawk:${PORTSDIR}/lang/runawk
USE_LDCONFIG=	yes

LICENSE=	MIT

MKCMAKE?=	${LOCALBASE}/bin/mkcmake
INSTALL_TARGET=	installdirs install

PORTDOCS=	ChangeLog NEWS README TODO

MAN1=		lmdbg-run.1 lmdbg-leaks.1 lmdbg-sysleaks.1 lmdbg-sym.1 lmdbg.1 \
		lmdbg-stat.1 lmdbg-grep.1 lmdbg-sort.1

MKCMAKE_ENV+=	CPPFLAGS=-I${LOCALBASE}/include
MKCMAKE_ENV+=	LDFLAGS=-L${LOCALBASE}/lib

do-build:
	${SETENV} ${MKCMAKE_ENV} ${MKCMAKE} -C ${WRKSRC}

do-install:
	${SETENV} ${MKCMAKE_ENV} ${MKCMAKE} -C ${WRKSRC} ${INSTALL_TARGET}

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for doc in ${PORTDOCS}
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/${doc} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
