# New ports collection makefile for:	lsdb (for emacs21)
# Date Created:		27 Apr 2002
# Whom:			Yoichi NAKAYAMA <yoichi@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	lsdb
PORTVERSION=	0.10
PORTREVISION=	4
CATEGORIES=	databases elisp
MASTER_SITES=	http://downloads.sourceforge.jp/lsdb/${SFJP_RELEASE_ID}/
PKGNAMESUFFIX=	-${EMACS_PORT_NAME}

MAINTAINER=	yoichi@FreeBSD.org
COMMENT=	Lovely Sister Database

BUILD_DEPENDS=	${LOCALBASE}/share/flim/${FLIM_COOKIE}:${PORTSDIR}/editors/flim${DEPPORT_SUFFIX}

USE_EMACS=	yes

.include <bsd.port.pre.mk>

.if ${EMACS_PORT_NAME} == emacs20
DEPPORT_SUFFIX=	-${EMACS_PORT_NAME}
.else
DEPPORT_SUFFIX=
.endif

SFJP_RELEASE_ID=	1494
FLIM_COOKIE=	flim-${EMACS_PORT_NAME}-1.14.FreeBSD-packages

ALL_TARGET=	elc
MAKE_ARGS+=	LISPDIR=${PREFIX}/${EMACS_VERSION_SITE_LISPDIR}

post-patch:
	${REINPLACE_CMD} -e "s@ChangeLog:@ChangeLog:#@g" ${WRKSRC}/Makefile
post-install:
	${INSTALL_DATA} ${WRKSRC}/bbdb-to-lsdb.el ${PREFIX}/${EMACS_VERSION_SITE_LISPDIR}/${PORTNAME}
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA}	${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
