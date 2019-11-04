# Created by: Dmitry Marakasov <amdmi3@amdmi3.ru>
# $FreeBSD$

PORTNAME=	ois
PORTVERSION=	1.2.0
PORTREVISION=	5
CATEGORIES=	devel
MASTER_SITES=	SF/wgois/Source%20Release/1.2
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Object Oriented Input System

LICENSE=	ZLIB

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USES=		autoreconf libtool pathfix xorg
USE_XORG=	x11 xaw
USE_LDCONFIG=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

WRKSRC=		${WRKDIR}/${PORTNAME}

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libOIS.so

.include <bsd.port.mk>
