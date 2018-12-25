# $FreeBSD$

PORTNAME=	homerun
PORTVERSION=	0.2.3
PORTREVISION=	7
CATEGORIES=	deskutils
MASTER_SITES=	KDE/unstable/${PORTNAME}/src/

MAINTAINER=	yurkis@gmail.com
COMMENT=	Fullscreen launcher with content organized in tabs

DEPRECATED=		Qt4 has been EOL since december 2015
EXPIRATION_DATE=	2018-12-31

USES=		cmake compiler:c++0x gettext kde:4 qt:4 tar:bzip2
USE_KDE=	kdelibs automoc4 workspace
USE_QT=		moc_build qmake_build rcc_build uic_build corelib gui
USE_XORG=	x11
USE_LDCONFIG=	yes

.include <bsd.port.mk>
