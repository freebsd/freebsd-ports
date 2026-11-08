PORTNAME=	nerd-icons.el
DISTVERSION=	0.1.0-151
DISTVERSIONSUFFIX=	-g87ae849
CATEGORIES=	editors elisp

MAINTAINER=	jrm@FreeBSD.org
COMMENT=	Emacs Nerd Font Icons Library
WWW=		https://github.com/rainstormstudio/nerd-icons.el

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	nerd-fonts-symbols>0:x11-fonts/nerd-fonts-symbols

USES=		emacs:build
USE_GITHUB=	yes
GH_ACCOUNT=	rainstormstudio

NO_ARCH=	yes

PLIST_FILES=	${DATA_FILES:S|^|${ELISPDIR}/data/nerd-icons-data-|:S|$|.el|} \
		${ELISP_FILES:S|^|${ELISPDIR}/|}
PORTDOCS=	README.org

OPTIONS_DEFINE=	DOCS

ELISPDIR=	${EMACS_SITE_LISPDIR}/${PORTNAME}
ELISP_FILES=	nerd-icons-autoloads.el nerd-icons-data.el nerd-icons-faces.el \
		nerd-icons.el
DATA_FILES=	codicon devicon faicon flicon ipsicon mdicon octicon pomicon \
		powerline sucicon wicon

do-build:
	${EMACS_CMD} -q --batch -f loaddefs-generate-batch \
		${WRKSRC}/nerd-icons-autoloads.el ${WRKSRC}

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${ELISPDIR}/data
	${INSTALL_DATA} ${ELISP_FILES:S|^|${WRKSRC}/|} \
		${STAGEDIR}${PREFIX}/${ELISPDIR}
	${INSTALL_DATA} ${WRKSRC}/data/*.el \
		${STAGEDIR}${PREFIX}/${ELISPDIR}/data

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.org ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
