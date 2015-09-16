# $FreeBSD$

PORTNAME=	skrooge
PORTVERSION=	1.10.0
CATEGORIES=	finance kde
MASTER_SITES=	KDE/stable/${PORTNAME}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE4 personal finance manager

BUILD_DEPENDS=	xsltproc:${PORTSDIR}/textproc/libxslt
LIB_DEPENDS=	libofx.so:${PORTSDIR}/finance/libofx \
		libqca.so:${PORTSDIR}/devel/qca \
		libgrantlee_gui.so:${PORTSDIR}/devel/grantlee \
		libkactivities.so:${PORTSDIR}/x11/kactivities

USES=		cmake:outsource gettext shared-mime-info tar:bzip2
USE_SQLITE=	yes
USE_QT4=	qmake_build moc_build uic_build rcc_build designer_build \
		corelib dbus gui script sql webkit xml sql-sqlite3_run
USE_KDE4=	automoc4 kdelibs kdeprefix pimlibs
USE_LDCONFIG=	yes

PLIST_SUB=	VERSION=${PORTVERSION} \
		GRANTLEE_VER=0.5

# Skrooge creates several empty directories due to how it calls CMake's
# install(DIRECTORY ...) function, so we need some code to remove them.
post-install:
	${FIND} ${STAGEDIR}${PREFIX}/share/apps/skrooge/html \
		-type d -empty -delete

.include <bsd.port.mk>
