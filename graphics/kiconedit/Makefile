# New ports collection makefile for:	kiconedit
# Date created:		2008-09-01
# Whom:			Max Brazhnikov <makc@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	kiconedit
PORTVERSION=	${EXTRA_VER}
PORTREVISION=	2
CATEGORIES=	graphics kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	stable/extragear
DIST_SUBDIR=	KDE/extragear

MAINTAINER=	kde@FreeBSD.org
COMMENT=	A KDE icon editor

USE_BZIP2=	yes
USE_KDE4=	kdelibs kdeprefix kdehier automoc4
USE_QT4=	corelib qmake_build moc_build rcc_build uic_build
USES=		cmake

EXTRA_VER=	4.4.0

post-patch:
#Fix build with kdelibs>=4.5.0
	${REINPLACE_CMD} -e 's,V4.1.2-Based,V4.2-Based,g' \
		${WRKSRC}/doc-translations/hu_kiconedit/kiconedit/index.docbook

.include <bsd.port.mk>
