# New ports collection makefile for:	lmdbg
# Date created:				14 March 2009
# Whom:					Mikolaj Golub <to.my.trociny@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	lmdbg
PORTVERSION=	0.11.0
CATEGORIES=	devel
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	to.my.trociny@gmail.com
COMMENT=	Lightweight malloc debugger

BUILD_DEPENDS=	${LOCALBASE}/share/mk/_mkc.ver.mk:${PORTSDIR}/devel/mk-configure

MAN1=		lmdbg-run.1 lmdbg-leaks.1 lmdbg-sysleaks.1 lmdbg-sym.1 lmdbg.1

do-build:
	bmake -C ${WRKSRC}

do-install:
	bmake -C ${WRKSRC} install-dirs install

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/README    ${DOCSDIR}
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/NEWS      ${DOCSDIR}
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/ChangeLog ${DOCSDIR}
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/TODO      ${DOCSDIR}
.endif

.include <bsd.port.mk>
