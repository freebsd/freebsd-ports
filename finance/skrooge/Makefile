# $FreeBSD$

PORTNAME=	skrooge
PORTVERSION=	1.4.0
CATEGORIES=	finance kde
MASTER_SITES=	http://skrooge.org/files/

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE4 personal finance manager

BUILD_DEPENDS=	xsltproc:${PORTSDIR}/textproc/libxslt
LIB_DEPENDS=	ofx:${PORTSDIR}/finance/libofx \
		qca:${PORTSDIR}/devel/qca \
		grantlee_gui:${PORTSDIR}/devel/grantlee \
		kactivities:${PORTSDIR}/x11/kactivities

USE_BZIP2=	yes
USE_CMAKE=	yes
USE_SQLITE=	yes
USE_QT4=	qmake_build moc_build uic_build rcc_build \
		dbus gui script xml sql sql-sqlite3_run
USE_KDE4=	automoc4 kdehier kdelibs kdeprefix pimlibs sharedmime
USE_GETTEXT=	yes
USE_LDCONFIG=	yes
MAKE_JOBS_SAFE=	yes

PLIST_SUB=	VERSION=${PORTVERSION}

post-install:
	@-update-mime-database ${KDE4_PREFIX}/share/mime

.include <bsd.port.mk>
