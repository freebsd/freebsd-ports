# Created by: Kurt Jaeger <fbsd-ports@opsec.eu>
# $FreeBSD$

PORTNAME=	lfcbase
PORTVERSION=	1.5.8
CATEGORIES=	devel
MASTER_SITES=	http://www.lemke-it.com/

MAINTAINER=	fbsd-ports@opsec.eu
COMMENT=	Collection of basic c++ classes, used for databases/cego

LICENSE=	GPLv3

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
USE_AUTOTOOLS=	autoconf:env

post-patch:
	@${REINPLACE_CMD} 's|-O3||g' ${WRKSRC}/src/Makefile.in

.include <bsd.port.mk>
