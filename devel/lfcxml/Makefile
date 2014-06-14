# Created by: Kurt Jaeger <fbsd-ports@opsec.eu>
# $FreeBSD$

PORTNAME=	lfcxml
PORTVERSION=	1.1.7
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://www.lemke-it.com/

MAINTAINER=	fbsd-ports@opsec.eu
COMMENT=	C++ XML library, used for databases/cego

LICENSE=	GPLv3

LIB_DEPENDS=	liblfcbase.so:${PORTSDIR}/devel/lfcbase

GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
USES=		libtool
USE_LDCONFIG=	yes
USE_AUTOTOOLS=	autoconf:env

post-stage:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/liblfcxml.so.1.0.0

.include <bsd.port.mk>
