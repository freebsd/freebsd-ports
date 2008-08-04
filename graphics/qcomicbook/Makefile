# New ports collection makefile for:	qcomicbook
# Date created:				24 April, 2005
# Whom:					Adam Weinberger <adamw@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	qcomicbook
PORTVERSION=	0.4.0
PORTREVISION=	3
CATEGORIES=	graphics
MASTER_SITES=	http://linux.bydg.org/~yogin/qcomicbook/

MAINTAINER=	makc@issp.ac.ru
COMMENT=	QT-based comic book archive viewer

RUN_DEPENDS=	unzip:${PORTSDIR}/archivers/unzip \
		unrar:${PORTSDIR}/archivers/unrar

USE_QT_VER=	4
QT_COMPONENTS=	gui moc_build
USE_GNOME=	gnometarget
USE_GMAKE=	yes
USE_EFL=	imlib2
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	QtGui_CFLAGS="${QtGui_CFLAGS}"

MAN1=		qcomicbook.1

QtGui_CFLAGS=	-DQT_SHARED \
		-I${QT_INCDIR}/QtGui \
		-I${QT_INCDIR}/QtCore \
		-I${QT_INCDIR}

.include <bsd.port.mk>
