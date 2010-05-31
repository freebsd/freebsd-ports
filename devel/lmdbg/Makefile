# New ports collection makefile for:	lmdbg
# Date created:				14 March 2009
# Whom:					Mikolaj Golub <to.my.trociny@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	lmdbg
PORTVERSION=	0.15.0
CATEGORIES=	devel
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	to.my.trociny@gmail.com
COMMENT=	Lightweight malloc debugger

BUILD_DEPENDS=	mk-configure>=0.15.1:${PORTSDIR}/devel/mk-configure
RUN_DEPENDS=	runawk:${PORTSDIR}/devel/runawk

USE_LDCONFIG=	yes

MAN1=		lmdbg-run.1 lmdbg-leaks.1 lmdbg-sysleaks.1 lmdbg-sym.1 lmdbg.1 \
		lmdbg-stat.1 lmdbg-grep.1 lmdbg-sort.1

do-build:
	mkcmake -C ${WRKSRC}

do-install:
	mkcmake -C ${WRKSRC} installdirs install

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/README    ${DOCSDIR}
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/NEWS      ${DOCSDIR}
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/ChangeLog ${DOCSDIR}
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/TODO      ${DOCSDIR}
.endif

.include <bsd.port.mk>
