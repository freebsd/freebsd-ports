# $FreeBSD$

PORTNAME=	yawp
PORTVERSION=	0.4.5
PORTREVISION=	7
CATEGORIES=	deskutils kde
MASTER_SITES=	SF
PKGNAMEPREFIX=	plasma-applet-

MAINTAINER=	jhale@FreeBSD.org
COMMENT=	KDE4 weather plasma applet

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/LICENSE-GPL2

USES=		cmake gettext kde:4 tar:bzip2
USE_KDE=	automoc4 kdelibs workspace
USE_QT4=	corelib dbus gui network svg xml \
		qmake_build moc_build rcc_build uic_build

.include <bsd.port.mk>
