# ex:ts=8
# Ports collection makefile for:	pngwriter
# Date created:			Nov 7, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	pngwriter
PORTVERSION=	0.4.0
CATEGORIES=	graphics devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A C++ library for creating PNG images

LIB_DEPENDS=	png.5:${PORTSDIR}/graphics/png \
		freetype.9:${PORTSDIR}/print/freetype2

BUILD_WRKSRC=	${WRKDIR}/${DISTNAME}/src

CXXFLAGS+=	`freetype-config --cflags` -I${LOCALBASE}/include

do-build:
	cd ${BUILD_WRKSRC} \
		&& ${CXX} ${CXXFLAGS} -c pngwriter.cc -o pngwriter.o \
		&& ${AR} rv libpngwriter.a pngwriter.o

do-install:
	${INSTALL_DATA} ${WRKSRC}/src/pngwriter.h ${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/src/libpngwriter.a ${PREFIX}/lib
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC}/doc && ${FIND} . | \
		${CPIO} -pdm -L -R ${SHAREOWN}:${SHAREGRP} ${DOCSDIR}

	@${MKDIR} ${EXAMPLESDIR}
	cd ${WRKSRC}/examples && ${FIND} . | \
		${CPIO} -pdm -L -R ${SHAREOWN}:${SHAREGRP} ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
