# Created by: Castor Fu
# $FreeBSD$

PORTNAME=	cscope
PORTVERSION=	15.8b
CATEGORIES=	devel
MASTER_SITES=	SF

MAINTAINER=	johans@FreeBSD.org
COMMENT=	Interactive C program browser

LICENSE=	BSD3CLAUSE

USES=		ncurses
OPTIONS_DEFINE=	XCSCOPE
OPTIONS_SUB=	yes
XCSCOPE_DESC=	Install (X)Emacs package

GNU_CONFIGURE=	yes

EMACSLISPDIR=	${PREFIX}/share/emacs/site-lisp
XEMACSLISPDIR=	${PREFIX}/lib/xemacs/site-lisp

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/contrib/xcscope/cscope-indexer ${STAGEDIR}${PREFIX}/bin
	${MKDIR} ${STAGEDIR}${EMACSLISPDIR}
	${INSTALL_DATA} ${WRKSRC}/contrib/xcscope/xcscope.el ${STAGEDIR}${EMACSLISPDIR}
	${MKDIR} ${STAGEDIR}${XEMACSLISPDIR}
	${LN} -sf ${EMACSLISPDIR}/xcscope.el ${STAGEDIR}${XEMACSLISPDIR}

.include <bsd.port.mk>
