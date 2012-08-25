# New ports collection makefile for:	skrooge
# Date created:		2009-05-01
# Whom:			Max Brazhnikov <makc@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	skrooge
PORTVERSION=	1.3.2
CATEGORIES=	finance kde
MASTER_SITES=	http://skrooge.org/files/

MAINTAINER=	kde@FreeBSD.org
COMMENT=	A personal finances manager for KDE

LIB_DEPENDS=	ofx.5:${PORTSDIR}/finance/libofx \
		sqlite3:${PORTSDIR}/databases/sqlite3 \
		qca.2:${PORTSDIR}/devel/qca \
		grantlee_gui.0:${PORTSDIR}/devel/grantlee

USE_BZIP2=	yes
USE_CMAKE=	yes
USE_QT4=	qmake_build moc_build uic_build rcc_build \
		corelib dbus gui script xml sql sql-sqlite3_run
USE_KDE4=	automoc4 kdehier kdelibs kdeprefix sharedmime
USE_LDCONFIG=	yes
MAKE_JOBS_SAFE=	yes

PLIST_SUB=	VERSION=${PORTVERSION}

post-install:
	@-update-mime-database ${KDE4_PREFIX}/share/mime

.include <bsd.port.mk>
