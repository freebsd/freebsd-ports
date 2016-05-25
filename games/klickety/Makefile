# $FreeBSD$

PORTNAME=	klickety
PORTVERSION=	${KDE4_VERSION}
PORTREVISION=	1
CATEGORIES=	games kde
MASTER_SITES=	KDE/${KDE4_BRANCH}/${PORTVERSION}/src
DIST_SUBDIR=	KDE/${PORTVERSION}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	${${PORTNAME}_DESC}

USE_KDE4=	kdelibs libkdegames automoc4
USES=		cmake:outsource shebangfix tar:xz
SHEBANG_FILES=	klickety-2.0-inherit-ksame-highscore.pl
USE_QT4=	corelib gui xml \
		moc_build qmake_build rcc_build uic_build

.include <${.CURDIR}/../kdegames4/Makefile.common>
.include <bsd.port.mk>
