# Created by: Mina R Waheeb <syncer@gmail.com>
# $FreeBSD$

PORTNAME=	kstreamripper
PORTVERSION=	0.7.100
CATEGORIES=	audio kde
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}

MAINTAINER=	syncer@gmail.com
COMMENT=	Program for recording streams for KDE4

RUN_DEPENDS=	${LOCALBASE}/bin/streamripper:audio/streamripper

USES=		cmake gettext-tools tar:bzip2
USE_KDE4=	kdelibs kdeprefix automoc4
USE_QT4=	qmake_build moc_build rcc_build uic_build

WRKSRC=		${WRKDIR}/${PORTNAME}

.include <bsd.port.mk>
