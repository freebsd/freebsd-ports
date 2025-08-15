PORTNAME=	clojure-cider
DISTVERSIONPREFIX=	v
DISTVERSION=	1.19.0
PORTREVISION=	1
CATEGORIES=	devel elisp
PKGNAMESUFFIX=	${EMACS_PKGNAMESUFFIX}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Clojure IDE and REPL for Emacs
WWW=		https://github.com/clojure-emacs/cider

LICENSE=	GPLv3+

RUN_DEPENDS=	clojure-mode.el${EMACS_PKGNAMESUFFIX}>0:lang/clojure-mode.el@${EMACS_FLAVOR} \
		dash.el${EMACS_PKGNAMESUFFIX}>0:devel/dash.el@${EMACS_FLAVOR} \
		epl.el${EMACS_PKGNAMESUFFIX}>0:devel/epl.el@${EMACS_FLAVOR} \
		pkg-info.el${EMACS_PKGNAMESUFFIX}>0:devel/pkg-info.el@${EMACS_FLAVOR}

USES=		emacs
USE_GITHUB=	yes
GH_ACCOUNT=	clojure-emacs
GH_PROJECT=	cider

NO_ARCH=	yes
NO_BUILD=	yes

PLIST_FILES=	${EMACS_SITE_LISPDIR}/cider-client.el \
		${EMACS_SITE_LISPDIR}/cider-eldoc.el \
		${EMACS_SITE_LISPDIR}/cider-inspector.el \
		${EMACS_SITE_LISPDIR}/cider-macroexpansion.el \
		${EMACS_SITE_LISPDIR}/cider-mode.el \
		${EMACS_SITE_LISPDIR}/cider-repl.el \
		${EMACS_SITE_LISPDIR}/cider-scratch.el \
		${EMACS_SITE_LISPDIR}/cider-selector.el \
		${EMACS_SITE_LISPDIR}/cider-stacktrace.el \
		${EMACS_SITE_LISPDIR}/cider-util.el \
		${EMACS_SITE_LISPDIR}/cider.el \
		${EMACS_SITE_LISPDIR}/nrepl-client.el

do-install:
.for f in ${PLIST_FILES:S,^${EMACS_SITE_LISPDIR}/,,}
	${INSTALL_DATA} ${WRKSRC}/${f} \
		${STAGEDIR}${PREFIX}/${EMACS_SITE_LISPDIR}
.endfor

.include <bsd.port.mk>
