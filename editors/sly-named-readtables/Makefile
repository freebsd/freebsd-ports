PORTNAME=	sly-named-readtables
PORTVERSION=	20191013
PORTREVISION=	19
CATEGORIES=	editors elisp

MAINTAINER=	olce.freebsd.ports@certner.fr
COMMENT=	Support different readtables in the same file for SLY
WWW=		https://github.com/joaotavora/sly-named-readtables

LICENSE=	PD

MY_DEPENDS=	${PREFIX}/${EMACS_SITE_LISPDIR}/sly/sly.el:editors/sly
BUILD_DEPENDS=	${MY_DEPENDS}
RUN_DEPENDS=	${MY_DEPENDS}

USES=		emacs
USE_GITHUB=	yes
GH_ACCOUNT=	joaotavora
GH_TAGNAME=	a5a42674ccffa97ccd5e4e9742beaf3ea719931f

CONFLICTS_INSTALL=	sly-named-readtables-emacs_*

NO_ARCH=	yes
NO_BUILD=	yes

PLIST_THIS_LISPDIR=	${EMACS_SITE_LISPDIR}/${PORTNAME}
THIS_LISPDIR=		${PREFIX}/${PLIST_THIS_LISPDIR}
PLIST_SUB+=		THIS_LISPDIR=${PLIST_THIS_LISPDIR}

# File is buggy and can't be used as documented upstream
EXCLUDED_FILES=	${PORTNAME}-autoloads.el

PORTDOCS=	README.md screenshot.png
PORTEXAMPLES=	example.lisp

OPTIONS_DEFINE=	DOCS EXAMPLES

do-install:
	@${MKDIR} ${STAGEDIR}${THIS_LISPDIR}
	(cd ${WRKSRC} && \
		${COPYTREE_SHARE} . ${STAGEDIR}${THIS_LISPDIR} \
		"! ( -depth 1 ( ${EXCLUDED_FILES:C/^(.*)$/-name \1 -o/} \
			${PORTDOCS:C/^(.*)$/-name \1 -o/} \
			${PORTEXAMPLES:C/^(.*)$/-name \1 -o/} \
			-name LICENSE -o -name *\.md -o -name \.[^.]* ) )")

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:%=${WRKSRC}/%} ${STAGEDIR}${DOCSDIR}

post-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${PORTEXAMPLES:%=${WRKSRC}/%} ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
