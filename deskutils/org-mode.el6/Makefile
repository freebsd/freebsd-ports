# New ports collection makefile for:	org-mode.el6
# Date created:		2008-07-21
# Whom:			Thinker K.F. Li <thinker@branda.to>
#
# $FreeBSD$
#

PORTNAME=	org-mode.el
PORTVERSION=	6.05b
PORTREVISION=	1
CATEGORIES=	deskutils elisp
MASTER_SITES=	http://orgmode.org/
PKGNAMESUFFIX=	-${EMACS_PORT_NAME}
DISTNAME=	org-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An Emacs mode for notes and project planning

USE_EMACS=	yes
USE_GMAKE=	yes
EMACS_PORT_NAME?=	emacs22
MAKE_FLAGS=	prefix=${PREFIX}

.include <bsd.port.pre.mk>
.include <bsd.port.post.mk>
