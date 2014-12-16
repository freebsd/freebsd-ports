# Created by: Olivier Cochard-Labbe <olivier@cochard.me>
# $FreeBSD$

PORTNAME=	libsystem
PORTVERSION=	0.1.6
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	http://www.defora.org/os/download/download/3527/
DISTNAME=	libSystem-${PORTVERSION}
PKGNAMEPREFIX=	deforaos-

MAINTAINER=	olivier@cochard.me
COMMENT=	DeforaOS core system library

LICENSE=	GPLv3

USES=		pkgconfig
USE_LDCONFIG=	yes
USE_OPENSSL=	yes
CPPFLAGS+=	-I${OPENSSLINC}
LDFLAGS+=	-L${OPENSSLLIB}
MAKE_ARGS+=	PREFIX=${PREFIX}

post-patch:
	${REINPLACE_CMD} 's|/lib/|/libdata/|g' \
		${WRKSRC}/data/pkgconfig.sh
	${REINPLACE_CMD} 's|CPPFLAGS=|CPPFLAGS+=|' \
		${WRKSRC}/src/Makefile

.include <bsd.port.mk>
