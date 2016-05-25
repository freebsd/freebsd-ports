# $FreeBSD$

PORTNAME=	picmi
PORTVERSION=	${KDE4_VERSION}
CATEGORIES=	games kde
MASTER_SITES=	KDE/${KDE4_BRANCH}/${PORTVERSION}/src
DIST_SUBDIR=	KDE/${PORTVERSION}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	${${PORTNAME}_DESC}

USES=		cmake:outsource tar:xz
USE_KDE4=	kdelibs libkdegames automoc4
USE_QT4=	moc_build qmake_build rcc_build uic_build \
		svg xml

.include <${.CURDIR}/../kdegames4/Makefile.common>
.include <bsd.port.mk>
