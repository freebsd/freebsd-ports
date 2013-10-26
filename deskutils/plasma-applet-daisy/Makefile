# $FreeBSD$

PORTNAME=	daisy
PORTVERSION=	0.0.4.26
PORTREVISION=	1
CATEGORIES=	deskutils kde
MASTER_SITES=	http://cdlszm.org/downloads/
PKGNAMEPREFIX=	plasma-applet-
DISTNAME=	${PKGNAMEPREFIX}${PORTNAME}-${PORTVERSION}

MAINTAINER=	jhale@FreeBSD.org
COMMENT=	Simple launcher plasma applet for KDE4

LICENSE=	GPLv3

USES=		cmake gettext
USE_KDE4=	automoc4 kdeprefix kdelibs workspace
USE_QT4=	qmake_build moc_build rcc_build uic_build

NO_STAGE=	yes
.include <bsd.port.mk>
