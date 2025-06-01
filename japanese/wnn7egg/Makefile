PORTNAME=	wnn7egg
PORTVERSION=	1.02
PORTREVISION=	1
CATEGORIES=	japanese elisp
MASTER_SITES=	https://socialsolution.omron.com/software/products/product_text/wnn7/support/modules/wnn7egg/
DISTNAME=	wnn7-elisp-el-1.02-1

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Wnn7 elisp client
WWW=		https://socialsolution.omron.com/software/products/product_text/wnn7/support/wnn7egg_src.html

LICENSE=	GPLv2

USES=		tar:tgz

NO_BUILD=	yes

EMACSDIR=	${STAGEDIR}${PREFIX}/share/emacs/site-lisp
ELISPDIR=	${EMACSDIR}/wnn7egg
MANIFEST=	MANIFEST.wnn7egg
WRKSRC=		${WRKDIR}/wnn7/elisp

PORTDOCS=	README Setup_wnn7egg

OPTIONS_DEFINE=	DOCS

do-install:
	${MKDIR} ${ELISPDIR}/its-v309
	${INSTALL_DATA} ${WRKSRC}/emacs20/*.el ${ELISPDIR}
	${INSTALL_DATA} ${WRKSRC}/emacs20/its-v309/*.el ${ELISPDIR}/its-v309

	${INSTALL_DATA} ${WRKSRC}/emacs20/eggrc-wnn7 ${ELISPDIR}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
