# New ports collection makefile for:	libnoise
# Date created:		28 August 2006
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libnoise
DISTVERSION=	1.0.0
CATEGORIES=	audio
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}%20sources/${PORTVERSION}
DISTNAME=	${PORTNAME}src-${DISTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Generates three-dimensional coherent noise

USE_ZIP=	yes
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool:22:env
USE_LDCONFIG=	yes
CXXFLAGS+=	-O3 -fomit-frame-pointer
WRKSRC=		${WRKDIR}/noise

post-patch:
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g' \
		${WRKSRC}/src/Makefile
	@${REINPLACE_CMD} -e 's|include lib:|include:|g' \
		${WRKSRC}/Makefile

do-install:
	@${CP} -R ${WRKSRC}/src/${PORTNAME}.* ${PREFIX}/lib/
	@${CP} -R ${WRKSRC}/src/.libs/${PORTNAME}.so.* ${PREFIX}/lib/
	@${INSTALL} -d ${PREFIX}/include/noise
	@${CP} -R ${WRKSRC}/include/ ${PREFIX}/include/noise/
	@${RM} -f ${PREFIX}/include/noise/Makefile
#	This line is here to preserve the old behavior of the port.
	@${LN} -sf ${PREFIX}/lib/libnoise.so.0 ${PREFIX}/lib/libnoise.so.0.3

.include <bsd.port.mk>
