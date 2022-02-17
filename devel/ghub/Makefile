PORTNAME=	ghub
DISTVERSIONPREFIX=	v
DISTVERSION=	3.5.5
CATEGORIES=	devel elisp
PKGNAMESUFFIX=	${EMACS_PKGNAMESUFFIX}

MAINTAINER=	yasu@FreeBSD.org
COMMENT=	Client libraries for the APIs of various Git forges

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	treepy.el${EMACS_PKGNAMESUFFIX}>=0.1.1:devel/treepy.el@${EMACS_FLAVOR}
RUN_DEPENDS=	treepy.el${EMACS_PKGNAMESUFFIX}>=0.1.1:devel/treepy.el@${EMACS_FLAVOR}

USES=		emacs gmake makeinfo
USE_GITHUB=	yes
GH_ACCOUNT=	magit

MAKE_ARGS=	LOAD_PATH="-L ${PREFIX}/${EMACS_SITE_LISPDIR} -L ${PREFIX}/${EMACS_VERSION_SITE_LISPDIR} -L ."
ALL_TARGET=	lisp info

NO_ARCH=	yes

INFO=		ghub
PORTDOCS=	CHANGELOG README.md

OPTIONS_DEFINE=	DOCS

ELISP_FILES=	buck.el buck.elc ghub-autoloads.el ghub-graphql.el \
		ghub-graphql.elc ghub.el ghub.elc glab.el glab.elc gogs.el \
		gogs.elc gsexp.el gsexp.elc gtea.el gtea.elc

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${EMACS_VERSION_SITE_LISPDIR}/${PORTNAME}
	${INSTALL_DATA} ${ELISP_FILES:C/^/${WRKSRC}\/lisp\//} \
		${STAGEDIR}${PREFIX}/${EMACS_VERSION_SITE_LISPDIR}/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/docs/*.info ${STAGEDIR}${PREFIX}/${INFO_PATH}

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:C/^/${WRKSRC}\//} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
