PORTNAME=	semi
PORTVERSION=	${SEMI_VER}.${SNAPDATE}
PORTREVISION=	2
CATEGORIES=	editors elisp
PKGNAMESUFFIX=	${EMACS_PKGNAMESUFFIX}

MAINTAINER=	nobutaka@FreeBSD.org
COMMENT=	SEMI, Library of MIME feature for GNU Emacs for emacs
WWW=		https://github.com/wanderlust/semi

LICENSE=	GPLv2

BUILD_DEPENDS=	flim${EMACS_PKGNAMESUFFIX}>0:editors/flim@${EMACS_FLAVOR}
RUN_DEPENDS=	flim${EMACS_PKGNAMESUFFIX}>0:editors/flim@${EMACS_FLAVOR}

USES=		emacs iconv makeinfo
USE_GITHUB=	yes
GH_ACCOUNT=	wanderlust
GH_TAGNAME=	85a52b8

SNAPDATE=	20240606
NO_ARCH=	yes

FLIM_TRUNK=	1.14
SEMI_VER=	${SEMI_TRUNK}.7
SEMI_TRUNK=	1.14

ALL_TARGET=	elc

MAKE_ARGS+=	PREFIX="${STAGEDIR}${PREFIX}" \
		LISPDIR="${STAGEDIR}${PREFIX}/${EMACS_VERSION_SITE_LISPDIR}" \
		VERSION_SPECIFIC_LISPDIR="${STAGEDIR}${EMACS_VERSION_SITE_LISPDIR}" \
		PACKAGE_LISPDIR=NONE

INFO=		mime-ui-en mime-ui-ja

OPTIONS_DEFINE=	DOCS

post-build:
	@(cd ${WRKSRC} ; \
	for i in mime-ui-en.texi mime-ui-ja.texi; do \
		${MAKEINFO} --no-split --no-validate $${i} ; \
	done)

post-install:
	@(cd ${WRKSRC} ; \
	for i in mime-ui-en.info mime-ui-ja.info; do \
		${INSTALL_DATA} ${WRKSRC}/$${i} ${STAGEDIR}${PREFIX}/${INFO_PATH} ; \
	done)

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@(cd ${WRKSRC} ; \
	for i in NEWS README.* TODO VERSION ; do \
		${INSTALL_DATA} $${i} ${STAGEDIR}${DOCSDIR}/ ; \
	done)

.include <bsd.port.mk>
