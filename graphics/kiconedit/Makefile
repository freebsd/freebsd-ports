# $FreeBSD$

PORTNAME=	kiconedit
PORTVERSION=	${EXTRA_VER}
PORTREVISION=	5
CATEGORIES=	graphics kde
MASTER_SITES=	KDE/stable/extragear
DIST_SUBDIR=	KDE/extragear

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE icon editor

USE_KDE4=	kdelibs automoc4
USE_QT4=	corelib qmake_build moc_build rcc_build uic_build
USES=		cmake gettext tar:bzip2

EXTRA_VER=	4.4.0

post-patch:
#Fix build with kdelibs>=4.5.0
	${REINPLACE_CMD} -e 's,V4.1.2-Based,V4.2-Based,g' \
		${WRKSRC}/doc-translations/hu_kiconedit/kiconedit/index.docbook

.include <bsd.port.mk>
