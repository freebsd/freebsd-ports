# New ports collection makefile for:   weather
# Date Created:			5 Mar 2001
# Whom:				Yoichi NAKAYAMA <yoichi@eken.phys.nagoya-u.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	weather
PORTVERSION=	0.29
CATEGORIES=	japanese elisp
MASTER_SITES=	ftp://ftp.opaopa.org/pub/elisp/ \
		ftp://ftp.ring.gr.jp/pub/text/elisp/jaist/ftp.opaopa.org/elisp/ \
		ftp://ftp.jaist.ac.jp/pub/GNU/elisp/ftp.opaopa.org/elisp/
PKGNAMESUFFIX=	-${EMACS_PORT_NAME}

MAINTAINER=	yoichi@FreeBSD.org

EMACS_PORT_NAME?=	emacs20

.if ${EMACS_PORT_NAME} != "emacs21"
PORTNAMESUFFIX=	${PKGNAMESUFFIX}
.endif

BUILD_DEPENDS=	${LOCALBASE}/${EMACS_VERSION_SITE_LISPDIR}/emu/emu.el:${PORTSDIR}/editors/apel${PORTNAMESUFFIX}
RUN_DEPENDS=	${LOCALBASE}/${EMACS_VERSION_SITE_LISPDIR}/emu/emu.el:${PORTSDIR}/editors/apel${PORTNAMESUFFIX}

DOCS=		README

DOCSDIR=	${PREFIX}/share/doc/${PORTNAME}
MAKE_ARGS+=	LISPDIR=${PREFIX}/${EMACS_VERSION_SITE_LISPDIR}

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/${DOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
