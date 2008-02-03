# New ports collection makefile for:	remember.el
# Date created:				March 09 2005
# Whom:					Dryice Liu <dryice@liu.com.cn>
#
# $FreeBSD$
#

PORTNAME=	remember.el
PORTVERSION=	1.9
PORTREVISION=	2
CATEGORIES=	deskutils elisp
MASTER_SITES=	http://download.gna.org/remember-el/ \
		http://dryice.name/computer/FreeBSD/distfiles/
PKGNAMESUFFIX=	-${EMACS_PORT_NAME}
DISTNAME=	remember-${DISTVERSIONPREFIX}${DISTVERSION}${DISTVERSIONSUFFIX}

MAINTAINER=	dryice@dryice.name
COMMENT=	A Emacs mode for remembering data

BROKEN=		Conflicting dependencies

USE_EMACS=	yes
USE_GMAKE=	yes
EMACS_PORT_NAME?=	emacs21

INFO=		remember-el

OPTIONS=	BBDB "BBDB support" on
OPTIONS+=	PLANNER "Planner.el support" on

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_BBDB)
.if ${EMACS_NAME} == "xemacs"
BUILD_DEPENDS+=	${PREFIX}/${EMACS_LIBDIR}/xemacs-packages/lisp/bbdb/bbdb-com.el:${PORTSDIR}/editors/xemacs-packages
.else
BUILD_DEPENDS+=	${PREFIX}/${EMACS_VERSION_SITE_LISPDIR}/bbdb/bbdb-com.el:${PORTSDIR}/databases/bbdb
.endif
PLIST_SUB+=	HAS_BBDB=""
.else
PLIST_SUB+=	HAS_BBDB="@comment "
.endif

.if !defined(WITHOUT_PLANNER)
BUILD_DEPENDS+=	${PREFIX}/${EMACS_SITE_LISPDIR}/planner/planner.el:${PORTSDIR}/deskutils/planner.el
PLIST_SUB+=	HAS_PLANNER=""
.else
PLIST_SUB+=	HAS_PLANNER="@comment "
.endif
RUN_DEPENDS+= ${BUILD_DEPENDS}

.include <bsd.port.post.mk>
