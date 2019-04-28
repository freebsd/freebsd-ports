# Created by: Shigeyuki FUKUSHIMA <shige@FreeBSD.org>
# $FreeBSD$

PORTNAME=	flim
PORTVERSION=	1.14.9
PORTREVISION=	21
PORTEPOCH=	1
CATEGORIES=	editors elisp
MASTER_SITES=	http://git.chise.org/elisp/dist/${PORTNAME}/${PORTNAME}-${DISTVERSION:R}/
PKGNAMESUFFIX=	${EMACS_PKGNAMESUFFIX}

MAINTAINER=	nobutaka@FreeBSD.org
COMMENT=	Message representation or encoding elisp library for emacs

LICENSE=	GPLv2

BUILD_DEPENDS=	apel${EMACS_PKGNAMESUFFIX}>0:editors/apel@${EMACS_FLAVOR} \
		nkf:japanese/nkf
RUN_DEPENDS=	apel${EMACS_PKGNAMESUFFIX}>0:editors/apel@${EMACS_FLAVOR}

USES=		cpe emacs makeinfo

CPE_VENDOR=	gnu
NO_ARCH=	yes

ALL_TARGET=	elc

MAKE_ARGS+=	PREFIX="${STAGEDIR}${PREFIX}" \
		LISPDIR="${STAGEDIR}${PREFIX}/${EMACS_VERSION_SITE_LISPDIR}" \
		VERSION_SPECIFIC_LISPDIR="${STAGEDIR}${PREFIX}/${EMACS_VERSION_SITE_LISPDIR}"

INFO=		mime-en mime-ja

OPTIONS_DEFINE=	DOCS

post-build:
	@(cd ${WRKSRC} ; \
	for i in mime-en.texi mime-ja.texi; do \
		${CAT} $${i} | nkf -e > $${i}.jis ; \
		${MAKEINFO} --no-split --no-validate $${i}.jis ; \
	done)

post-install:
	@(cd ${WRKSRC} ; \
	for i in mime-en.info mime-ja.info; do \
		${INSTALL_DATA} ${WRKSRC}/$${i} ${STAGEDIR}${PREFIX}/${INFO_PATH} ; \
	done)

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@(cd ${WRKSRC} ; \
	for i in ChangeLog NEWS README.* VERSION ; do \
		${INSTALL_DATA} $${i} ${STAGEDIR}${DOCSDIR}/ ; \
	done)

.include <bsd.port.mk>
