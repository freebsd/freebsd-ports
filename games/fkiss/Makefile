# ports collection makefile for:	fkiss
# Version required:	0.28
# Date created:		31 Oct 1998
# Whom:			Seiichirou Hiraoka
#
# $FreeBSD$
#

DISTNAME=	fkiss028
PKGNAME=	fkiss-0.28
CATEGORIES=	games
MASTER_SITES=	http://www.oersted.co.jp/~yav/soft/fkiss/

MAINTAINER=	flathill@FreeBSD.org

RUN_DEPENDS=	lha:${PORTSDIR}/archivers/lha

NOT_FOR_ARCHS=	alpha

WRKSRC=		${WRKDIR}/fkiss
USE_IMAKE=	yes
MAN1=		fkiss.1

INSTALL_TARGET=	install install.man

post-install:
	${MKDIR} ${PREFIX}/share/examples/fkiss
	${INSTALL_DATA} ${WRKSRC}/frkismi4.lzh ${PREFIX}/share/examples/fkiss
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/ja/fkiss
	${INSTALL_MAN} ${WRKSRC}/fkiss.doc ${PREFIX}/share/doc/ja/fkiss
.endif

.include <bsd.port.mk>
