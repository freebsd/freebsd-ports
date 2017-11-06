# Created by: Oliver Lehmann <oliver@FreeBSD.org>
# $FreeBSD$

PORTNAME=	freealut
PORTVERSION=	1.1.0
PORTREVISION=	4
CATEGORIES=	audio
MASTER_SITES=	DEBIAN_POOL
DISTNAME=	freealut_${PORTVERSION}.orig

MAINTAINER=	oliver@FreeBSD.org
COMMENT=	The OpenAL Utility Toolkit

GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
USES=		gmake libtool openal:al pathfix pkgconfig
USE_LDCONFIG=	yes
LLD_UNSAFE=	yes
INSTALL_TARGET=	install-strip
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

post-patch:
	@${REINPLACE_CMD} -e 's/@CFLAGS@/& -lopenal -lpthread/g' \
		${WRKSRC}/examples/Makefile.in \
		${WRKSRC}/test_suite/Makefile.in

.include <bsd.port.mk>
