# New ports collection makefile for:	caml-mode.el
# Date created:		23 October 2001
# Whom:			J Koshy <jkoshy@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	caml-mode
PORTVERSION=	3.01
CATEGORIES=	lang elisp
MASTER_SITES=	http://wwwfun.kurims.kyoto-u.ac.jp/soft/olabl/dist/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	jkoshy
DISTNAME=	ocaml-mode-3.01

MAINTAINER=	jkoshy@FreeBSD.org

BUILD_DEPENDS=	emacs:${PORTSDIR}/editors/emacs21
RUN_DEPENDS=	emacs:${PORTSDIR}/editors/emacs21

NO_BUILD=	yes

#
# Install configuration
#

ELISP_SUBDIR=	${PREFIX}/share/emacs/site-lisp/
CAMLMODE_ELISPDIR= ${ELISP_SUBDIR}/caml-mode
CAMLMODE_DOCDIR=	share/doc/caml-mode
CAMLMODE_DIR_ENTRY=* Caml-mode: (caml-mode).         A mode for editing CAML programs.

INSTALL_TARGET=	install install-ocamltags
MAKE_ENV+=	EMACSDIR=${CAMLMODE_ELISPDIR}

.include <bsd.port.mk>
