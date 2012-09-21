# $FreeBSD$

PORTNAME=	skrooge
PORTVERSION=	1.3.3
CATEGORIES=	finance kde
MASTER_SITES=	http://skrooge.org/files/

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE4 personal finance manager

LIB_DEPENDS=	ofx:${PORTSDIR}/finance/libofx \
		qca:${PORTSDIR}/devel/qca \
		grantlee_gui:${PORTSDIR}/devel/grantlee

USE_BZIP2=	yes
USE_CMAKE=	yes
USE_SQLITE=	yes
USE_QT4=	qmake_build moc_build uic_build rcc_build \
		dbus gui script xml sql sql-sqlite3_run
USE_KDE4=	automoc4 kdehier kdelibs kdeprefix sharedmime
USE_GETTEXT=	yes
USE_LDCONFIG=	yes
MAKE_JOBS_SAFE=	yes

PLIST_SUB=	VERSION=${PORTVERSION}

post-install:
	@-update-mime-database ${KDE4_PREFIX}/share/mime

.include <bsd.port.mk>
