# New ports collection makefile for:	cego-xml
# Date created:				Jun 12, 2010
# Whom:					Kurt Jaeger <fbsd-ports@opsec.eu>
#
# $FreeBSD$

PORTNAME=	lfcxml
PORTVERSION=	1.0.27
CATEGORIES=	devel
MASTER_SITES=	http://www.lemke-it.com/

MAINTAINER=	fbsd-ports@opsec.eu
COMMENT=	C++ XML library, used for databases/cego

LICENSE=	GPLv2

LIB_DEPENDS=	lfc.1:${PORTSDIR}/devel/lfc

GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
USE_LDCONFIG=	yes
USE_AUTOTOOLS=	autoconf:env

.include <bsd.port.mk>
