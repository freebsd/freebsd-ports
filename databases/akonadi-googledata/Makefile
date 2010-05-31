# New ports collection makefile for:	akonadi-googledata
# Date created:		2009-08-16
# Whom:			Troels Kofoed Jacobsen <tkjacobsen@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	akonadi-googledata
PORTVERSION=	1.0.1
PORTREVISION=	4
CATEGORIES=	databases
MASTER_SITES=	http://libgcal.googlecode.com/files/

MAINTAINER=	tkjacobsen@gmail.com
COMMENT=	Akonadi Resources for Google Contacts and Calendar

LIB_DEPENDS=	gcal:${PORTSDIR}/deskutils/libgcal

USE_BZIP2=	yes
USE_CMAKE=	yes
USE_GETTEXT=	yes
USE_QT_VER=	4
QT_COMPONENTS=	qmake_build rcc_build moc_build uic_build dbus gui network sql svg xml
USE_KDE4=	kdelibs kdeprefix pimlibs automoc4 akonadi

.include <bsd.port.mk>
