# Created by: Mina R Waheeb <syncer@gmail.com>
# $FreeBSD$

PORTNAME=	kstreamripper
PORTVERSION=	0.7.100
PORTREVISION=	2
CATEGORIES=	audio kde
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}

MAINTAINER=	syncer@gmail.com
COMMENT=	Program for recording streams for KDE4

DEPRECATED=		Qt4 has been EOL since december 2015
EXPIRATION_DATE=	2018-12-31

RUN_DEPENDS=	${LOCALBASE}/bin/streamripper:audio/streamripper

USES=		cmake gettext-tools kde:4 qt:4 tar:bzip2
USE_KDE=	kdelibs automoc4
USE_QT=		qmake_build moc_build rcc_build uic_build

WRKSRC=		${WRKDIR}/${PORTNAME}

.include <bsd.port.mk>
