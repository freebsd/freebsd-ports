# Created by: sobomax
# $FreeBSD$

PORTNAME=     	libg722
DISTVERSIONPREFIX=	v_
DISTVERSION=	1_0_2
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

USE_LDCONFIG=	yes

MAKE_ENV=	MAKEOBJDIR=${WRKDIR}

do-install:
	${INSTALL_DATA} ${WRKSRC}/g722.h ${STAGEDIR}${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/g722_decoder.h ${STAGEDIR}${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/g722_encoder.h ${STAGEDIR}${PREFIX}/include
	${INSTALL_DATA} ${WRKDIR}/libg722.a ${STAGEDIR}${PREFIX}/lib
	${INSTALL_PROGRAM} ${WRKDIR}/libg722.so.0 ${STAGEDIR}${PREFIX}/lib
	${LN} -sf libg722.so.0 ${STAGEDIR}${PREFIX}/lib/libg722.so

.include <bsd.port.mk>
