# New ports collection makefile for:	CImg
# Date created:         11 September 2004
# Whom:			thierry@pompo.net
#
# $FreeBSD$
#

PORTNAME=	cimg
PORTVERSION=	1.0.7
PORTREVISION=	2
CATEGORIES=	graphics devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	CImg-${PORTVERSION:S/./_/:S/.//}

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	The C++ Template Image Processing Library

USE_ZIP=	yes
BUILD_WRKSRC=	${WRKSRC}/examples
MAKE_ENV=	CPPFLAGS="${CFLAGS} ${LAPACK_DEF} ${PTHREAD_CFLAGS}"	\
		LDFLAGS="${LDFLAGS} ${LAPACK_LIB} ${PTHREAD_LIBS}"	\
		X11PATH=${X11BASE}

.if !defined(NOPORTDOCS)
BUILD_DEPENDS+=	doxygen:${PORTSDIR}/devel/doxygen
USE_GCC=	3.4
USE_REINPLACE=	yes
REINPLACE_ARGS=	-i ""
DOCBASE=	CHANGES.txt README.txt
.else
NOBUILD=	yes
.endif

.if !defined(WITHOUT_IM)
RUN_DEPENDS+=	${LOCALBASE}/lib/libMagick.so.7:${PORTSDIR}/graphics/ImageMagick
.endif
.if !defined(WITHOUT_LAPACK)
LIB_DEPENDS+=	atlas:${PORTSDIR}/math/atlas
LAPACK_LIB=	-L${LOCALBASE}/lib -lalapack -lcblas -lf77blas -lg2c -latlas
LAPACK_DEF=	-Dcimg_lapack
.endif

#post-extract:
#	@${CP} ${WRKSRC}/CImg.h ${WRKSRC}/CImg.h.dos
#	@${TR} -d '\r' < ${WRKSRC}/CImg.h.dos > ${WRKSRC}/CImg.h

.if !defined(NOPORTDOCS)
post-patch:
	@${GREP} -lR 'img/' ${BUILD_WRKSRC} |	\
		${XARGS} ${REINPLACE_CMD} -e 's|img/|${EXAMPLESDIR}/img/|g'
.endif

do-install:
	${INSTALL_DATA} ${WRKSRC}/CImg.h ${PREFIX}/include
.if !defined(NOPORTDOCS)
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/CImg_test ${PREFIX}/bin
	${MKDIR} ${DOCSDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${DOCBASE:S|^|${WRKSRC}/|} ${DOCSDIR}
	${CP} -R ${WRKSRC}/documentation/* ${DOCSDIR}
	${CP} -R ${WRKSRC}/examples/* ${EXAMPLESDIR}
	@(cd ${EXAMPLESDIR} && ${MAKE} clean)
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${DOCSDIR} ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
