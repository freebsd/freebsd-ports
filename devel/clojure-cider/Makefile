# $FreeBSD$

PORTNAME=	clojure-cider
PORTVERSION=	0.7.0
PORTREVISION=	1
CATEGORIES=	devel elisp
DISTNAME=	cider-${PORTVERSION}

MAINTAINER=	rpaulo@FreeBSD.org
COMMENT=	Clojure IDE and REPL for Emacs

LICENSE=	GPLv3

USE_GITHUB=	yes
GH_ACCOUNT=	clojure-emacs
GH_TAGNAME=	v${PORTVERSION}
GH_COMMIT=	950c38a
GH_PROJECT=	cider

USE_EMACS=	yes

NO_BUILD=	yes

RUN_DEPENDS+=	clojure-mode.el>0:${PORTSDIR}/lang/clojure-mode.el \
		dash.el>0:${PORTSDIR}/devel/dash.el \
		epl.el>0:${PORTSDIR}/devel/epl.el \
		pkg-info.el>0:${PORTSDIR}/devel/pkg-info.el

do-install:
	${INSTALL_DATA} ${WRKSRC}/cider-client.el \
		${STAGEDIR}${PREFIX}/${EMACS_SITE_LISPDIR}
	${INSTALL_DATA} ${WRKSRC}/cider-eldoc.el \
		${STAGEDIR}${PREFIX}/${EMACS_SITE_LISPDIR}
	${INSTALL_DATA} ${WRKSRC}/cider-inspector.el \
		${STAGEDIR}${PREFIX}/${EMACS_SITE_LISPDIR}
	${INSTALL_DATA} ${WRKSRC}/cider-interaction.el \
		${STAGEDIR}${PREFIX}/${EMACS_SITE_LISPDIR}
	${INSTALL_DATA} ${WRKSRC}/cider-macroexpansion.el \
		${STAGEDIR}${PREFIX}/${EMACS_SITE_LISPDIR}
	${INSTALL_DATA} ${WRKSRC}/cider-mode.el \
		${STAGEDIR}${PREFIX}/${EMACS_SITE_LISPDIR}
	${INSTALL_DATA} ${WRKSRC}/cider-repl.el \
		${STAGEDIR}${PREFIX}/${EMACS_SITE_LISPDIR}
	${INSTALL_DATA} ${WRKSRC}/cider-scratch.el \
		${STAGEDIR}${PREFIX}/${EMACS_SITE_LISPDIR}
	${INSTALL_DATA} ${WRKSRC}/cider-selector.el \
		${STAGEDIR}${PREFIX}/${EMACS_SITE_LISPDIR}
	${INSTALL_DATA} ${WRKSRC}/cider-stacktrace.el \
		${STAGEDIR}${PREFIX}/${EMACS_SITE_LISPDIR}
	${INSTALL_DATA} ${WRKSRC}/cider-util.el \
		${STAGEDIR}${PREFIX}/${EMACS_SITE_LISPDIR}
	${INSTALL_DATA} ${WRKSRC}/cider.el \
		${STAGEDIR}${PREFIX}/${EMACS_SITE_LISPDIR}
	${INSTALL_DATA} ${WRKSRC}/nrepl-client.el \
		${STAGEDIR}${PREFIX}/${EMACS_SITE_LISPDIR}

.include <bsd.port.mk>
