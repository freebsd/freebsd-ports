# $FreeBSD$

PORTNAME=	skrooge
PORTVERSION=	1.7.1
PORTREVISION=	2
CATEGORIES=	finance kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	stable/${PORTNAME}/${PORTVERSION}/src/

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE4 personal finance manager

BUILD_DEPENDS=	xsltproc:${PORTSDIR}/textproc/libxslt
LIB_DEPENDS=	ofx:${PORTSDIR}/finance/libofx \
		qca:${PORTSDIR}/devel/qca \
		grantlee_gui:${PORTSDIR}/devel/grantlee \
		kactivities:${PORTSDIR}/x11/kactivities

USE_BZIP2=	yes
USES=		cmake:outsource gettext
USE_SQLITE=	yes
USE_QT4=	qmake_build moc_build uic_build rcc_build designer_build \
		corelib dbus gui script sql webkit xml sql-sqlite3_run
USE_KDE4=	automoc4 kdehier kdelibs kdeprefix pimlibs sharedmime
USE_LDCONFIG=	yes

PLIST_SUB=	VERSION=${PORTVERSION}

NO_STAGE=	yes
.include <bsd.port.mk>
