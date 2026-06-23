PORTNAME=	llama.el
DISTVERSIONPREFIX=	v
DISTVERSION=	1.0.5
CATEGORIES=	devel elisp

MAINTAINER=	jrm@FreeBSD.org
COMMENT=	Compact syntax for short lambda in Emacs Lisp
WWW=		https://github.com/tarsius/llama

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	compat.el>=31.0:misc/compat.el

USES=		emacs:build gmake
USE_GITHUB=	yes
GH_ACCOUNT=	tarsius
GH_PROJECT=	llama

MAKE_ARGS=	LOAD_PATH=" -L ${PREFIX}/${EMACS_SITE_LISPDIR} -L ."
ALL_TARGET=	autoloads

CONFLICTS_INSTALL=	llama.el-emacs_*

NO_ARCH=	yes

PLIST_FILES=	${ELISPDIR}/llama-autoloads.el \
		${ELISPDIR}/llama.el

PORTDOCS=	README.org

OPTIONS_DEFINE=	DOCS

ELISPDIR=	${EMACS_SITE_LISPDIR}/${PORTNAME:R}
ELISP_FILES=	llama-autoloads.el llama.el

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${ELISPDIR}
	${INSTALL_DATA}  ${ELISP_FILES:C/^/${WRKSRC}\//} \
		${STAGEDIR}${PREFIX}/${ELISPDIR}

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:C/^/${WRKSRC}\//} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
