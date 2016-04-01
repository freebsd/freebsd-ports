# Created by: ijliao
# $FreeBSD$

PORTNAME=	log4c
PORTVERSION=	1.2.4
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	SF

MAINTAINER=	rodrigo@FreeBSD.org
COMMENT=	Logging for C Library

LICENSE=	LGPL21

OPTIONS_DEFINE=	EXPAT
OPTIONS_DEFAULT=EXPAT
EXPAT_CONFIGURE_WITH=	expat
EXPAT_LIB_DEPENDS=	libexpat.so:textproc/expat2

USES=		libtool pathfix
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/liblog4c.so

.include <bsd.port.mk>
