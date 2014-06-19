# Created by: Castor Fu
# $FreeBSD$

PORTNAME=	cscope
PORTVERSION=	15.8a
CATEGORIES=	devel
MASTER_SITES=	SF

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	Interactive C program browser

LICENSE=	BSD3CLAUSE

OPTIONS_DEFINE=	XCSCOPE
XCSCOPE_DESC=	Install (X)Emacs package

GNU_CONFIGURE=	yes

EMACSLISPDIR=	${PREFIX}/share/emacs/site-lisp
XEMACSLISPDIR=	${PREFIX}/lib/xemacs/site-lisp

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MXCSCOPE}
PLIST_SUB+=	XCSCOPE=""
post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/contrib/xcscope/cscope-indexer ${STAGEDIR}${PREFIX}/bin
	${MKDIR} ${STAGEDIR}${EMACSLISPDIR}
	${INSTALL_DATA} ${WRKSRC}/contrib/xcscope/xcscope.el ${STAGEDIR}${EMACSLISPDIR}
	${MKDIR} ${STAGEDIR}${XEMACSLISPDIR}
	${LN} -sf ${EMACSLISPDIR}/xcscope.el ${STAGEDIR}${XEMACSLISPDIR}
.else
PLIST_SUB+=	XCSCOPE="@comment "
.endif

.include <bsd.port.mk>
