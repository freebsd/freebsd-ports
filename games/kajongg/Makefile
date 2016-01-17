# $FreeBSD$

PORTNAME=	kajongg
PORTVERSION=	${KDE4_VERSION}
PORTREVISION=	1
CATEGORIES=	games kde
MASTER_SITES=	KDE/${KDE4_BRANCH}/${PORTVERSION}/src
DIST_SUBDIR=	KDE/${PORTVERSION}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	${${PORTNAME}_DESC}

USES=		cmake:outsource python tar:xz twisted:run sqlite
USE_KDE4=	kdelibs kdeprefix pykde4 automoc4
USE_QT4=	moc_build qmake_build rcc_build uic_build
CMAKE_ARGS=	-DINSTALL_KAJONGG:BOOL=TRUE

.include <${.CURDIR}/../kdegames4/Makefile.common>
.include <bsd.port.mk>
