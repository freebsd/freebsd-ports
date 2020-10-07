# $FreeBSD$

PORTNAME=	cscope
DISTVERSION=	15.9
CATEGORIES=	devel
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/v${PORTVERSION}

MAINTAINER=	moritz@schmi.tt
COMMENT=	Interactive C source code browser

LICENSE=	BSD3CLAUSE

USES=		ncurses

GNU_CONFIGURE=	yes

OPTIONS_DEFINE=	XCSCOPE
OPTIONS_SUB=	yes

XCSCOPE_DESC=	Install Emacs package

EMACSLISPDIR=	${PREFIX}/share/emacs/site-lisp

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/contrib/xcscope/cscope-indexer ${STAGEDIR}${PREFIX}/bin
	${MKDIR} ${STAGEDIR}${EMACSLISPDIR}
	${INSTALL_DATA} ${WRKSRC}/contrib/xcscope/xcscope.el ${STAGEDIR}${EMACSLISPDIR}

.include <bsd.port.mk>
