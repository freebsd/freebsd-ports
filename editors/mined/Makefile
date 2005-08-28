# New ports collection makefile for:	mined
# Date created:		24 December 2004
# Whom:			thierry@pompo.net
#
# $FreeBSD$
#

PORTNAME=	mined
PORTVERSION=	2000.11
CATEGORIES=	editors
MASTER_SITES=	http://towo.net/mined/

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Text mode editor with Unicode support

MAKEFILE=	makefile

.if defined(NOPORTDOCS)
ALL_TARGET=	mined manual
.else
PORTDOCS=	*
.endif

USE_GMAKE=	YES
MAKE_ARGS=	GMAKE=${GMAKE} CC=${CC:T} OPT="${CFLAGS}"
INSTALL_TARGET=	localinstall

MAN1=		mined.1

pre-build:
	${MV} ${WRKSRC}/src/mkinclud.cc ${WRKSRC}/src/mkinclud.cc.bak
	${CP} ${WRKSRC}/src/mkinclud.gcc ${WRKSRC}/src/mkinclud.cc
	(if [ ! -f ${WRKSRC}/src/mkinclud.${CC:T} ] ; then	\
	${LN} -sf ${WRKSRC}/src/mkinclud.cc ${WRKSRC}/src/mkinclud.${CC:T} ; \
	fi)
	@${ECHO_MSG}
	@${ECHO_MSG} "Warning: conversion of all keyboard mapping tables may take a long time!"
	@${ECHO_MSG}

post-install:
	@${RM} ${DATADIR}/LICENSE.GNU ${DATADIR}/*.bat
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	cd ${WRKSRC}/doc && ${INSTALL_DATA} * ${DOCSDIR}
.endif

.include <bsd.port.mk>
