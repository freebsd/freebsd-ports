# Created by: Stefan Jahn <stefan.jahn@nemesis-sektor.de>
# $FreeBSD$

PORTNAME=	kile
PORTVERSION=	2.1.3
PORTREVISION=	7
CATEGORIES=	editors kde
MASTER_SITES=	SF/${PORTNAME}/stable/${PORTNAME}-${DISTVERSION}
PKGNAMESUFFIX=	-kde4

MAINTAINER=	kde@FreeBSD.org
COMMENT=	LaTeX source editor for KDE

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	identify:graphics/ImageMagick

USES=		cmake gettext-tools kde:4 qt:4 shared-mime-info tar:bzip2
USE_QT=		qmake_build moc_build rcc_build uic_build
USE_KDE=	kdelibs automoc4 kate_run
USE_TEX=	latex

OPTIONS_DEFINE=	OKULAR
OKULAR_DESC=	Use Okular for viewing
OKULAR_USE=	KDE=okular_run

CONFLICTS_INSTALL=	kile-3.*
PORTSCOUT=	limit:2\.1.*

.include <bsd.port.mk>
