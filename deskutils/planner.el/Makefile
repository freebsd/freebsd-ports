# New ports collection makefile for:	planner.el
# Date created:				March 09 2005
# Whom:					Dryice Liu <dryice@liu.com.cn>
#
# $FreeBSD$
#

PORTNAME=	planner.el
PORTVERSION=	3.42
PORTREVISION=	3
CATEGORIES=	deskutils elisp
MASTER_SITES=	http://download.gna.org/planner-el/ \
		http://dryice.name/computer/FreeBSD/distfiles/
PKGNAMESUFFIX=	-${EMACS_PORT_NAME}
DISTNAME=	planner-${DISTVERSIONPREFIX}${DISTVERSION}${DISTVERSIONSUFFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	PlannerMode is an organizer and day planner for Emacs

USE_EMACS=	yes
USE_GMAKE=	yes

BUILD_DEPENDS+=	${LOCALBASE}/${EMACS_SITE_LISPDIR}/muse/muse.el:${PORTSDIR}/textproc/muse

OPTIONS=	BBDB "BBDB support" off
OPTIONS+=	GNATS "GNATS support" off
OPTIONS+=	PSVN "PSVN support" off
OPTIONS+=	VM "View Mail support" off
OPTIONS+=	W3M "W3M support" off
OPTIONS+=	WL "Wanderlust support" off
OPTIONS+=	XTLA "XTLA support" off

.include <bsd.port.pre.mk>

.if ${EMACS_PORT_NAME} != "emacs23"
PORTNAMESUFFIX=	${PKGNAMESUFFIX}
.endif

.if (${EMACS_PORT_NAME} == "emacs21")
PLIST_SUB+=	HAS_ICAL="@comment "
.else
PLIST_SUB+=	HAS_ICAL=""
.endif

.if defined(WITH_BBDB)
BUILD_DEPENDS+=	${LOCALBASE}/${EMACS_VERSION_SITE_LISPDIR}/bbdb/bbdb-com.el:${PORTSDIR}/databases/bbdb
PLIST_SUB+=	HAS_BBDB=""
.else
PLIST_SUB+=	HAS_BBDB="@comment "
.endif

.if (${EMACS_PORT_NAME} == "emacs21")
PLIST_SUB+=	HAS_ERC="@comment "
.else
# emacs 22 and above has ERC build in
PLIST_SUB+=	HAS_ERC=""
.endif

.if defined(WITH_GNATS)
BUILD_DEPENDS+=	${LOCALBASE}/${EMACS_SITE_LISPDIR}/gnats.el:${PORTSDIR}/databases/gnats4
PLIST_SUB+=	HAS_GNATS=""
.else
PLIST_SUB+=	HAS_GNATS="@comment "
.endif

.if defined(WITH_PSVN)
BUILD_DEPENDS+=	${LOCALBASE}/${EMACS_VERSION_SITE_LISPDIR}/psvn/psvn.el:${PORTSDIR}/devel/psvn
PLIST_SUB+=	HAS_PSVN=""
.else
PLIST_SUB+=	HAS_PSVN="@comment "
.endif

.if defined(WITH_VM)
BUILD_DEPENDS+=	qp-decode:${PORTSDIR}/mail/vm
PLIST_SUB+=	HAS_VM=""
.else
PLIST_SUB+=	HAS_VM="@comment "
.endif

.if defined(WITH_W3M)
BUILD_DEPENDS+=	${LOCALBASE}/${EMACS_VERSION_SITE_LISPDIR}/w3m/w3m.el:${PORTSDIR}/www/emacs-w3m
PLIST_SUB+=	HAS_W3M=""
.else
PLIST_SUB+=	HAS_W3M="@comment "
.endif

.if defined(WITH_WL)
BUILD_DEPENDS+=	${LOCALBASE}/${EMACS_VERSION_SITE_LISPDIR}/wl/wl.el:${PORTSDIR}/mail/wanderlust
PLIST_SUB+=	HAS_WL=""
.else
PLIST_SUB+=	HAS_WL="@comment "
.endif

.if defined(WITH_XTLA)
BUILD_DEPENDS+=	${LOCALBASE}/${EMACS_VERSION_SITE_LISPDIR}/xtla/xtla.el:${PORTSDIR}/devel/xtla
PLIST_SUB+=	HAS_XTLA=""
.else
PLIST_SUB+=	HAS_XTLA="@comment "
.endif

RUN_DEPENDS+=	${BUILD_DEPENDS}

LISPDIR=	${PREFIX}/${EMACS_VERSION_SITE_LISPDIR}/planner

.if !defined(NOPORTDOCS)
PORTDOCS=	AUTHORS ChangeLog.1 ChangeLog.2 ChangeLog.3 ChangeLog \
		COMMENTARY NEWS README
.endif

post-patch:
	@${REINPLACE_CMD} 's,PREFIX   =,PREFIX   ?=,' ${WRKSRC}/Makefile.defs.default

pre-build:
	${CP} ${WRKSRC}/contrib/schedule.el ${WRKSRC}/schedule.el

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for i in ${PORTDOCS}
	${CP} -R ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>
