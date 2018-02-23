# Created by: Dominic Mitchell
# $FreeBSD$

PORTNAME=	slime
DISTVERSIONPREFIX=	v
DISTVERSION=	2.20
CATEGORIES=	editors elisp
PKGNAMESUFFIX=	${EMACS_PKGNAMESUFFIX}

MAINTAINER=	joe@thrallingpenguin.com
COMMENT=	Superior Lisp Interaction Mode for Emacs

LICENSE=	PD

BUILD_DEPENDS=	texinfo>=5.2:print/texinfo

USES=		emacs gmake
USE_GITHUB=	yes
NO_ARCH=	yes

SLIME_LISPDIR=	${PREFIX}/${EMACS_VERSION_SITE_LISPDIR}/slime

SUB_FILES=	pkg-message
SUB_LIST=	SLIME_LISPDIR="${SLIME_LISPDIR}"

INFO=		slime
PORTDOCS=	CONTRIBUTING.md NEWS PROBLEMS README.md

OPTIONS_DEFINE=	DOCS

do-build:
	cd ${WRKSRC}/doc && ${MAKE_CMD} slime.info
	cd ${WRKSRC} && ${EMACS_CMD} -batch \
		-eval '(setq load-path (cons nil load-path))' \
		-f batch-byte-compile *.el

do-install:
	@${MKDIR} ${STAGEDIR}${SLIME_LISPDIR}/contrib
	@${MKDIR} ${STAGEDIR}${SLIME_LISPDIR}/contrib/test
	@${MKDIR} ${STAGEDIR}${SLIME_LISPDIR}/lib
	@${MKDIR} ${STAGEDIR}${SLIME_LISPDIR}/swank
	cd ${WRKSRC} && ${INSTALL_DATA} *.asd *.el *.lisp ${STAGEDIR}${SLIME_LISPDIR}
	cd ${WRKSRC}/lib && ${INSTALL_DATA} *.el ${STAGEDIR}${SLIME_LISPDIR}/lib
	cd ${WRKSRC}/contrib && ${INSTALL_DATA} \
		*.el *.lisp *.ss *.scm *.sml \
		${STAGEDIR}${SLIME_LISPDIR}/contrib
	cd ${WRKSRC}/contrib/test && ${INSTALL_DATA} *.txt *.el \
		${STAGEDIR}${SLIME_LISPDIR}/contrib/test
	cd ${WRKSRC}/swank && ${INSTALL_DATA} *.lisp \
		${STAGEDIR}${SLIME_LISPDIR}/swank
	${INSTALL_DATA} ${INSTALL_WRKSRC}/doc/slime.info \
		${STAGEDIR}${PREFIX}/${INFO_PATH}

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${INSTALL_WRKSRC}/contrib/README.md \
		${STAGEDIR}${DOCSDIR}/README-contrib.md
	(cd ${INSTALL_WRKSRC}/doc && ${INSTALL_DATA} slime-refcard.pdf \
		slime-small.pdf ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
