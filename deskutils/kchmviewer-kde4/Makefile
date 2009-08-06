# New ports collection makefile for:	kchmviewer
# Date created:				Mon Jul 25 10:42:16 CEST 2005
# Whom:					Markus Brueffer <markus@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	kchmviewer
PORTVERSION=	4.1
CATEGORIES=	deskutils kde
MASTER_SITES=	SF

MAINTAINER=	makc@FreeBSD.org
COMMENT=	A Qt/KDE viewer for CHM files

LIB_DEPENDS=	chm.0:${PORTSDIR}/misc/chmlib

LATEST_LINK=	${PORTNAME}-kde4

USE_CMAKE=	yes
USE_KDE4=	kdeprefix kdelibs automoc4
USE_QT_VER=	4
QT_COMPONENTS=	dbus gui network svg xml designer_build \
		qmake_build moc_build rcc_build uic_build
MAKE_JOBS_SAFE=	yes

.include <bsd.port.mk>
