# Created by: sobomax
# $FreeBSD$

PORTNAME=     	libg722
PORTVERSION=	1.0.0
#PORTREVISION= 	1
CATEGORIES= 	audio

MAINTAINER=	ports@sippysoft.com
COMMENT=	Software G.722 decoding/encoding library

LICENSE=	PUBLIC_DOMAIN
LICENSE_NAME=	${LICENSE:S/_/ /}
LICENSE_FILE=	${WRKSRC}/LICENSE
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

USE_GITHUB=	yes
GH_ACCOUNT=	sippy
GH_TAGNAME=	v_1_0_0

MAKE_ENV=	MAKEOBJDIR=${WRKDIR}

do-install:
	${INSTALL_DATA} ${WRKSRC}/g722.h ${STAGEDIR}${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/g722_decoder.h ${STAGEDIR}${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/g722_encoder.h ${STAGEDIR}${PREFIX}/include
	${INSTALL_DATA} ${WRKDIR}/libg722.a ${STAGEDIR}${PREFIX}/lib

.include <bsd.port.mk>
