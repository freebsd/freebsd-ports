# New ports collection makefile for:	libnoise
# Date created:		28 August 2006
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libnoise
DISTVERSION=	1.0.0-RC1
CATEGORIES=	audio
MASTER_SITES=	SF
DISTNAME=	${PORTNAME}src-${DISTVERSION}

MAINTAINER=	infofarmer@FreeBSD.org
COMMENT=	Generates three-dimensional coherent noise

BUILD_DEPENDS=	libtool:${PORTSDIR}/devel/libtool15

USE_ZIP=	yes
USE_GMAKE=	yes
USE_LDCONFIG=	yes
CXXFLAGS+=	-O3 -fomit-frame-pointer
WRKSRC=		${WRKDIR}/noise

do-install:
	@${CP} -R ${WRKSRC}/lib/${PORTNAME}.* ${PREFIX}/lib/
	@${INSTALL} -d ${PREFIX}/include/noise
	@${CP} -R ${WRKSRC}/include/ ${PREFIX}/include/noise/
	@${RM} -f ${PREFIX}/include/noise/Makefile
	@${LN} -sf ${PREFIX}/lib/libnoise.so.0.3 ${PREFIX}/lib/libnoise.so.0

.include <bsd.port.mk>
