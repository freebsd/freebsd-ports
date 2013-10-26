# Created by: fluffy@
# $FreeBSD$

PORTNAME=	kate
PORTVERSION=	${KDE4_VERSION}
PORTREVISION=	1
CATEGORIES=	editors kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	${KDE4_BRANCH}/${PORTVERSION}/src
DIST_SUBDIR=	KDE/${PORTVERSION}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Basic editor framework for the KDE system

LIB_DEPENDS=	qjson.0:${PORTSDIR}/devel/qjson

CONFLICTS=	kdebase-4.[0-6].* kdelibs-4.[0-6].* kdesdk-4.[0-6].*

USE_XZ=		yes
USE_KDE4=	kdelibs kdeprefix kdehier automoc4 kactivities
USES=		cmake:outsource gettext perl5
USE_PERL5=	build
USE_QT4=	dbus gui script sql webkit xml \
		moc_build qmake_build rcc_build uic_build
USE_LDCONFIG=	yes

MAN1=		kate.1

# editors/kate-plugin-pate installs pate
CMAKE_ARGS+=	-DBUILD_pate=off

NO_STAGE=	yes
.include <bsd.port.mk>
