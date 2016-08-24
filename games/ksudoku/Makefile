# $FreeBSD$

PORTNAME=	ksudoku
PORTVERSION=	${KDE4_VERSION}
CATEGORIES=	games kde
MASTER_SITES=	KDE/${KDE4_BRANCH}/${PORTVERSION}/src
DIST_SUBDIR=	KDE/${PORTVERSION}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	${${PORTNAME}_DESC}

USES=		cmake:outsource kde:4 tar:xz
USE_GL=		glu
USE_KDE=	kdelibs libkdegames automoc4
USE_QT4=	corelib gui corelib gui opengl \
		moc_build qmake_build rcc_build uic_build

.include <${.CURDIR}/../kdegames4/Makefile.common>
.include <bsd.port.mk>
