# Created by: Dominic Mitchell
# $FreeBSD$

PORTNAME=	slime
PORTVERSION=	2.10.1
PORTREVISION=	1
CATEGORIES=	editors elisp
MASTER_SITES=	https://codeload.github.com/slime/slime/legacy.tar.gz/v${PORTVERSION}?dummy=/

MAINTAINER=	joe@thrallingpenguin.com
COMMENT=	Superior Lisp Interaction Mode for Emacs

LICENSE=	PUBLIC_DOMAIN
LICENSE_NAME=	${LICENSE:S/_/ /}
LICENSE_TEXT=	The license: ${_LICENSE} (${_LICENSE_NAME}) is standard, please read from the web.
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

BUILD_DEPENDS=	texinfo>=5.2:${PORTSDIR}/print/texinfo

USES=		gmake
USE_EMACS=	yes

SLIME_LISPDIR=	${PREFIX}/${EMACS_VERSION_SITE_LISPDIR}/slime
WRKSRC=		${WRKDIR}/slime-slime-295edb8

SUB_FILES=	pkg-message
SUB_LIST=	SLIME_LISPDIR="${SLIME_LISPDIR}"

INFO=		slime
PORTDOCS=	CONTRIBUTING.md ChangeLog NEWS PROBLEMS README.md

OPTIONS_DEFINE=	DOCS

do-build:
	cd ${WRKSRC}/doc && ${MAKE_CMD} slime.info
	cd ${WRKSRC} && ${EMACS_CMD} -batch \
		-eval '(setq load-path (cons nil load-path))' \
		-f batch-byte-compile *.el

do-install:
	@${MKDIR} ${STAGEDIR}${SLIME_LISPDIR}/contrib
	@${MKDIR} ${STAGEDIR}${SLIME_LISPDIR}/lib
	cd ${WRKSRC} && ${INSTALL_DATA} *.elc *.el *.lisp ${STAGEDIR}${SLIME_LISPDIR}
	cd ${WRKSRC}/lib && ${INSTALL_DATA} *.el ${STAGEDIR}${SLIME_LISPDIR}/lib
	cd ${WRKSRC}/contrib && ${INSTALL_DATA} *.el *.lisp \
		${STAGEDIR}${SLIME_LISPDIR}/contrib
	${INSTALL_DATA} ${WRKSRC}/ChangeLog ${STAGEDIR}${SLIME_LISPDIR}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${INSTALL_WRKSRC}/doc/slime.info \
		${STAGEDIR}${PREFIX}/${INFO_PATH}
	${INSTALL_DATA} ${INSTALL_WRKSRC}/contrib/README.md \
		${STAGEDIR}${DOCSDIR}/README-contrib.md
	(cd ${INSTALL_WRKSRC}/doc && ${INSTALL_DATA} slime-refcard.pdf \
		slime-small.pdf ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
