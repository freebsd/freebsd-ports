# Created by: Donald Burr <dburr@FreeBSD.org>
# $FreeBSD$

PORTNAME=	tank
PORTVERSION=	0.4a
PORTREVISION=	4
CATEGORIES=	games
MASTER_SITES=	http://elfga.com/~erik/fbsd/files/
EXTRACT_SUFX=	-src.tar.gz

MAINTAINER=	erik@bz.bzflag.bz
COMMENT=	3-D network tank game that uses OpenGL/Mesa

DEPRECATED=	Depends on expiring graphics/libaux
EXPIRATION_DATE=	2016-07-04

BUILD_DEPENDS=	libaux>=1.0:graphics/libaux

USES=		gmake
ALL_TARGET=	linux-mesa-elf

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tank ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/*.tga ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/*.au ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
