PORTNAME=	clojure-cider
DISTVERSIONPREFIX=	v
DISTVERSION=	1.21.0
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

do-install:
	${INSTALL_DATA} ${WRKSRC}/lisp/*.el ${STAGEDIR}${PREFIX}/${EMACS_SITE_LISPDIR}

.include <bsd.port.mk>
