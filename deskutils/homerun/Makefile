# $FreeBSD$

PORTNAME=	homerun
PORTVERSION=	0.2.3
PORTREVISION=	4
CATEGORIES=	deskutils
MASTER_SITES=	KDE/unstable/${PORTNAME}/src/

MAINTAINER=	yurkis@gmail.com
COMMENT=	Fullscreen launcher with content organized in tabs

USES=		cmake:outsource compiler:c++0x gettext kde:4 tar:bzip2
USE_KDE=	kdelibs automoc4 workspace
USE_QT4=	moc_build qmake_build rcc_build uic_build corelib gui
USE_XORG=	x11
USE_LDCONFIG=	yes

.include <bsd.port.mk>
