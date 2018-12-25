# $FreeBSD$

PORTNAME=	kremotecontrol
PORTVERSION=	${KDE4_VERSION}
PORTREVISION=	3
CATEGORIES=	comms kde kde-kde4

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE frontend for your remote controls

DEPRECATED=	KDE4 is EOL upstream
EXPIRATION_DATE=	2018-12-31

RUN_DEPENDS=	lircd:comms/lirc

USES=		cmake kde:4 qt:4 tar:xz
USE_KDE=	automoc4 kdelibs
USE_QT=		corelib script xmlpatterns \
		qmake_build moc_build rcc_build uic_build
USE_LDCONFIG=	yes

.include <bsd.port.mk>
