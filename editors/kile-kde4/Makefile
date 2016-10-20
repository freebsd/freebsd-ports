# Created by: Stefan Jahn <stefan.jahn@nemesis-sektor.de>
# $FreeBSD$

PORTNAME=	kile
PORTVERSION=	2.1.3
PORTREVISION=	4
CATEGORIES=	editors kde
MASTER_SITES=	SF/${PORTNAME}/stable/${PORTNAME}-${DISTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	LaTeX source editor for KDE

RUN_DEPENDS=	identify:graphics/ImageMagick

USES=		cmake gettext-tools kde:4 shared-mime-info tar:bzip2
USE_QT4=	qmake_build moc_build rcc_build uic_build
USE_KDE=	kdelibs automoc4 kate_run
USE_TEX=	latex

OPTIONS_DEFINE=	OKULAR
OKULAR_DESC=	Use Okular for viewing
OKULAR_USE=	KDE=okular_run

.include <bsd.port.mk>
