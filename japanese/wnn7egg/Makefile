# New ports collection makefile for:	wnn7egg
# Date created:		01/07/16
# Whom:			Satoshi Taoka <taoka@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	wnn7egg
PORTVERSION=	1.02
#PORTREVISION=	1
CATEGORIES=	japanese elisp
MASTER_SITES=	ftp://ftp.omronsoft.co.jp/pub/Wnn7/client/lisp/
DISTNAME=	wnn7-elisp-el-1.02-1
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A Wnn7 elisp client

EMACSDIR=	${PREFIX}/share/emacs/site-lisp
ELISPDIR=	${EMACSDIR}/wnn7egg
SITEPKGDIR=	${PREFIX}/lib/xemacs/site-packages
XELISPDIR=	${SITEPKGDIR}/lisp/wnn7egg
DOCDIR=		${PREFIX}/share/doc/wnn7egg
MANIFEST=	MANIFEST.wnn7egg
WRKSRC=		${WRKDIR}/wnn7/elisp

NO_BUILD=	yes

do-install:
	${MKDIR} ${ELISPDIR} ${DOCDIR} ${XELISPDIR}
	${MKDIR} ${ELISPDIR}/its-v309 ${XELISPDIR}/its-v309
	${INSTALL_DATA} ${WRKSRC}/emacs20/*.el ${ELISPDIR}
	${INSTALL_DATA} ${WRKSRC}/emacs20/its-v309/*.el ${ELISPDIR}/its-v309

	${INSTALL_DATA} ${WRKSRC}/emacs20/eggrc-wnn7 ${ELISPDIR}
	${INSTALL_DATA} ${WRKSRC}/xemacs21/*.el ${XELISPDIR}
	${INSTALL_DATA} ${WRKSRC}/xemacs21/its-v309/*.el ${XELISPDIR}/its-v309
	${INSTALL_DATA} ${WRKSRC}/xemacs21/eggrc-wnn7 ${XELISPDIR}
.if !defined(NOPORTDOCS)
	${INSTALL_DATA} ${WRKSRC}/README ${DOCDIR}/
	${INSTALL_DATA} ${WRKSRC}/Setup_wnn7egg ${DOCDIR}
.endif

.include <bsd.port.mk>
