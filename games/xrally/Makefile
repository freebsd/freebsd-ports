# Created by: Edwin Groothuis
# $FreeBSD$

PORTNAME=	xrally
PORTVERSION=	1.1.1
PORTREVISION=	6
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/1.1
DISTNAME=	${PORTNAME}-1.1

MAINTAINER=	edwin@mavetju.org
COMMENT=	XRally is a Linux clone of the classic Rally X arcade game

WRKSRC=		${WRKDIR}/${PORTNAME}
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX}
USE_XORG=	x11 xi xpm
USE_BZIP2=	yes
USE_GMAKE=	yes
CFLAGS+=	${PTHREAD_CFLAGS} -I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}
MAKE_ENV=	INCLUDES="-I${LOCALBASE}/include"

NO_STAGE=	yes
.include <bsd.port.mk>
