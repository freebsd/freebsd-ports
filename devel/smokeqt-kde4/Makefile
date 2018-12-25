# $FreeBSD$

PORTNAME=	smokeqt
PORTVERSION=	${KDE4_VERSION}
PORTREVISION=	5
CATEGORIES=	devel kde kde-kde4

MAINTAINER=	kde@FreeBSD.org
COMMENT=	SMOKE bindings for Qt

DEPRECATED=	KDE4 is EOL upstream
EXPIRATION_DATE=	2018-12-31

LIB_DEPENDS=	libqscintilla2_qt4.so:devel/qscintilla2 \
		libqwt.so:x11-toolkits/qwt5

USES=		cmake kde:4 pkgconfig qt:4 tar:xz
USE_KDE=	smokegen qimageblitz
USE_QT=		corelib dbus declarative designer_build gui help \
		multimedia network opengl phonon qtestlib script \
		sql svg webkit xml xmlpatterns \
		qmake_build moc_build uic_build rcc_build
USE_LDCONFIG=	yes
USE_CXXSTD=	gnu++98

.include <bsd.port.mk>
