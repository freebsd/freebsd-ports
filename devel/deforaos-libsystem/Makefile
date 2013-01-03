# Created by: Olivier Cochard-Labbe <olivier@cochard.me>
# $FreeBSD$

PORTNAME=	libsystem
PORTVERSION=	0.1.6
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://www.defora.org/os/download/download/3527/
DISTNAME=	libSystem-${PORTVERSION}
PKGNAMEPREFIX=	deforaos-

MAINTAINER=	olivier@cochard.me
COMMENT=	DeforaOS core system library

LICENSE=	GPLv3

USE_LDCONFIG=	yes
USE_PKGCONFIG=	build
MAKE_ARGS+=	PREFIX=${PREFIX}

post-patch:
	${REINPLACE_CMD} -e 's|/lib/|/libdata/|g' \
		${WRKSRC}/data/pkgconfig.sh

.include <bsd.port.mk>
