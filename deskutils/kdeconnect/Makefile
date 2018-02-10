# $FreeBSD$

PORTNAME=	kdeconnect-kde
PORTVERSION=	0.7.2
PORTREVISION=	5
CATEGORIES=	deskutils
MASTER_SITES=	KDE/unstable/kdeconnect/${PORTVERSION}/src/

MAINTAINER=	yurkis@gmail.com
COMMENT=	Support for KDE to interface between your phone and your computer

USES=		cmake:noninja compiler:c++0x gettext kde:4 tar:xz
USE_KDE=	kdelibs automoc4 workspace runtime
USE_QT4=	corelib gui moc_build qmake_build uic_build rcc_build
USE_LDCONFIG=	yes

.include <bsd.port.mk>
