# ex:ts=8
# Ports collection makefile for:	texmaker
# Date created:			Dec 29, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	texmaker
PORTVERSION=	1.0
CATEGORIES=	editors
MASTER_SITES=	http://perso.club-internet.fr/pascal.brachet/texmaker/
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	LaTeX Development Environment

USE_BZIP2=	yes
USE_QT_VER=	3

do-build:
	@cd ${WRKSRC} && \
	 qmake -makefile -unix "LIBS+=-lm -lqt-mt" texmaker.pro && \
	 ${SETENV} QTDIR=${X11BASE} make

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/texmaker ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/*.html ${DOCSDIR}
.endif

.include <bsd.port.mk>
