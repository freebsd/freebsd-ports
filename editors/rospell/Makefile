# New ports collection makefile for:	rospell
# Date created:				2005-11-04
# Whom:			Ion-Mihai "IOnut" Tetcu <itetcu@people.tecnik93.com>
#
# $Tecnik: ports/editors/rospell/Makefile,v 1.4 2006/05/15 10:49:31 itetcu Exp $
# $FreeBSD$

PORTNAME=	rospell
PORTVERSION=	2006.00
CATEGORIES=	editors textproc # this should/will be romanian ;)
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	itetcu@people.tecnik93.com
COMMENT=	QT-based editor with support for romanian charsets and spell checking

USE_XLIB=	yes
USE_QT_VER=	3
MAKE_ENV+=	PTHREAD_CFLAGS=${PTHREAD_CFLAGS} PTHREAD_LIBS=${PTHREAD_LIBS}
CONFIGURE_ENV=	QTDIR=${X11BASE} LDFLAGS="${LDFLAGS} ${PTHREAD_LIBS}"

MAKEFILE=	BSDmakefile

MAN1=	rospell.1

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
IGNORE=		doesn't compile properly on 4.x systems
.endif

do-configure:
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE} -f ${MAKEFILE} dictfiles.h

do-build:
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE} -f ${MAKEFILE} ${ALL_TARGET}

do-install:
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE} -f ${MAKEFILE} ${INSTALL_TARGET}

.include <bsd.port.post.mk>
