# New ports collection makefile for:	bbdb (for emacs21)
# Date Created:		12 Dec 2001
# Whom:			Yoichi NAKAYAMA <yoichi@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	bbdb
PORTVERSION=	2.35
PORTREVISION=	6
CATEGORIES=	databases elisp
MASTER_SITES=	SF
PKGNAMESUFFIX=	-${EMACS_PORT_NAME}

MAINTAINER=	dryice@FreeBSD.org
COMMENT=	Big Brother Database

USE_EMACS=	yes

ALL_TARGET=	bbdb info
MAKE_ARGS=	MAKE="${MAKE} clean MAKEINFO=\"makeinfo --no-split\""
BBDB_LISPDIR=	${EMACS_VERSION_SITE_LISPDIR}/${PORTNAME}
DIRSECTION=	"The Emacs editor and associated tools"
INFOENTRY=	"* BBDB: (bbdb).             The Insidious Big Brother Database."
PLIST_SUB+=	BBDB_LISPDIR=${BBDB_LISPDIR} \
		DIRSECTION=${DIRSECTION} INFOENTRY=${INFOENTRY}
MAKE_JOBS_UNSAFE=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-emacs=${EMACS_CMD}

do-install:
	${MKDIR} ${PREFIX}/${EMACS_VERSION_SITE_LISPDIR}/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/lisp/*.el ${WRKSRC}/lisp/*.elc ${PREFIX}/${EMACS_VERSION_SITE_LISPDIR}/${PORTNAME}
.if !defined(NOPORTDOCS)
	${INSTALL_DATA} ${WRKSRC}/texinfo/bbdb.info ${PREFIX}/info
	install-info --section=${DIRSECTION} --entry=${INFOENTRY} ${PREFIX}/info/bbdb.info ${PREFIX}/info/dir
.endif

.include <bsd.port.mk>
