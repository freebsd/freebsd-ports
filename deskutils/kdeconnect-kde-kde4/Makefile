# $FreeBSD$

PORTNAME=	kdeconnect-kde
PORTVERSION=	0.7.2
PORTREVISION=	8
CATEGORIES=	deskutils
MASTER_SITES=	KDE/unstable/kdeconnect/${PORTVERSION}/src/
PKGNAMESUFFIX=	-kde4

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Support for KDE to interface between your phone and your computer

DEPRECATED=		Qt4 has been EOL since december 2015
EXPIRATION_DATE=	2018-12-31

CONFLICTS_INSTALL=	${PORTNAME}

USES=		cmake:noninja compiler:c++0x gettext kde:4 qt:4 tar:xz
USE_KDE=	kdelibs automoc4 workspace runtime
USE_QT=		corelib gui moc_build qmake_build uic_build rcc_build
USE_LDCONFIG=	yes

.include <bsd.port.mk>
