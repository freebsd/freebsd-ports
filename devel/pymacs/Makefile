# New ports collection makefile for: pymacs
# Date created:		23 July 2005
# Whom:			mwm@mired.org
#
# $FreeBSD$
#

PORTNAME=	Pymacs
PORTVERSION=	0.22
PORTREVISION=	2
CATEGORIES=	devel editors python elisp
MASTER_SITES=	http://pymacs.progiciels-bpi.ca/archives/ \
		${MASTER_SITE_GENTOO}
MASTER_SITE_SUBDIR=	distfiles

MAINTAINER=	mwm@mired.org
COMMENT=	A Python package for scripting emacs

USE_PYTHON=	yes
USE_PYDISTUTILS=yes
USE_PYTHON_PREFIX=	yes
USE_EMACS=	yes

.if !defined(EMACS_PORT_NAME)
EMACS_PORT_NAME=xemacs21
.endif

post-patch:
.for f in __init__.py pymacs.py
	${REINPLACE_CMD} -e 's,# Copyright,# coding:latin1 Copyright,g' \
		${WRKSRC}/Pymacs/$f
.endfor

# Install the emacs side of things
post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/pymacs.el ${PREFIX}/${EMACS_SITE_LISPDIR}
	${EMACS_NAME} -batch -f batch-byte-compile \
		${PREFIX}/${EMACS_SITE_LISPDIR}/pymacs.el

.include <bsd.port.mk>
