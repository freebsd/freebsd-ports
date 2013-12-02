# Created by: ijliao
# $FreeBSD$

PORTNAME=	log4c
PORTVERSION=	1.2.3
CATEGORIES=	devel
MASTER_SITES=	SF

MAINTAINER=	rodrigo@bebik.net
COMMENT=	Logging for C Library

LICENSE=	LGPL21

OPTIONS_DEFINE=	EXPAT
OPTIONS_DEFAULT=EXPAT
EXPAT_CONFIGURE_WITH=	expat
EXPAT_LIB_DEPENDS=	libexpat.so:${PORTSDIR}/textproc/expat2

USES=		pathfix
USE_AUTOTOOLS=	libtool
USE_LDCONFIG=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/liblog4c.so

.include <bsd.port.mk>
