# Created by: Satoshi Taoka <taoka@FreeBSD.org>
# $FreeBSD$

PORTNAME=	wnn7egg
PORTVERSION=	1.02
#PORTREVISION=	1
CATEGORIES=	japanese elisp
MASTER_SITES=	http://www.omronsoft.co.jp/SP/pcunix/wnn7/support/modules/wnn7egg/
DISTNAME=	wnn7-elisp-el-1.02-1
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A Wnn7 elisp client

EMACSDIR=	${PREFIX}/share/emacs/site-lisp
ELISPDIR=	${EMACSDIR}/wnn7egg
SITEPKGDIR=	${PREFIX}/lib/xemacs/site-packages
XELISPDIR=	${SITEPKGDIR}/lisp/wnn7egg
DOCSDIR=	${PREFIX}/share/doc/wnn7egg
MANIFEST=	MANIFEST.wnn7egg
WRKSRC=		${WRKDIR}/wnn7/elisp

NO_BUILD=	yes

PORTDOCS=	README Setup_wnn7egg

NO_STAGE=	yes
do-install:
	${MKDIR} ${ELISPDIR} ${XELISPDIR}
	${MKDIR} ${ELISPDIR}/its-v309 ${XELISPDIR}/its-v309
	${INSTALL_DATA} ${WRKSRC}/emacs20/*.el ${ELISPDIR}
	${INSTALL_DATA} ${WRKSRC}/emacs20/its-v309/*.el ${ELISPDIR}/its-v309

	${INSTALL_DATA} ${WRKSRC}/emacs20/eggrc-wnn7 ${ELISPDIR}
	${INSTALL_DATA} ${WRKSRC}/xemacs21/*.el ${XELISPDIR}
	${INSTALL_DATA} ${WRKSRC}/xemacs21/its-v309/*.el ${XELISPDIR}/its-v309
	${INSTALL_DATA} ${WRKSRC}/xemacs21/eggrc-wnn7 ${XELISPDIR}
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
