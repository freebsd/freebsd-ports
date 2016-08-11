# $FreeBSD$

PORTNAME=	smokeqt
PORTVERSION=	${KDE4_VERSION}
PORTREVISION=	1
CATEGORIES=	devel kde
MASTER_SITES=	KDE/${KDE4_BRANCH}/${PORTVERSION}/src
DIST_SUBDIR=	KDE/${PORTVERSION}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	SMOKE bindings for Qt

LIB_DEPENDS=	libqscintilla2.so:devel/qscintilla2 \
		libqwt.so:x11-toolkits/qwt5

USE_KDE4=	smokegen qimageblitz
USE_QT4=	corelib dbus declarative designer_build gui help \
		multimedia network opengl phonon qtestlib script \
		sql svg webkit xml xmlpatterns \
		qmake_build moc_build uic_build rcc_build
USES=		cmake:outsource pkgconfig tar:xz
USE_LDCONFIG=	yes

.include <bsd.port.mk>
