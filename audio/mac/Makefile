# New ports collection makefile for:	mac
# Date created:		8 Aug 2004
# Whom:			dieringe
#
# $FreeBSD$
#

PORTNAME=	mac
PORTVERSION=	3.99.4.5
CATEGORIES=	audio
MASTER_SITES=	SF/mac-port
DISTNAME=	${PORTNAME}-3.99-u4-b5

MAINTAINER=	infofarmer@FreeBSD.org
COMMENT=	Monkey's Audio lossless codec

BUILD_DEPENDS=	yasm:${PORTSDIR}/devel/yasm

USE_AUTOTOOLS=	libtool:15
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-static

post-patch:
	@${REINPLACE_CMD} -e 's|-O3||' ${WRKSRC}/configure
#	@${REINPLACE_CMD} -e '/GetInfo/s|intptr_t|long|g' ${WRKSRC}/src/MACLib/*.*
#	@${REINPLACE_CMD} -e 's|wcsnicmp|wcsncmp|g;s|wcsicmp|wcscmp|g;s|_wcsicmp|wcscmp|g;s|\.__pos||g' \
#		${WRKSRC}/src/MACLib/*.* ${WRKSRC}/src/Shared/*.*

.include <bsd.port.mk>
