PORTNAME=	log4c
PORTVERSION=	1.2.4
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	SF

MAINTAINER=	rodrigo@FreeBSD.org
COMMENT=	Logging for C Library
WWW=		https://log4c.sourceforge.net/

LICENSE=	LGPL21

USES=				libtool pathfix
USE_LDCONFIG=			yes
GNU_CONFIGURE=			yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

OPTIONS_DEFINE=		EXPAT
OPTIONS_DEFAULT=	EXPAT

EXPAT_LIB_DEPENDS=	libexpat.so:textproc/expat2
EXPAT_CONFIGURE_WITH=	expat

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/liblog4c.so

.include <bsd.port.mk>
