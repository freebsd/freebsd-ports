# Created by: Mina R Waheeb <syncer@gmail.com>
# $FreeBSD$

PORTNAME=	silence
PORTVERSION=	0.2
PORTREVISION=	7
CATEGORIES=	deskutils kde
MASTER_SITES=	http://kde-apps.org/CONTENT/content-files/
DISTNAME=	124776-${PORTNAME}-${PORTVERSION}

MAINTAINER=	syncer@gmail.com
COMMENT=	Information management tool

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	${KDE4_PREFIX}/lib/kde4/katepart.so:editors/kate

USES=		cmake
USE_KDE4=	kdelibs kdeprefix automoc4
USE_QT4=	qmake_build moc_build rcc_build uic_build linguisttools_build

WRKSRC=		${WRKDIR}/${PORTNAME}

.include <bsd.port.mk>
