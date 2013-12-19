# Created by: Troels Kofoed Jacobsen <tkjacobsen@gmail.com>
# $FreeBSD$

PORTNAME=	akonadi-googledata
PORTVERSION=	1.2.0
PORTREVISION=	2
CATEGORIES=	databases
MASTER_SITES=	http://libgcal.googlecode.com/files/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Akonadi Resources for Google Contacts and Calendar

LIB_DEPENDS=	libgcal.so:${PORTSDIR}/deskutils/libgcal

USE_BZIP2=	yes
USES=		cmake gettext
USE_QT4=	qmake_build rcc_build moc_build uic_build dbus
USE_KDE4=	kdelibs kdeprefix pimlibs automoc4 akonadi

NO_STAGE=	yes
.include <bsd.port.mk>
