# Created by: Hardy Schumacher <lowmaster@web.de>
# $FreeBSD$

PORTNAME=	rudeconfig
PORTVERSION=	5.0.5
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://www.rudeserver.com/config/download/

MAINTAINER=	lowmaster@web.de
COMMENT=	Library for handling configuration files, written in C++

HAS_CONFIGURE=	yes
CONFIGURE_ARGS+=--prefix=${PREFIX}
USE_LDCONFIG=	yes

MAN3=		rudeconfig.3

NO_STAGE=	yes
pre-install:
	${CHMOD} 744 ${WRKSRC}/install-sh

.include <bsd.port.mk>
