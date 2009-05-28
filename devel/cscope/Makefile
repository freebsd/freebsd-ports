# ex:ts=8
# ports collection makefile for:	cscope
# Date created:		1998-11-21
# Whom:			Castor Fu
#
# $FreeBSD$
#

PORTNAME=	cscope
PORTVERSION=	15.7a
CATEGORIES=	devel
MASTER_SITES=	SF

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	An interactive C program browser

OPTIONS=	XCSCOPE "Install (X)Emacs package" off

USE_BZIP2=	yes
GNU_CONFIGURE=	yes

EMACSLISPDIR=	${PREFIX}/share/emacs/site-lisp
XEMACSLISPDIR=	${PREFIX}/lib/xemacs/site-lisp

.include <bsd.port.pre.mk>

.if defined(WITH_XCSCOPE)
PLIST_SUB+=	XCSCOPE=""
.else
PLIST_SUB+=	XCSCOPE="@comment "
.endif

MAN1=		cscope.1

.if defined(WITH_XCSCOPE)
post-install:
	${MKDIR} ${EMACSLISPDIR}
	${INSTALL_DATA} ${WRKSRC}/contrib/xcscope/xcscope.el ${EMACSLISPDIR}/
	${MKDIR} ${XEMACSLISPDIR}
	${LN} -sf ${EMACSLISPDIR}/xcscope.el ${XEMACSLISPDIR}
.endif

.include <bsd.port.post.mk>
