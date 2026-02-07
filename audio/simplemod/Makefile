PORTNAME=	simplemod
PORTVERSION=	1.1
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	http://borderworlds.dk/projects/sm/

MAINTAINER=	xi@borderworlds.dk
COMMENT=	Minimalistic module player
WWW=		https://borderworlds.dk/projects/ #sm

LIB_DEPENDS=	libmikmod.so:audio/libmikmod

WRKSRC=		${WRKDIR}/simplemod

ALL_TARGET=	simplemod
PLIST_FILES=	bin/simplemod

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/simplemod ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
