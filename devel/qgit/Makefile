# New ports collection makefile for:	qgit
# Date created:				2009-04-19
# Whom:				Ion-Mihai "IOnut" Tetcu <itetcu@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	qgit
PORTVERSION=	2.2
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	SF
PKGNAMESUFFIX=	-qt4

MAINTAINER=	itetcu@FreeBSD.org
COMMENT=	A graphical interface to git repositories

USE_BZIP2=	yes
USE_QT_VER=	4
QT_COMPONENTS=	corelib gui moc_build qmake_build rcc_build uic_build

WRKSRC=		${WRKDIR}/${PORTNAME}

PLIST_FILES=	bin/${PORTNAME}

do-configure:
	@cd ${WRKSRC} && ${QMAKE} ${PORTNAME}.pro

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/${PORTNAME} ${PREFIX}/bin

.include <bsd.port.mk>
