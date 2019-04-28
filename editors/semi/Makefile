# Created by: Shigeyuki FUKUSHIMA <shige@FreeBSD.org>
# $FreeBSD$

PORTNAME=	semi
PORTVERSION=	${SEMI_VER}
PORTREVISION=	23
CATEGORIES=	editors elisp
MASTER_SITES=	http://git.chise.org/elisp/dist/semi/semi-1.14-for-flim-1.14/
PKGNAMESUFFIX=	${EMACS_PKGNAMESUFFIX}

MAINTAINER=	nobutaka@FreeBSD.org
COMMENT=	SEMI, Library of MIME feature for GNU Emacs for emacs

LICENSE=	GPLv2

BUILD_DEPENDS=	flim${EMACS_PKGNAMESUFFIX}>0:editors/flim@${EMACS_FLAVOR} \
		nkf:japanese/nkf
RUN_DEPENDS=	flim${EMACS_PKGNAMESUFFIX}>0:editors/flim@${EMACS_FLAVOR}

USES=		emacs makeinfo

NO_ARCH=	yes

FLIM_TRUNK=	1.14
SEMI_VER=	${SEMI_TRUNK}.6
SEMI_TRUNK=	1.14

ALL_TARGET=	elc

MAKE_ARGS+=	PREFIX="${STAGEDIR}${PREFIX}" \
		LISPDIR="${STAGEDIR}${PREFIX}/${EMACS_VERSION_SITE_LISPDIR}" \
		VERSION_SPECIFIC_LISPDIR="${STAGEDIR}${EMACS_VERSION_SITE_LISPDIR}"

INFO=		mime-ui-en mime-ui-ja

OPTIONS_DEFINE=	DOCS

post-build:
	@(cd ${WRKSRC} ; \
	for i in mime-ui-en.texi mime-ui-ja.texi; do \
		${CAT} $${i} | nkf -e > $${i}.jis ; \
		${MAKEINFO} --no-split --no-validate $${i}.jis ; \
	done)

post-install:
	@(cd ${WRKSRC} ; \
	for i in mime-ui-en.info mime-ui-ja.info; do \
		${INSTALL_DATA} ${WRKSRC}/$${i} ${STAGEDIR}${PREFIX}/${INFO_PATH} ; \
	done)

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@(cd ${WRKSRC} ; \
	for i in ChangeLog NEWS README.* TODO VERSION ; do \
		${INSTALL_DATA} $${i} ${STAGEDIR}${DOCSDIR}/ ; \
	done)

.include <bsd.port.mk>
