# $FreeBSD$

PORTNAME=	panelspacer
PORTVERSION=	0.2
PORTREVISION=	14
CATEGORIES=	deskutils kde
MASTER_SITES=	http://danakil.free.fr/linux/releases/${PORTNAME}-${PORTVERSION}/
PKGNAMEPREFIX=	plasma-applet-
DISTNAME=	${PORTNAME}-plasmoid-${PORTVERSION}

MAINTAINER=	jhale@FreeBSD.org
COMMENT=	Panel spacer plasma applet for KDE4

LICENSE=	GPLv2

USES=		cmake kde:4
USE_KDE=	automoc4 workspace
USE_QT4=	gui dbus network opengl svg webkit xml \
		qmake_build moc_build rcc_build uic_build

WRKSRC=		${WRKDIR}/Panelspacer_from_svn_pour_kdelook-tmp

PLIST_FILES=	lib/kde4/plasma_applet_panelspacer.so \
		share/kde4/services/plasma-applet-panelspacer.desktop

.include <bsd.port.mk>
