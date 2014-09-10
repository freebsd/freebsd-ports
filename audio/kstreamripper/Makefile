# Created by: Mina R Waheeb <syncer@gmail.com>
# $FreeBSD$

PORTNAME=	kstreamripper
PORTVERSION=	0.7.1
PORTREVISION=	5
CATEGORIES=	audio kde
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	syncer@gmail.com
COMMENT=	Program for recording streams for KDE4

RUN_DEPENDS=	${LOCALBASE}/bin/streamripper:${PORTSDIR}/audio/streamripper

USES=		cmake tar:bzip2
USE_KDE4=	kdelibs kdehier kdeprefix automoc4
USE_QT4=	qmake_build moc_build rcc_build uic_build

CMAKE_ARGS+=	-DWITHOUT_LIBPROXY=YES # requires libproxy >= 0.3.1
WRKSRC=		${WRKDIR}/${PORTNAME}

.include <bsd.port.mk>
