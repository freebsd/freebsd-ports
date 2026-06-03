PORTNAME=	clojure-cider
DISTVERSIONPREFIX=	v
DISTVERSION=	1.21.0
PORTREVISION=	1
CATEGORIES=	devel elisp

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Clojure IDE and REPL for Emacs
WWW=		https://github.com/clojure-emacs/cider

LICENSE=	GPLv3+

RUN_DEPENDS=	clojure-mode.el>0:lang/clojure-mode.el \
		dash.el>0:devel/dash.el \
		epl.el>0:devel/epl.el \
		pkg-info.el>0:devel/pkg-info.el

USES=		emacs
USE_GITHUB=	yes
GH_ACCOUNT=	clojure-emacs
GH_PROJECT=	cider

CONFLICTS_INSTALL=	clojure-cider-emacs_*

NO_ARCH=	yes
NO_BUILD=	yes

do-install:
	${INSTALL_DATA} ${WRKSRC}/lisp/*.el ${STAGEDIR}${PREFIX}/${EMACS_SITE_LISPDIR}

.include <bsd.port.mk>
