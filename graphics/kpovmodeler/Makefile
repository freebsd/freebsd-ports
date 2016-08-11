# $FreeBSD$

PORTNAME=	kpovmodeler
PORTVERSION=	${APP_VER}.${EXTRA_VER}
PORTREVISION=	12
CATEGORIES=	graphics kde
MASTER_SITES=	KDE/Attic/${EXTRA_VER}/src/extragear
DISTNAME=	${PORTNAME}-${APP_VER}-kde${EXTRA_VER}
DIST_SUBDIR=	KDE/extragear

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE editor/frontend for Povray

RUN_DEPENDS=	povray:graphics/povray-meta

USE_GL=		glu
USE_KDE4=	kdelibs automoc4
USE_QT4=	corelib opengl qmake_build moc_build rcc_build uic_build
USES=		cmake gettext tar:bzip2

APP_VER=	1.1.3
EXTRA_VER=	4.3.1

post-patch:
#Fix build with kdelibs>=4.5.0
	${REINPLACE_CMD} -e 's,V4.1.2-Based,V4.2-Based,g' \
		${WRKSRC}/doc-translations/hu_kpovmodeler/kpovmodeler/index.docbook

.include <bsd.port.mk>
