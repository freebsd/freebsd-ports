# New ports collection makefile for:	lsdb (for emacs21)
# Date Created:		27 Apr 2002
# Whom:			Yoichi NAKAYAMA <yoichi@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	lsdb
PORTVERSION=	0.11
PORTREVISION=	2
CATEGORIES=	databases elisp
MASTER_SITES=	SFJP/${PORTNAME}/7488
PKGNAMESUFFIX=	-${EMACS_PORT_NAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Lovely Sister Database

LICENSE=	GPLv2 # (or later)

BUILD_DEPENDS=	${LOCALBASE}/share/flim/${FLIM_COOKIE}:${PORTSDIR}/editors/flim${DEPPORT_SUFFIX}

USE_EMACS=	yes
MAKE_ARGS=	LISPDIR="${PREFIX}/${EMACS_VERSION_SITE_LISPDIR}"
ALL_TARGET=	elc

FLIM_COOKIE=   flim-${EMACS_PORT_NAME}-1.14.FreeBSD-packages

.include <bsd.port.pre.mk>

.if defined(EMACS_PORT_NAME)
.if (${EMACS_PORT_NAME} == "emacs23") || (${EMACS_PORT_NAME} == "emacs-devel")
DEPPORT_SUFFIX=
.else
DEPPORT_SUFFIX=	-${EMACS_PORT_NAME}
.endif
.endif

post-patch:
	${REINPLACE_CMD} -e "s@ChangeLog:@ChangeLog:#@g" ${WRKSRC}/Makefile

post-install:
	${INSTALL_DATA} ${WRKSRC}/bbdb-to-lsdb.el ${PREFIX}/${EMACS_VERSION_SITE_LISPDIR}/${PORTNAME}
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA}	${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
