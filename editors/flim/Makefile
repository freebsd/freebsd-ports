PORTNAME=	flim
PORTVERSION=	1.14.9.${SNAPDATE}
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	editors elisp
PKGNAMESUFFIX=	${EMACS_PKGNAMESUFFIX}

MAINTAINER=	nobutaka@FreeBSD.org
COMMENT=	Message representation or encoding elisp library for emacs
WWW=		https://github.com/wanderlust/flim

LICENSE=	GPLv2

BUILD_DEPENDS=	apel${EMACS_PKGNAMESUFFIX}>0:editors/apel@${EMACS_FLAVOR}
RUN_DEPENDS=	apel${EMACS_PKGNAMESUFFIX}>0:editors/apel@${EMACS_FLAVOR}

USES=		cpe emacs iconv makeinfo
USE_GITHUB=	yes
GH_ACCOUNT=	wanderlust
GH_TAGNAME=	f14c8bf

SNAPDATE=	20250506
CPE_VENDOR=	gnu
NO_ARCH=	yes

ALL_TARGET=	elc

MAKE_ARGS+=	PREFIX="${STAGEDIR}${PREFIX}" \
		LISPDIR="${STAGEDIR}${PREFIX}/${EMACS_VERSION_SITE_LISPDIR}" \
		VERSION_SPECIFIC_LISPDIR="${STAGEDIR}${PREFIX}/${EMACS_VERSION_SITE_LISPDIR}" \
		PACKAGE_LISPDIR=NONE

INFO=		mime-en mime-ja

OPTIONS_DEFINE=	DOCS

post-build:
	@(cd ${WRKSRC} ; \
	for i in mime-en.texi mime-ja.texi; do \
		${MAKEINFO} --no-split --no-validate $${i} ; \
	done)

post-install:
	@(cd ${WRKSRC} ; \
	for i in mime-en.info mime-ja.info; do \
		${INSTALL_DATA} ${WRKSRC}/$${i} ${STAGEDIR}${PREFIX}/${INFO_PATH} ; \
	done)

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@(cd ${WRKSRC} ; \
	for i in NEWS README.* VERSION ; do \
		${INSTALL_DATA} $${i} ${STAGEDIR}${DOCSDIR}/ ; \
	done)

.include <bsd.port.mk>
