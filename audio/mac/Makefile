# Created by: Martin Dieringer <Martin.Dieringer@t-online.de>
# $FreeBSD$

PORTNAME=	mac
PORTVERSION=	3.99.4.5
PORTREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	http://supermmx.org/resources/linux/mac/
DISTNAME=	${PORTNAME}-3.99-u4-b5

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	Monkey's Audio lossless codec

BROKEN=		No public distfiles

USES=		libtool
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip

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
		Prepare.h UnBitArrayBase.h ${STAGEDIR}${PREFIX}/include/mac

.include <bsd.port.post.mk>
