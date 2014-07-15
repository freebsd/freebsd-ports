# $FreeBSD$

PORTNAME=	skrooge
PORTVERSION=	1.7.1
PORTREVISION=	4
CATEGORIES=	finance kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	stable/${PORTNAME}/${PORTVERSION}/src/

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE4 personal finance manager

BUILD_DEPENDS=	xsltproc:${PORTSDIR}/textproc/libxslt
LIB_DEPENDS=	libofx.so:${PORTSDIR}/finance/libofx \
		libqca.so:${PORTSDIR}/devel/qca \
		libgrantlee_gui.so:${PORTSDIR}/devel/grantlee \
		libkactivities.so:${PORTSDIR}/x11/kactivities

USE_BZIP2=	yes
USES=		cmake:outsource gettext shared-mime-info
USE_SQLITE=	yes
USE_QT4=	qmake_build moc_build uic_build rcc_build designer_build \
		corelib dbus gui script sql webkit xml sql-sqlite3_run
USE_KDE4=	automoc4 kdehier kdelibs kdeprefix pimlibs
USE_LDCONFIG=	yes

PLIST_SUB=	VERSION=${PORTVERSION} \
		GRANTLEE_VER=0.4

.include <bsd.port.mk>
