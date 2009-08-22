# New ports collection makefile for:	python-mode.el
# Date created:				11 October 2005
# Whom:					Dario Freni <saturnero@gufi.org
#
# $FreeBSD$
#

PORTNAME=	python-mode.el
PORTVERSION=	1.0
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	lang elisp python
MASTER_SITES=	SF/python-mode/OldFiles
DISTNAME=	python-mode-${PORTVERSION}

MAINTAINER=	saturnero@gufi.org
COMMENT=	Emacs lisp module for the Python language

NO_BUILD=	yes

CONFLICTS=	python-2.4.[012]*
EMACSLISPDIR=	${PREFIX}/share/emacs/site-lisp
XEMACSLISPDIR=	${PREFIX}/lib/xemacs/site-lisp

LISPFILES=	doctest-mode.el pycomplete.el pycomplete.py python-mode.el

do-install:
	${MKDIR} ${EMACSLISPDIR}
	${MKDIR} ${XEMACSLISPDIR}
	for i in ${LISPFILES}; do \
		${INSTALL_DATA} ${WRKSRC}/$${i} ${EMACSLISPDIR}/$${i}; \
		${LN} -sf ${EMACSLISPDIR}/$${i} ${XEMACSLISPDIR}; \
	done;

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
