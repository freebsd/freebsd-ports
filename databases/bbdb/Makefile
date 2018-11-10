# Created by: Yoichi NAKAYAMA <yoichi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	bbdb
DISTVERSION=	3.1.2
PORTREVISION=	1
CATEGORIES=	databases elisp
MASTER_SITES=	SAVANNAH
PKGNAMESUFFIX=	${EMACS_PKGNAMESUFFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Big Brother Database

LICENSE=	GPLv3+

.if ${FLAVOR:U} != devel && ${FLAVOR:U} != devel_nox
# http://pkg.awarnach.mathstat.dal.ca/data/11i386-default/2018-05-30_07h36m11s/logs/errors/bbdb-emacs26-3.1.2_1.log
BROKEN=		fails to build
.endif

# do not depend on base texinfo on 10
BUILD_DEPENDS=	texi2dvi:print/texinfo

USES=		emacs
USE_TEX=	latex:build

BBDB_LISPDIR=	${EMACS_SITE_LISPDIR}/${PORTNAME}
GNU_CONFIGURE=	yes
INFO=		bbdb
PORTDOCS=	bbdb.pdf
NO_ARCH=	yes
PLIST_SUB+=	BBDB_LISPDIR=${BBDB_LISPDIR}

OPTIONS_DEFINE=	DOCS

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${BBDB_LISPDIR}
	${INSTALL_DATA} ${WRKSRC}/lisp/*.el ${WRKSRC}/lisp/*.elc \
		${STAGEDIR}${PREFIX}/${BBDB_LISPDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/${PORTNAME}.info \
		${STAGEDIR}${PREFIX}/${INFO_PATH}

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/bbdb.pdf ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
