# New ports collection makefile for:	wnn7egg
# Date created:		01/07/16
# Whom:			Satoshi Taoka <taoka@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	wnn7egg
PORTVERSION=	1.00
CATEGORIES=	japanese elisp
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	taoka
DISTNAME=	ja-wnn7-elisp-1.00_1
EXTRACT_SUFX=	.tgz

MAINTAINER=	taoka@FreeBSD.org

EMACSDIR=	${PREFIX}/share/emacs/site-lisp
ELISPDIR=	${EMACSDIR}/wnn7egg
SITEPKGDIR=	${PREFIX}/lib/xemacs/site-packages
XELISPDIR=	${SITEPKGDIR}/lisp/wnn7egg
DOCDIR=		${PREFIX}/share/doc/wnn7egg
MANIFEST=	MANIFEST.wnn7egg
WRKSRC=		${WRKDIR}/usr/share/wnn7/elisp

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
