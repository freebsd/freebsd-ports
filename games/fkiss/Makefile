# ports collection makefile for:	fkiss
# Date created:		31 Oct 1998
# Whom:			Seiichirou Hiraoka
#
# $FreeBSD$
#

PORTNAME=	fkiss
PORTVERSION=	0.32
CATEGORIES=	games
MASTER_SITES=	http://www.oersted.co.jp/~yav/soft/fkiss/
DISTNAME=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Freely enjoy childlike KISS, French-KISS!

RUN_DEPENDS=	lha:${PORTSDIR}/archivers/lha

USE_XLIB=	yes
GNU_CONFIGURE=	yes

NOT_FOR_ARCHS=	alpha

WRKSRC=		${WRKDIR}/${DISTNAME}
MAN1=		fkiss.1

INSTALL_TARGET=	install

post-install:
	${INSTALL_MAN} ${WRKSRC}/fkiss.man ${PREFIX}/man/man1/fkiss.1
	${MKDIR} ${PREFIX}/share/examples/fkiss
	${INSTALL_DATA} ${WRKSRC}/frkismi4.lzh ${PREFIX}/share/examples/fkiss
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/fkiss
	${MKDIR} ${PREFIX}/share/doc/ja/fkiss
	${INSTALL_MAN} ${WRKSRC}/README ${PREFIX}/share/doc/fkiss
	${INSTALL_MAN} ${WRKSRC}/README.euc ${PREFIX}/share/doc/ja/fkiss
	${INSTALL_MAN} ${WRKSRC}/README.sjis ${PREFIX}/share/doc/ja/fkiss
.endif

.include <bsd.port.mk>
