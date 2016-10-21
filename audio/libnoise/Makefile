# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libnoise
DISTVERSION=	1.0.0
PORTREVISION=	4
CATEGORIES=	audio
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}%20sources/${PORTVERSION}
DISTNAME=	${PORTNAME}src-${DISTVERSION}
EXTRACT_SUFX=	.zip

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Generates three-dimensional coherent noise

LICENSE=	LGPL21
LICENSE_FILE=	${WRKDIR}/COPYING.txt

USES=		dos2unix gmake libtool:build zip
DOS2UNIX_FILES=	${WRKSRC}/src/Makefile
USE_LDCONFIG=	yes
CXXFLAGS+=	-O3 -fomit-frame-pointer
WRKSRC=		${WRKDIR}/noise

post-patch:
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g' \
		${WRKSRC}/src/Makefile
	@${REINPLACE_CMD} -e 's|include lib:|include:|g' \
		${WRKSRC}/Makefile

post-build:
	${STRIP_CMD} ${WRKSRC}/src/.libs/libnoise.so

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/lib
	(cd ${WRKSRC}/src && ${LOCALBASE}/bin/libtool --mode=install \
		${INSTALL_LIB} libnoise.la ${STAGEDIR}${PREFIX}/lib)
	(cd ${WRKSRC}/include && \
		${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/include/noise)
	${RM} ${STAGEDIR}${PREFIX}/include/noise/Makefile

.include <bsd.port.mk>
