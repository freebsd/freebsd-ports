# Created by: fluffy@
# $FreeBSD$

PORTNAME=	kate
PORTVERSION=	${KDE4_VERSION}
PORTREVISION=	1
CATEGORIES=	editors kde
MASTER_SITES=	KDE/${KDE4_BRANCH}/${PORTVERSION}/src
DIST_SUBDIR=	KDE/${PORTVERSION}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Basic editor framework for the KDE system

LIB_DEPENDS=	libqjson.so:devel/qjson

USE_KDE4=	kdelibs kdeprefix automoc4 kactivities
USES=		cmake:outsource gettext perl5 tar:xz
USE_PERL5=	build
USE_QT4=	dbus gui script sql webkit xml \
		moc_build qmake_build rcc_build uic_build
USE_LDCONFIG=	yes

# editors/kate-plugin-pate installs pate
CMAKE_ARGS+=	-DBUILD_pate=off

.include <bsd.port.mk>
