# ex:ts=8
# Ports collection makefile for:	ptypes
# Date created:			Aug 12, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	ptypes
PORTVERSION=	1.8.2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	sem@ciam.ru
COMMENT=	C++ Portable Types Library

SHLIB_VER=	1
INSTALLS_SHLIB=	yes
MAKE_ARGS+=	SHLIB_VER=${SHLIB_VER} PTHREAD_LIBS=${PTHREAD_LIBS} \
		PTHREAD_CFLAGS=${PTHREAD_CFLAGS}

do-install:
	${MKDIR} ${PREFIX}/include/ptypes
	${INSTALL_DATA} ${WRKSRC}/include/* ${PREFIX}/include/ptypes
	${MKDIR} ${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/so/libptypes.so.${SHLIB_VER} \
		${PREFIX}/lib
	cd ${PREFIX}/lib; ${LN} -s libptypes.so.${SHLIB_VER} libptypes.so
	${INSTALL_DATA} ${WRKSRC}/lib/* ${PREFIX}/lib
.if !defined(NOPORTDOCS)
	${MKDIR} ${EXAMPLESDIR}/wshare
	-${RM} -f ${WRKSRC}/wshare/*.o ${WRKSRC}/wshare/*.orig
	${INSTALL_DATA} ${WRKSRC}/wshare/*.* ${EXAMPLESDIR}/wshare
	${INSTALL_PROGRAM} ${WRKSRC}/wshare/wshare ${EXAMPLESDIR}/wshare
	${MKDIR} ${DOCSDIR}/doc
	${INSTALL_DATA} ${WRKSRC}/LICENSE ${WRKSRC}/index.html ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/* ${DOCSDIR}/doc
.endif

.include <bsd.port.mk>
