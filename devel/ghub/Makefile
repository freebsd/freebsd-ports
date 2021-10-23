PORTNAME=	ghub
DISTVERSIONPREFIX=	v
DISTVERSION=	3.5.4
PORTREVISION=	1
CATEGORIES=	devel elisp
PKGNAMESUFFIX=	${EMACS_PKGNAMESUFFIX}

MAINTAINER=	yasu@FreeBSD.org
COMMENT=	Minuscule client library for the Github API

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	treepy.el${EMACS_PKGNAMESUFFIX}>=0.1.1:devel/treepy.el@${EMACS_FLAVOR}
RUN_DEPENDS=	treepy.el${EMACS_PKGNAMESUFFIX}>=0.1.1:devel/treepy.el@${EMACS_FLAVOR}

USES=		emacs gmake makeinfo
USE_GITHUB=	yes
GH_ACCOUNT=	magit

MAKE_ARGS=	LOAD_PATH="-L ${PREFIX}/${EMACS_SITE_LISPDIR} -L ${PREFIX}/${EMACS_VERSION_SITE_LISPDIR} -L ."

NO_ARCH=	yes

INFO=		ghub
PORTDOCS=	README.md

OPTIONS_DEFINE=	DOCS

ELISP_FILES=	buck.el buck.elc ghub-autoloads.el ghub-graphql.el \
		ghub-graphql.elc ghub.el ghub.elc glab.el glab.elc gogs.el \
		gogs.elc gsexp.el gsexp.elc gtea.el gtea.elc

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${EMACS_VERSION_SITE_LISPDIR}/${PORTNAME}
.for f in ${ELISP_FILES}
	${INSTALL_DATA} ${WRKSRC}/${f} \
		${STAGEDIR}${PREFIX}/${EMACS_VERSION_SITE_LISPDIR}/${PORTNAME}
.endfor
	${INSTALL_DATA} ${WRKSRC}/*.info ${STAGEDIR}${PREFIX}/${INFO_PATH}

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
