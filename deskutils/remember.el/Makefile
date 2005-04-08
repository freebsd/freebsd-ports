# New ports collection makefile for:	remember.el
# Date created:				March 09 2005
# Whom:					Dryice Liu <dryice@liu.com.cn>
#
# $FreeBSD$
#

PORTNAME=	remember.el
PORTVERSION=	1.6
CATEGORIES=	deskutils elisp
MASTER_SITES=	http://sacha.free.net.ph/notebook/emacs/planner/ \
		http://bsdchat.com/dist/dryice/
PKGNAMESUFFIX=	-${EMACS_PORT_NAME}
DISTNAME=	remember-el-${DISTVERSIONPREFIX}${DISTVERSION}${DISTVERSIONSUFFIX}

MAINTAINER=	dryice@liu.com.cn
COMMENT=	A Emacs mode for remembering data

EMACS_PORT_NAME?=	emacs21

.if ${EMACS_PORT_NAME} != "emacs21"
PORTNAMESUFFIX=	${PKGNAMESUFFIX}
.endif

OPTIONS=	BBDB "BBDB support" on
OPTIONS+=	PLANNER "Planner.el support" on

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_BBDB)
RUN_DEPENDS+=	${PREFIX}/${EMACS_VERSION_SITE_LISPDIR}/bbdb/bbdb-com.el:${PORTSDIR}/databases/bbdb
.endif

.if !defined(WITHOUT_PLANNER)
RUN_DEPENDS+=	${PREFIX}/${EMACS_VERSION_SITE_LISPDIR}/planner/planner.el:${PORTSDIR}/deskutils/planner.el
.endif

INFO=		remember-el
LISPDIR=	${PREFIX}/${EMACS_VERSION_SITE_LISPDIR}/remember

do-build:
	cd ${WRKSRC}; makeinfo --no-split remember.texi

do-install:
	${MKDIR} ${LISPDIR}
.for i in *.el
	${INSTALL_DATA} ${WRKSRC}/${i} ${LISPDIR}
.endfor
	${INSTALL_DATA} ${WRKSRC}/remember-el.info ${PREFIX}/info

.include <bsd.port.post.mk>
