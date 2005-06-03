# New ports collection makefile for:	planner.el
# Date created:				March 09 2005
# Whom:					Dryice Liu <dryice@liu.com.cn>
#
# $FreeBSD$
#

PORTNAME=	planner.el
PORTVERSION=	3.30
CATEGORIES=	deskutils elisp
MASTER_SITES=	http://sacha.free.net.ph/notebook/emacs/planner/ \
		http://bsdchat.com/dist/dryice/
PKGNAMESUFFIX=	-${EMACS_PORT_NAME}
DISTNAME=	planner-el-${DISTVERSIONPREFIX}${DISTVERSION}${DISTVERSIONSUFFIX}

MAINTAINER=	dryice@liu.com.cn
COMMENT=	PlannerMode is an organizer and day planner for Emacs

EMACS_PORT_NAME?=	emacs21

.if ${EMACS_PORT_NAME} != "emacs21"
PORTNAMESUFFIX=	${PKGNAMESUFFIX}
.endif

RUN_DEPENDS+=	${LOCALBASE}/${EMACS_VERSION_SITE_LISPDIR}/emacs-wiki/emacs-wiki.el:${PORTSDIR}/textproc/emacs-wiki

OPTIONS=	BBDB "BBDB support" off
OPTIONS+=	ERC "ERC support" off
OPTIONS+=	VM "View Mail support" off
OPTIONS+=	W3M "W3M support" off
OPTIONS+=	WL "Wanderlust support" off
OPTIONS+=	XTLA "XTLA support" off

.include <bsd.port.pre.mk>

.if defined(WITH_BBDB)
RUN_DEPENDS+=	${LOCALBASE}/${EMACS_VERSION_SITE_LISPDIR}/bbdb/bbdb-com.el:${PORTSDIR}/databases/bbdb
.endif

.if defined(WITH_ERC)
RUN_DEPENDS+=	${LOCALBASE}/${EMACS_VERSION_SITE_LISPDIR}/erc/erc.el:${PORTSDIR}/irc/erc
.endif

.if defined(WITH_VM)
RUN_DEPENDS+=	qp-decode:${PORTSDIR}/mail/vm
.endif

.if defined(WITH_W3M)
RUN_DEPENDS+=	${LOCALBASE}/${EMACS_VERSION_SITE_LISPDIR}/w3m/w3m.el:${PORTSDIR}/www/emacs-w3m
.endif

.if defined(WITH_WL)
RUN_DEPENDS+=	${LOCALBASE}/${EMACS_VERSION_SITE_LISPDIR}/wl/wl.el:${PORTSDIR}/mail/wanderlust
.endif

.if defined(WITH_XTLA)
RUN_DEPENDS+=	${LOCALBASE}/${EMACS_VERSION_SITE_LISPDIR}/xtla/xtla.el:${PORTSDIR}/devel/xtla
.endif

INFO=		planner-el
LISPDIR=	${PREFIX}/${EMACS_VERSION_SITE_LISPDIR}/planner

do-build:
	cd ${WRKSRC}; makeinfo --no-split planner-el.texi

do-install:
	${MKDIR} ${LISPDIR}
.for i in *.el
	${INSTALL_DATA} ${WRKSRC}/${i} ${LISPDIR}
.endfor
	${INSTALL_DATA} ${WRKSRC}/planner-el.info ${PREFIX}/info

.include <bsd.port.post.mk>
