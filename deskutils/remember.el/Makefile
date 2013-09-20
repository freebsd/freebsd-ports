# Created by: Dryice Liu <dryice@liu.com.cn>
# $FreeBSD$

PORTNAME=	remember.el
PORTVERSION=	2.0
PORTREVISION=	10
CATEGORIES=	deskutils elisp
MASTER_SITES=	http://download.gna.org/remember-el/
PKGNAMESUFFIX=	-${EMACS_PORT_NAME}
DISTNAME=	remember-${DISTVERSIONPREFIX}${DISTVERSION}${DISTVERSIONSUFFIX}

MAINTAINER=	dryice@dryice.name
COMMENT=	A Emacs mode for remembering data

USE_EMACS=	yes
USE_GMAKE=	yes

INFO=		remember remember-extra

OPTIONS_DEFINE=	BBDB PLANNER
BBDB_DESC=	BBDB support
PLANNER_DESC=	Planner.el support

NO_STAGE=	yes
.include <bsd.port.pre.mk>

.if (${EMACS_PORT_NAME} == "emacs23") || (${EMACS_PORT_NAME} == "emacs24") || (${EMACS_PORT_NAME} == "emacs-devel")
IGNORE=		incorporated into Emacs 23/24
.endif

.if ${PORT_OPTIONS:MBBDB}
.if ${EMACS_NAME} == "xemacs"
BUILD_DEPENDS+=	${LOCALBASE}/${EMACS_LIBDIR}/xemacs-packages/lisp/bbdb/bbdb-com.el:${PORTSDIR}/editors/xemacs-packages
.else
BUILD_DEPENDS+=	${LOCALBASE}/${EMACS_VERSION_SITE_LISPDIR}/bbdb/bbdb-com.el:${PORTSDIR}/databases/bbdb
.endif
PLIST_SUB+=	HAS_BBDB=""
.else
PLIST_SUB+=	HAS_BBDB="@comment "
.endif

.if ${PORT_OPTIONS:MPLANNER}
BUILD_DEPENDS+=	${LOCALBASE}/${EMACS_SITE_LISPDIR}/planner/planner.el:${PORTSDIR}/deskutils/planner.el
PLIST_SUB+=	HAS_PLANNER=""
.else
PLIST_SUB+=	HAS_PLANNER="@comment "
.endif
RUN_DEPENDS+=	${BUILD_DEPENDS}

.include <bsd.port.post.mk>
