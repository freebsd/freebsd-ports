PORTNAME=	llama.el
DISTVERSIONPREFIX=	v
DISTVERSION=	1.0.4
CATEGORIES=	devel elisp

MAINTAINER=	jrm@FreeBSD.org
COMMENT=	Compact syntax for short lambda in Emacs Lisp
WWW=		https://github.com/tarsius/llama

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	compat.el>=30.1.0.0:misc/compat.el

USES=		emacs:build gmake
USE_GITHUB=	yes
GH_ACCOUNT=	tarsius
GH_PROJECT=	llama

MAKE_ARGS=	LOAD_PATH=" -L ${PREFIX}/${EMACS_SITE_LISPDIR} -L ."
ALL_TARGET=	autoloads

CONFLICTS_INSTALL=	llama.el-emacs_*

NO_ARCH=	yes

PLIST_FILES=	${EMACS_SITE_LISPDIR}/llama-autoloads.el \
		${EMACS_SITE_LISPDIR}/llama.el

PORTDOCS=	README.org

OPTIONS_DEFINE=	DOCS

ELISP_FILES=	llama-autoloads.el llama.el

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${EMACS_SITE_LISPDIR}
	${INSTALL_DATA}  ${ELISP_FILES:C/^/${WRKSRC}\//} \
		${STAGEDIR}${PREFIX}/${EMACS_SITE_LISPDIR}

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:C/^/${WRKSRC}\//} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
