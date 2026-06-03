PORTNAME=	flim
PORTVERSION=	1.14.9.${SNAPDATE}
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	editors elisp

MAINTAINER=	nobutaka@FreeBSD.org
COMMENT=	Message representation or encoding elisp library for emacs
WWW=		https://github.com/wanderlust/flim

LICENSE=	GPLv2

BUILD_DEPENDS=	apel>0:editors/apel
RUN_DEPENDS=	apel>0:editors/apel

USES=		cpe emacs:build iconv makeinfo
CPE_VENDOR=	gnu
USE_GITHUB=	yes
GH_ACCOUNT=	wanderlust
GH_TAGNAME=	392c29d

SNAPDATE=	20251030

MAKE_ARGS+=	PREFIX="${STAGEDIR}${PREFIX}" \
		LISPDIR="${STAGEDIR}${PREFIX}/${EMACS_SITE_LISPDIR}" \
		VERSION_SPECIFIC_LISPDIR="${STAGEDIR}${PREFIX}/${EMACS_SITE_LISPDIR}" \
		PACKAGE_LISPDIR=NONE

CONFLICTS_INSTALL=	flim-emacs_*

NO_ARCH=	yes

INFO=		mime-en mime-ja

OPTIONS_DEFINE=	DOCS

do-build:
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
