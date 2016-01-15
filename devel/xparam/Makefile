# Created by: ijliao
# $FreeBSD$

PORTNAME=	xparam
PORTVERSION=	1.22
PORTREVISION=	3
CATEGORIES=	devel
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	General-purpose tool for parameter handling in C++

LICENSE=	GPLv2+

GNU_CONFIGURE=	yes
USES=		gmake libtool:build
USE_LDCONFIG=	yes

post-install:
	${CHMOD} u+w ${STAGEDIR}${PREFIX}/lib/libxparam.so
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libxparam.so

.include <bsd.port.mk>
