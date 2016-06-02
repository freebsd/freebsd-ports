# $FreeBSD$

PORTNAME=	kapptemplate
PORTVERSION=	${KDE4_VERSION}
CATEGORIES=	devel kde
MASTER_SITES=	KDE/${KDE4_BRANCH}/${PORTVERSION}/src
DIST_SUBDIR=	KDE/${PORTVERSION}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE template generator

USE_KDE4=	kdelibs automoc4
USES=		cmake:outsource gmake tar:xz
USE_QT4=	moc_build qmake_build rcc_build uic_build \
		corelib dbus declarative

.include <bsd.port.mk>
