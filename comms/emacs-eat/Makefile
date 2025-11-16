PORTNAME=	emacs-eat
DISTVERSIONPREFIX=	v
DISTVERSION=	0.9.4
PORTREVISION=	1
CATEGORIES=	comms elisp
MASTER_SITES=	https://codeberg.org/akib/${PORTNAME}/archive/${DISTVERSIONFULL}${EXTRACT_SUFX}?dummy=/
PKGNAMESUFFIX=	${EMACS_PKGNAMESUFFIX}

MAINTAINER=	pat@patmaddox.com
COMMENT=	Emulate A Terminal, in a region, in a buffer and in Eshell
WWW=		https://codeberg.org/akib/emacs-eat

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		emacs gmake makeinfo

NO_ARCH=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}

INFO=		eat

OPTIONS_DEFINE=	DOCS

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${EMACS_SITE_LISPDIR}
	${INSTALL_DATA} ${WRKSRC}/eat.el ${STAGEDIR}${PREFIX}/${EMACS_SITE_LISPDIR}
	${INSTALL_DATA} ${WRKSRC}/eat.elc ${STAGEDIR}${PREFIX}/${EMACS_SITE_LISPDIR}
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/terminfo/e
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/terminfo/65
	${INSTALL_DATA} ${WRKSRC}/terminfo/e/* ${STAGEDIR}${PREFIX}/share/terminfo/e/
	${INSTALL_DATA} ${WRKSRC}/terminfo/65/* ${STAGEDIR}${PREFIX}/share/terminfo/65/

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.org ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/eat.info ${STAGEDIR}${PREFIX}/${INFO_PATH}/

.include <bsd.port.mk>
