# New ports collection makefile for:	STk
# Date created:		17 Sep 96
# Whom:			jmacd@cs.berkeley.edu
#
# $FreeBSD$
#

PORTNAME=	STk
PORTVERSION=	4.0.1
CATEGORIES=	lang scheme
MASTER_SITES=	${MASTER_SITE_SUNSITE} \
		ftp://kaolin.unice.fr/pub/STk/
MASTER_SITE_SUBDIR=	devel/lang/lisp

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A scheme interpreter with full access to the Tk graphical package

USE_XLIB=	yes
GNU_CONFIGURE=	yes

PLIST_SUB=	STK_VERSION=${PORTVERSION} STK_ARCH=${STK_ARCH}

STK_ARCH!=	${ECHO} "$$(uname)-$$(uname -r)-$$(uname -m)"

.include <bsd.port.pre.mk>

.if ${ARCH} == "sparc64"
BROKEN=		"Does not compile on sparc64"
.endif

.include <bsd.port.post.mk>
