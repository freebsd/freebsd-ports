# New ports collection makefile for:   weather
# Date Created:			5 Mar 2001
# Whom:				Yoichi NAKAYAMA <yoichi@eken.phys.nagoya-u.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	weather
PORTVERSION=	0.19
CATEGORIES=	japanese elisp
MASTER_SITES=	ftp://ftp.opaopa.org/pub/elisp/ \
		ftp://ftp.ring.gr.jp/pub/text/elisp/jaist/ftp.opaopa.org/elisp/ \
		ftp://ftp.jaist.ac.jp/pub/GNU/elisp/ftp.opaopa.org/elisp/
PKGNAMESUFFIX=	-${EMACS_PORT_NAME}

MAINTAINER=	yoichi@eken.phys.nagoya-u.ac.jp

BUILD_DEPENDS=	${LOCALBASE}/${EMACS_LIBDIR_WITH_VER}/site-lisp/emu/emu.el:${PORTSDIR}/editors/apel-emacs20
RUN_DEPENDS=	${LOCALBASE}/${EMACS_LIBDIR_WITH_VER}/site-lisp/emu/emu.el:${PORTSDIR}/editors/apel-emacs20

EMACS_PORT_NAME=emacs20

DOCS=		README

DOCSDIR=	${PREFIX}/share/doc/${PORTNAME}

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/${DOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
