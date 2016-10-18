# $FreeBSD$

PORTNAME=	kremotecontrol
PORTVERSION=	${KDE4_VERSION}
CATEGORIES=	comms kde kde-kde4

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE frontend for your remote controls

RUN_DEPENDS=	lircd:comms/lirc

USES=		cmake:outsource kde:4 tar:xz
USE_KDE=	automoc4 kdelibs
USE_QT4=	corelib script xmlpatterns \
		qmake_build moc_build rcc_build uic_build
USE_LDCONFIG=	yes

.include <bsd.port.mk>
