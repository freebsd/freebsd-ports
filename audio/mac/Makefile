# New ports collection makefile for:	Monkey's Audio Codec
# Date created:				8 Aug 2004
# Whom:			Martin Dieringer <Martin.Dieringer@t-online.de>
#
# $FreeBSD$
#

PORTNAME=	mac
PORTVERSION=	3.99.4.5
CATEGORIES=	audio
MASTER_SITES=	CENKES
DISTNAME=	${PORTNAME}-3.99-u4-b5

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Monkey's Audio lossless codec

USE_AUTOTOOLS=	libtool:22
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-static

.include <bsd.port.pre.mk>

.if ${ARCH} == "i386" || ${ARCH} == "amd64"
BUILD_DEPENDS+=	yasm:${PORTSDIR}/devel/yasm
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|-O3||' ${WRKSRC}/configure

.include <bsd.port.post.mk>
