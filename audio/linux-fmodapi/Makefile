# New ports collection makefile for:	devel/linux-fmodapi
# Date created:				2010-01-06
# Whom:					Edwin Groothuis <edwin@mavetju.org>
#
# $FreeBSD$
#

PORTNAME=	fmodapi
PORTVERSION=	4.24.16
PORTREVISION=	1
CATEGORIES=	audio devel linux
MASTER_SITES=	http://www.fmod.org/index.php/release/version/
PKGNAMEPREFIX=	linux-
DISTNAME=	fmodapi42416linux

MAINTAINER=	edwin@mavetju.org
COMMENT=	Music & Sound effects system

ONLY_FOR_ARCHS=	i386
INSTALL_SHLIB=	yes
USE_LDCONFIG=	yes
NO_BUILD=	yes
USE_LINUX_PREFIX=	yes

post-patch:
	${REINPLACE_CMD} -e 's,%%PREFIX%%,${PREFIX},' ${WRKSRC}/Makefile

.include <bsd.port.mk>
