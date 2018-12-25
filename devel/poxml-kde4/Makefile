# $FreeBSD$

PORTNAME=	poxml
PORTVERSION=	${KDE4_VERSION}
PORTREVISION=	3
CATEGORIES=	devel kde kde-kde4

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Tools to translate Docbook XML using gettext

DEPRECATED=	KDE4 is EOL upstream
EXPIRATION_DATE=	2018-12-31

BUILD_DEPENDS=	${LOCALBASE}/lib/libantlr.a:devel/antlr

USES=		cmake gettext-tools:build,run kde:4 qt:4 tar:xz
USE_KDE=	kdelibs automoc4
USE_QT=		moc_build qmake_build rcc_build uic_build \
		corelib xml

.include <bsd.port.mk>
