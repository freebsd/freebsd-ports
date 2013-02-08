# Created by: Castor Fu
# $FreeBSD$

PORTNAME=	cscope
PORTVERSION=	15.8a
CATEGORIES=	devel
MASTER_SITES=	SF

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	An interactive C program browser

OPTIONS_DEFINE=	XCSCOPE
XCSCOPE_DESC=	Install (X)Emacs package

GNU_CONFIGURE=	yes

EMACSLISPDIR=	${PREFIX}/share/emacs/site-lisp
XEMACSLISPDIR=	${PREFIX}/lib/xemacs/site-lisp

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MXCSCOPE}
PLIST_SUB+=	XCSCOPE=""
post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/contrib/xcscope/cscope-indexer ${PREFIX}/bin
	${MKDIR} ${EMACSLISPDIR}
	${INSTALL_DATA} ${WRKSRC}/contrib/xcscope/xcscope.el ${EMACSLISPDIR}
	${MKDIR} ${XEMACSLISPDIR}
	${LN} -sf ${EMACSLISPDIR}/xcscope.el ${XEMACSLISPDIR}
.else
PLIST_SUB+=	XCSCOPE="@comment "
.endif

MAN1=		cscope.1

.include <bsd.port.mk>
