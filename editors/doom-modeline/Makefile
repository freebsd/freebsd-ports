PORTNAME=	doom-modeline
DISTVERSIONPREFIX=	v
DISTVERSION=	4.2.1
CATEGORIES=	editors elisp

MAINTAINER=	jrm@FreeBSD.org
COMMENT=	Fancy and fast Emacs mode-line
WWW=		https://github.com/seagle0128/doom-modeline

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	compat.el>=30.1.0.0:misc/compat.el \
		nerd-icons.el>=0.1.0:editors/nerd-icons.el \
		shrink-path.el>=0.3.1:editors/shrink-path.el

USES=		emacs:build
USE_GITHUB=	yes
GH_ACCOUNT=	seagle0128

NO_ARCH=	yes

PLIST_FILES=	${ELISP_FILES:S|^|${ELISPDIR}/|}
PORTDOCS=	README.md

OPTIONS_DEFINE=	DOCS

ELISPDIR=	${EMACS_SITE_LISPDIR}/${PORTNAME}
ELISP_FILES=	doom-modeline-autoloads.el doom-modeline-core.el \
		doom-modeline-env.el doom-modeline-segments.el doom-modeline.el

do-build:
	${EMACS_CMD} -q --batch -f loaddefs-generate-batch \
		${WRKSRC}/doom-modeline-autoloads.el ${WRKSRC}

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${ELISPDIR}
	${INSTALL_DATA} ${ELISP_FILES:S|^|${WRKSRC}/|} \
		${STAGEDIR}${PREFIX}/${ELISPDIR}

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
