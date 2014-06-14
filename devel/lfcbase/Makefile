# Created by: Kurt Jaeger <fbsd-ports@opsec.eu>
# $FreeBSD$

PORTNAME=	lfcbase
PORTVERSION=	1.5.10
CATEGORIES=	devel
MASTER_SITES=	http://www.lemke-it.com/

MAINTAINER=	pi@FreeBSD.org
COMMENT=	Collection of basic c++ classes, used for databases/cego

LICENSE=	GPLv3

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
USES=		libtool
USE_AUTOTOOLS=	autoconf:env

post-patch:
	@${REINPLACE_CMD} 's|-O3||g' ${WRKSRC}/src/Makefile.in

post-stage:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/liblfcbase.so.1

.include <bsd.port.mk>
