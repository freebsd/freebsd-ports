# $FreeBSD$

PORTNAME=	daisy
PORTVERSION=	0.0.4.26
PORTREVISION=	7
CATEGORIES=	deskutils kde
MASTER_SITES=	http://cdlszm.org/downloads/
PKGNAMEPREFIX=	plasma-applet-
DISTNAME=	${PKGNAMEPREFIX}${PORTNAME}-${PORTVERSION}

MAINTAINER=	jhale@FreeBSD.org
COMMENT=	Simple launcher plasma applet for KDE4

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cmake gettext kde:4
USE_KDE=	automoc4 kdelibs workspace
USE_QT4=	corelib dbus gui network svg xml \
		qmake_build moc_build rcc_build uic_build

.include <bsd.port.mk>
