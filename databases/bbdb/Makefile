# Created by: Yoichi NAKAYAMA <yoichi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	bbdb
PORTVERSION=	2.35
PORTREVISION=	9
CATEGORIES=	databases elisp
MASTER_SITES=	SF
PKGNAMESUFFIX=	-${EMACS_PORT_NAME}

MAINTAINER=	dryice@FreeBSD.org
COMMENT=	Big Brother Database

USE_EMACS=	yes

USES=		makeinfo
ALL_TARGET=	bbdb info
MAKE_ARGS=	MAKE="${MAKE} clean MAKEINFO=\"makeinfo --no-split\""
BBDB_LISPDIR=	${EMACS_VERSION_SITE_LISPDIR}/${PORTNAME}
PLIST_SUB+=	BBDB_LISPDIR=${BBDB_LISPDIR}
MAKE_JOBS_UNSAFE=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-emacs=${EMACS_CMD}

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}
INFO=	bbdb
.endif

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/${EMACS_VERSION_SITE_LISPDIR}/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/lisp/*.el ${WRKSRC}/lisp/*.elc ${STAGEDIR}${PREFIX}/${EMACS_VERSION_SITE_LISPDIR}/${PORTNAME}
.if ${PORT_OPTIONS:MDOCS}
	${INSTALL_DATA} ${WRKSRC}/texinfo/bbdb.info ${STAGEDIR}${PREFIX}/info
.endif

.include <bsd.port.mk>
