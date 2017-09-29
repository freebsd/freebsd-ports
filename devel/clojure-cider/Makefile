# $FreeBSD$

PORTNAME=	clojure-cider
PORTVERSION=	0.15.1
DISTVERSIONPREFIX=	v
CATEGORIES=	devel elisp

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Clojure IDE and REPL for Emacs

LICENSE=	GPLv3+

RUN_DEPENDS=	clojure-mode.el>0:lang/clojure-mode.el \
		dash.el>0:devel/dash.el \
		epl.el>0:devel/epl.el \
		pkg-info.el>0:devel/pkg-info.el

USE_GITHUB=	yes
GH_ACCOUNT=	clojure-emacs
GH_PROJECT=	cider

USE_EMACS=	yes

NO_BUILD=	yes
NO_ARCH=	yes

PLIST_FILES=	${EMACS_SITE_LISPDIR}/cider-client.el \
		${EMACS_SITE_LISPDIR}/cider-eldoc.el \
		${EMACS_SITE_LISPDIR}/cider-inspector.el \
		${EMACS_SITE_LISPDIR}/cider-interaction.el \
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
