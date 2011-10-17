# New ports collection makefile for:	skrooge
# Date created:		2009-05-01
# Whom:			Max Brazhnikov <makc@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	skrooge
PORTVERSION=	0.9.1
PORTREVISION=	1
CATEGORIES=	finance kde
MASTER_SITES=	http://skrooge.org/files/

MAINTAINER=	makc@FreeBSD.org
COMMENT=	A personal finances manager for KDE

LIB_DEPENDS=	ofx.4:${PORTSDIR}/finance/libofx \
		sqlite3:${PORTSDIR}/databases/sqlite3 \
		qca.2:${PORTSDIR}/devel/qca

USE_BZIP2=	yes
USE_CMAKE=	yes
USE_QT_VER=	4
QT_COMPONENTS=	qmake_build moc_build uic_build rcc_build \
		sql-sqlite3_run
USE_KDE4=	kdelibs kdeprefix automoc4
USE_LDCONFIG=	yes
MAKE_JOBS_SAFE=	yes

PLIST_SUB=	VERSION=${PORTVERSION}

.include <bsd.port.mk>
