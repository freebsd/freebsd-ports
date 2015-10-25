# Created by: Edwin Groothuis <edwin@mavetju.org>
# $FreeBSD$

PORTNAME=	fmodapi
PORTVERSION=	4.24.16
PORTREVISION=	1
CATEGORIES=	audio devel linux
MASTER_SITES=	http://www.fmod.org/index.php/release/version/
PKGNAMEPREFIX=	linux-
DISTNAME=	fmodapi42416linux

MAINTAINER=	edwin@mavetju.org
COMMENT=	Music & Sound effects system

BROKEN=		Unfetchable
DEPRECATED=	Broken for more than 6 months
EXPIRATION_DATE=	2015-11-26
ONLY_FOR_ARCHS=	i386 amd64
INSTALL_SHLIB=	yes
USE_LDCONFIG=	yes
USE_LINUX_PREFIX=	yes
NO_BUILD=	yes

post-patch:
	${REINPLACE_CMD} -e 's,%%PREFIX%%,${STAGEDIR}${PREFIX},' ${WRKSRC}/Makefile

pre-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/

.include <bsd.port.mk>
