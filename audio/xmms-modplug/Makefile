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

BUILD_DEPENDS=	xmms>0:${PORTSDIR}/multimedia/xmms
LIB_DEPENDS=	libmodplug.so:${PORTSDIR}/audio/libmodplug
RUN_DEPENDS=	xmms>0:${PORTSDIR}/multimedia/xmms

USES=		pkgconfig
USE_AUTOTOOLS=	libtool
USE_LDCONFIG=	yes

PLIST_FILES=	lib/xmms/Input/libmodplugxmms.so

post-patch:
	@${REINPLACE_CMD} -e \
		's|-lstdc++||' ${WRKSRC}/modplugxmms/Makefile.in

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/xmms/Input
	(cd ${WRKSRC}/modplugxmms/.libs && ${INSTALL_LIB} libmodplugxmms.so \
		${STAGEDIR}${PREFIX}/lib/xmms/Input)

.include <bsd.port.mk>
