PORTNAME=	llama.el
DISTVERSIONPREFIX=	v
DISTVERSION=	1.0.0
CATEGORIES=	devel elisp
PKGNAMESUFFIX=	${EMACS_PKGNAMESUFFIX}

MAINTAINER=	yasu@FreeBSD.org
COMMENT=	Compact syntax for short lambda in Emacs Lisp
WWW=		https://github.com/tarsius/llama

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	compat.el${EMACS_PKGNAMESUFFIX}>=30.1.0.0:misc/compat.el@${EMACS_FLAVOR}
RUN_DEPENDS=	compat.el${EMACS_PKGNAMESUFFIX}>=30.1.0.0:misc/compat.el@${EMACS_FLAVOR}

USES=		emacs gmake
USE_GITHUB=	yes
GH_ACCOUNT=	tarsius
GH_PROJECT=	llama

MAKE_ARGS=	LOAD_PATH=" -L ${PREFIX}/${EMACS_VERSION_SITE_LISPDIR} -L ${PREFIX}/${EMACS_VERSION_SITE_LISPDIR}/compat -L ."
MAKE_JOBS_UNSAFE=	Opening input file: No such file or directory, /wrkdirs/usr/ports/devel/llama.el/work-nox/llama-0.6.0/.#llama-autoloads.el

NO_ARCH=	yes
PLIST_FILES=	${EMACS_VERSION_SITE_LISPDIR}/llama-autoloads.el \
		${EMACS_VERSION_SITE_LISPDIR}/llama.el \
		${EMACS_VERSION_SITE_LISPDIR}/llama.elc

PORTDOCS=	README.org

OPTIONS_DEFINE=	DOCS

ELISP_FILES=	llama-autoloads.el llama.el llama.elc

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${EMACS_VERSION_SITE_LISPDIR}
	${INSTALL_DATA}  ${ELISP_FILES:C/^/${WRKSRC}\//} \
		${STAGEDIR}${PREFIX}/${EMACS_VERSION_SITE_LISPDIR}

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:C/^/${WRKSRC}\//} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
