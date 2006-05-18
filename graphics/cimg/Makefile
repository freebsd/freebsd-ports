# New ports collection makefile for:	CImg
# Date created:         11 September 2004
# Whom:			thierry@pompo.net
#
# $FreeBSD$
#

PORTNAME=	cimg
DISTVERSION=	1-14
CATEGORIES=	graphics devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	CImg-${DISTVERSION}

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
REINPLACE_ARGS=	-i ""
DOCBASE=	CHANGES.txt README.txt
DOCREFS=	download.shtml favicon.ico favicon.png foot_reference.html	\
		head.html head_reference.html img index.shtml news.html		\
		reference screenshots.shtml
.else
NOBUILD=	yes
.endif

.if !defined(WITHOUT_IM)
RUN_DEPENDS+=	${LOCALBASE}/lib/libMagick.so.9:${PORTSDIR}/graphics/ImageMagick
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

.if !defined(NOPORTDOCS)
post-build:
	cd ${WRKSRC}/documentation && doxygen CImg.doxygen
.endif

do-install:
	${INSTALL_DATA} ${WRKSRC}/CImg.h ${PREFIX}/include
.if !defined(NOPORTDOCS)
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/CImg_demo ${PREFIX}/bin
	${MKDIR} ${DOCSDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${DOCBASE:S|^|${WRKSRC}/|} ${DOCSDIR}
. for doc in ${DOCREFS}
	${CP} -R ${WRKSRC}/documentation/${doc} ${DOCSDIR}
. endfor
	${CP} -R ${WRKSRC}/examples/* ${EXAMPLESDIR}
	@(cd ${EXAMPLESDIR} && ${MAKE} clean)
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${DOCSDIR} ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
