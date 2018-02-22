# Created by: fluffy@
# $FreeBSD$

PORTNAME=	kate
PORTVERSION=	${KDE4_VERSION}
PORTREVISION=	4
CATEGORIES=	editors kde kde-kde4

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Basic editor framework for the KDE system

LIB_DEPENDS=	libqjson.so:devel/qjson

USES=		cmake:outsource gettext kde:4 perl5 tar:xz
USE_KDE=	kdelibs automoc4 kactivities
USE_PERL5=	build
USE_QT4=	dbus gui script sql webkit xml \
		moc_build qmake_build rcc_build uic_build
USE_LDCONFIG=	yes

# editors/kate-kde4-plugin-pate installs pate
CMAKE_ARGS+=	-DBUILD_pate=off

.include <bsd.port.mk>
