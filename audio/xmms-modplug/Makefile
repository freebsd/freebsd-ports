# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	modplug
PORTVERSION=	2.0.5
PORTREVISION=	7
CATEGORIES?=	audio
MASTER_SITES=	SF/${PORTNAME}-xmms/${PORTNAME}-xmms/2.05
PKGNAMEPREFIX=	xmms-
DISTNAME=	${PORTNAME}${PKGNAMEPREFIX}2.05

MAINTAINER=	ports@FreeBSD.org
COMMENT=	ModPlug-based plugin for XMMS

LIB_DEPENDS?=	libxmms.so:${PORTSDIR}/multimedia/xmms
LIB_DEPENDS+=	modplug:${PORTSDIR}/audio/libmodplug

USES=		pkgconfig
NO_STAGE=	yes
USE_LDCONFIG=	yes
HAS_CONFIGURE=	yes
PLUGDIR?=	lib/xmms/Input
PLIST_FILES=	${PLUGDIR}/libmodplugxmms.so

post-patch:
	@${REINPLACE_CMD} -e '/objformat=/s|=.*|=elf|' ${WRKSRC}/configure

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/modplugxmms/.libs/libmodplugxmms.so \
		${PREFIX}/${PLUGDIR}

.include <bsd.port.mk>
