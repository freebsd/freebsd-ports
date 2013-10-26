# $FreeBSD$

PORTNAME=	panelspacer
PORTVERSION=	0.2
PORTREVISION=	9
CATEGORIES=	deskutils kde
MASTER_SITES=	http://danakil.free.fr/linux/releases/${PORTNAME}-${PORTVERSION}/
PKGNAMEPREFIX=	plasma-applet-
DISTNAME=	${PORTNAME}-plasmoid-${PORTVERSION}

MAINTAINER=	jhale@FreeBSD.org
COMMENT=	Panel spacer plasma applet for KDE4

USES=		cmake
USE_KDE4=	automoc4 kdeprefix workspace
USE_QT4=	gui dbus network opengl svg webkit xml \
		qmake_build moc_build rcc_build uic_build

WRKSRC=		${WRKDIR}/Panelspacer_from_svn_pour_kdelook-tmp

PLIST_FILES=	lib/kde4/plasma_applet_panelspacer.so \
		share/kde4/services/plasma-applet-panelspacer.desktop

NO_STAGE=	yes
.include <bsd.port.mk>
