# New ports collection makefile for:	elisp-info.el
# Date Created:		21 Jan 2002
# Whom:			Yoichi NAKAYAMA <yoichi@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	elisp-info
PORTVERSION=	2.11
CATEGORIES=	japanese elisp
MASTER_SITES=	http://namazu.org/~tsuchiya/elisp/
DISTNAME=	${PORTNAME}
EXTRACT_SUFX=	.el

MAINTAINER=	yoichi@FreeBSD.org

BUILD_DEPENDS=	${LOCALBASE}/info/elisp-ja:${PORTSDIR}/japanese/elisp-manual
RUN_DEPENDS=	${LOCALBASE}/info/elisp-ja:${PORTSDIR}/japanese/elisp-manual

NO_WRKSUBDIR=	yes
EXTRACT_CMD=	${CP}
EXTRACT_BEFORE_ARGS=	-p
EXTRACT_AFTER_ARGS=	./

EMACS_PORT_NAME?=	emacs21
EMACS_NO_RUN_DEPENDS=	yes
LISPDIR?=	${PREFIX}/${EMACS_SITE_LISPDIR}/${PORTNAME}

post-extract:
	${CP} ${FILESDIR}/ELISP_CFG ${WRKDIR}
do-build:
	(cd ${WRKDIR}; \
	${EMACS_CMD} -batch -l ./ELISP_CFG -l ./${PORTNAME}.el -f ${PORTNAME}-make-index)
do-install:
	${MKDIR} ${LISPDIR}
	${INSTALL_DATA} ${WRKDIR}/${PORTNAME}.el ${LISPDIR}
	${INSTALL_DATA} ${WRKDIR}/${PORTNAME}-index.el ${LISPDIR}
	${INSTALL_DATA} ${FILESDIR}/${PORTNAME}-setup.el ${LISPDIR}

.include <bsd.port.mk>
