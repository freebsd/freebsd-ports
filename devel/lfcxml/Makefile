# Created by: Kurt Jaeger <fbsd-ports@opsec.eu>
# $FreeBSD$

PORTNAME=	lfcxml
PORTVERSION=	1.1.1
CATEGORIES=	devel
MASTER_SITES=	http://www.lemke-it.com/

MAINTAINER=	fbsd-ports@opsec.eu
COMMENT=	C++ XML library, used for databases/cego

LICENSE=	GPLv2

LIB_DEPENDS=	lfc:${PORTSDIR}/devel/lfc

GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
USE_LDCONFIG=	yes
USE_AUTOTOOLS=	autoconf:env

.include <bsd.port.mk>
