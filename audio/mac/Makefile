# Created by: Martin Dieringer <Martin.Dieringer@t-online.de>
# $FreeBSD$

PORTNAME=	mac
PORTVERSION=	3.99.4.5
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	http://supermmx.org/resources/linux/mac/ CENKES
DISTNAME=	${PORTNAME}-3.99-u4-b5

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	Monkey's Audio lossless codec

USE_AUTOTOOLS=	libtool
NO_STAGE=	yes
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes

.include <bsd.port.pre.mk>

.if ${ARCH} == "i386" || ${ARCH} == "amd64"
BUILD_DEPENDS=	yasm:${PORTSDIR}/devel/yasm
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|-O3||' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e '/nRetVal = 0/s|int|intptr_t|' \
		${WRKSRC}/src/MACLib/APEDecompress.cpp

post-install:
	cd ${WRKSRC}/src/MACLib && ${INSTALL_DATA} BitArray.h \
		Prepare.h UnBitArrayBase.h ${PREFIX}/include/mac

.include <bsd.port.post.mk>
