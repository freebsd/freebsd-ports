# Created by: Oliver Lehmann <oliver@FreeBSD.org>
# $FreeBSD$

PORTNAME=	freealut
PORTVERSION=	1.1.0
PORTREVISION=	4
CATEGORIES=	audio
MASTER_SITES=	http://connect.creativelabs.com/openal/Downloads/ALUT/

MAINTAINER=	oliver@FreeBSD.org
COMMENT=	The OpenAL Utility Toolkit

BROKEN=		Fails to fetch
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
USES=		gmake libtool openal:al pathfix pkgconfig
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

post-patch:
	@${REINPLACE_CMD} -e 's/@CFLAGS@/& -lopenal -lpthread/g' \
		${WRKSRC}/examples/Makefile.in \
		${WRKSRC}/test_suite/Makefile.in

.include <bsd.port.mk>
