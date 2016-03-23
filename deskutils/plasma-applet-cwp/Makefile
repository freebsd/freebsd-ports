# Created by: Stas Timokhin <stast@bsdportal.ru>
# $FreeBSD$

PORTNAME=	cwp
PORTVERSION=	1.12.1
CATEGORIES=	deskutils kde
MASTER_SITES=	http://kde-look.org/CONTENT/content-files/
PKGNAMEPREFIX=	plasma-applet-
DISTNAME=	98925-cwp-${PORTVERSION}

MAINTAINER=	dbn@FreeBSD.org
COMMENT=	Weather plasma applet for KDE4

LICENSE=	GPLv3

USES=		cmake gettext tar:bzip2
USE_KDE4=	automoc4 kdeprefix kdelibs
USE_QT4=	gui dbus network opengl svg phonon webkit xml \
		qmake_build moc_build rcc_build uic_build

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

.include <bsd.port.mk>
