# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libnoise
DISTVERSION=	1.0.0
CATEGORIES=	audio
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}%20sources/${PORTVERSION}
DISTNAME=	${PORTNAME}src-${DISTVERSION}
EXTRACT_SUFX=	.zip

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Generates three-dimensional coherent noise

USES=		gmake
USE_AUTOTOOLS=	libtool:env
USE_LDCONFIG=	yes
CXXFLAGS+=	-O3 -fomit-frame-pointer
WRKSRC=		${WRKDIR}/noise

post-patch:
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g' \
		${WRKSRC}/src/Makefile
	@${REINPLACE_CMD} -e 's|include lib:|include:|g' \
		${WRKSRC}/Makefile

do-install:
	${CP} -R ${WRKSRC}/src/${PORTNAME}.* ${STAGEDIR}${PREFIX}/lib/
	${INSTALL_LIB} ${WRKSRC}/src/.libs/${PORTNAME}.so.* ${STAGEDIR}${PREFIX}/lib/
	@${INSTALL} -d ${STAGEDIR}${PREFIX}/include/noise
	${CP} -R ${WRKSRC}/include/ ${STAGEDIR}${PREFIX}/include/noise/
	${RM} -f ${STAGEDIR}${PREFIX}/include/noise/Makefile
#	This line is here to preserve the old behavior of the port.
	${LN} -sf libnoise.so.0 ${STAGEDIR}${PREFIX}/lib/libnoise.so.0.3

.include <bsd.port.mk>
