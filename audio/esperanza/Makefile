# Created by: Alexander Botero-Lowry <alexbl@FreeBSD.org>
# $FreeBSD$

PORTNAME=	esperanza
PORTVERSION=	0.4.0.20091017
PORTREVISION=	1
CATEGORIES=	audio
#MASTER_SITES=	http://exodus.xmms.se/~tru/esperanza/0.4/
MASTER_SITES=	DEBIAN
DISTNAME=	${PORTNAME}_${PORTVERSION:R}+git${PORTVERSION:E}.orig

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Advanced QT4 XMMS2 client

LIB_DEPENDS=	xmmsclient++.4:${PORTSDIR}/audio/cpp-xmms2

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION:R}+git${PORTVERSION:E}

USE_BZIP2=	yes
USE_QT4=	gui xml network imageformats_run \
		qmake_build moc_build rcc_build uic_build
QT_NONSTANDARD=	yes
USES=		gmake
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX} --disable-growl

PLIST_FILES=	bin/esperanza

.include <bsd.port.mk>
