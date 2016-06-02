# $FreeBSD$

PORTNAME=	teacooker
PORTVERSION=	0.3.0
PORTREVISION=	11
CATEGORIES=	deskutils kde
MASTER_SITES=	http://www.kde-apps.org/CONTENT/content-files/
PKGNAMEPREFIX=	plasma-applet-
DISTNAME=	85564-TeaCooker

MAINTAINER=	jhale@FreeBSD.org
COMMENT=	KDE4 tea cooker plasma applet

LICENSE=	GPLv3

USES=		cmake
USE_KDE4=	automoc4 kdelibs
USE_QT4=	gui dbus network opengl svg webkit xml \
		qmake_build moc_build rcc_build uic_build

WRKSRC=		${WRKDIR}/TeaCooker

.include <bsd.port.mk>
