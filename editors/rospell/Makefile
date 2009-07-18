# New ports collection makefile for:	rospell
# Date created:				2005-11-04
# Whom:			Ion-Mihai "IOnut" Tetcu <itetcu@people.tecnik93.com>
#
# $FreeBSD$

PORTNAME=	rospell
DISTVERSION=	2007.02.rc1
PORTREVISION=	2
CATEGORIES=	editors textproc # this should/will be romanian ;)
MASTER_SITES=	SF

MAINTAINER=	itetcu@FreeBSD.org
COMMENT=	QT-based editor with support for romanian charsets and spell checking

BUILD_DEPENDS+=	exctags:${PORTSDIR}/devel/ctags
RUN_DEPENDS+=	exctags:${PORTSDIR}/devel/ctags
LIB_DEPENDS+=	jpeg:${PORTSDIR}/graphics/jpeg

USE_XORG=	x11 xext
USE_QT_VER=	3

MAKE_ENV+=	PTHREAD_CFLAGS=${PTHREAD_CFLAGS} PTHREAD_LIBS=${PTHREAD_LIBS}
CONFIGURE_ENV=	LDFLAGS="${LDFLAGS} ${PTHREAD_LIBS}"

MAKEFILE=	BSDmakefile

MAN1=	rospell.1

.include <bsd.port.pre.mk>

do-configure:
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE} -f ${MAKEFILE} dictfiles.h

do-build:
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE} -f ${MAKEFILE} ${ALL_TARGET}

do-install:
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE} -f ${MAKEFILE} ${INSTALL_TARGET}

.include <bsd.port.post.mk>
