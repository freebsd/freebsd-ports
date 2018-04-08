# $FreeBSD$

PORTNAME=	libkcddb
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	audio kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE CDDB library

LIB_DEPENDS=	libmusicbrainz5.so:audio/libmusicbrainz5

USES=		cmake:outsource gettext kde:5 tar:xz
USE_KDE=	auth codecs completion config configwidgets \
		coreaddons ecm i18n jobwidgets kio service \
		widgetsaddons
USE_QT5=	core gui network widgets xml \
		buildtools_build qmake_build
USE_LDCONFIG=	yes

.include <bsd.port.mk>
