# $FreeBSD$

PORTNAME=	ksirk
PORTVERSION=	${KDE4_VERSION}
CATEGORIES=	games kde
MASTER_SITES=	KDE/${KDE4_BRANCH}/${PORTVERSION}/src
DIST_SUBDIR=	KDE/${PORTVERSION}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	${${PORTNAME}_DESC}

LIB_DEPENDS=	libqca.so:devel/qca

USE_KDE4=	kdelibs kdeprefix libkdegames automoc4
USES=		cmake:outsource tar:xz
USE_QT4=	corelib gui corelib gui network qt3support svg xml \
		moc_build qmake_build rcc_build uic_build
USE_LDCONFIG=	yes

.include <${.CURDIR}/../kdegames4/Makefile.common>
.include <bsd.port.mk>
