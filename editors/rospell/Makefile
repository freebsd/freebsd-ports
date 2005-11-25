# New ports collection makefile for:	rospell
# Date created:				2005-11-04
# Whom:			Ion-Mihai "IOnut" Tetcu <itetcu@people.tecnik93.com>
#
# $FreeBSD$
# $Id: Makefile,v 1.1 2005/11/20 18:17:56 itetcu Rel $
#

PORTNAME=	rospell
PORTVERSION=	2005.03.b1
CATEGORIES=	editors textproc # this should/will be romanian ;)
MASTER_SITES=	http://people.tecnik93.com/~itetcu/FreeBSD/ports/${PORTNAME}/sources/
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	itetcu@people.tecnik93.com
COMMENT=	QT-based editor with support for romanian charsets and spell checking

USE_XLIB=	yes
USE_QT_VER=	3
MAKE_ENV+=	PTHREAD_CFLAGS=${PTHREAD_CFLAGS} PTHREAD_LIBS=${PTHREAD_LIBS}

MAN1=	rospell.1

do-build:
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE}

do-install:
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE} install

.include <bsd.port.mk>
