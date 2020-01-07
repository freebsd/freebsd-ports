# Created by: Yoichi NAKAYAMA <yoichi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	bbdb
DISTVERSIONPREFIX=	v
DISTVERSION=	3.2
PORTREVISION=	2
CATEGORIES=	databases elisp
PKGNAMESUFFIX=	${EMACS_PKGNAMESUFFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Big Brother Database

LICENSE=	GPLv3+

BUILD_DEPENDS=	texi2dvi:print/texinfo

USES=		autoreconf emacs
USE_GITHUB=	yes
GH_ACCOUNT=	emacsmirror
USE_TEX=	latex:build

BBDB_LISPDIR=	${EMACS_SITE_LISPDIR}/${PORTNAME}
GNU_CONFIGURE=	yes
# Do not install the info file.  Upstream has yet to add any real content to it.
#INFO=		bbdb
PORTDOCS=	bbdb.pdf
NO_ARCH=	yes
PLIST_SUB+=	BBDB_LISPDIR=${BBDB_LISPDIR}

OPTIONS_DEFINE=	DOCS

# See http://lists.nongnu.org/archive/html/bbdb-user/2018-11/msg00003.html
.if ${FLAVOR:U} != devel_full && ${FLAVOR:U} != devel_nox
post-configure:
	${REINPLACE_CMD} -e '/[[:blank:]]*--eval '\''(setq byte-compile-dest-file-function (lambda (_) "$$@"))'\'' \\/d' \
		${WRKSRC}/lisp/Makefile
.endif

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${BBDB_LISPDIR}
	${INSTALL_DATA} ${WRKSRC}/lisp/*.el ${WRKSRC}/lisp/*.elc \
		${STAGEDIR}${PREFIX}/${BBDB_LISPDIR}
# Do not install the info file.  Upstream has yet to add any real content to it.
#	${INSTALL_DATA} ${WRKSRC}/doc/${PORTNAME}.info \
#		${STAGEDIR}${PREFIX}/${INFO_PATH}

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/bbdb.pdf ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
