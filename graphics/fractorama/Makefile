# Created by: Ying-Chieh Liao <ijliao@FreeBSD.org>
# $FreeBSD$

PORTNAME=	fractorama
PORTVERSION=	1.6.7
PORTREVISION=	8
CATEGORIES=	graphics
MASTER_SITES=	CRITICAL
MASTER_SITE_SUBDIR=	${PORTNAME}/${PORTVERSION}
DISTNAME=	${PORTNAME}
DIST_SUBDIR=	${PORTNAME}/${PORTVERSION}

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Fractal generation program

LIB_DEPENDS=	tiff.4:${PORTSDIR}/graphics/tiff

USE_QT_VER=	3
USES=		bison gmake
MAKE_JOBS_UNSAFE=	yes

MAKE_ENV=	QTCPPFLAGS="${QTCPPFLAGS} ${PTHREAD_CFLAGS}" \
		QTCFGLIBS="${QTCFGLIBS} ${PTHREAD_LIBS}"

WRKSRC=		${WRKDIR}/${DISTNAME}/src
ALL_TARGET=	release

CXXFLAGS+=	-I${LOCALBASE}/include

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

post-extract:
.for e in cpp h
	@${CP} ${WRKSRC}/lib/tiff/TiffWriter.${e} ${WRKSRC}
.endfor
	@${RM} -rf ${WRKSRC}/lib/tiff

pre-build:
	${CXX} ${CXXFLAGS} -c -o ${WRKSRC}/TiffWriter.o ${WRKSRC}/TiffWriter.cpp

post-patch:
	@${FIND} ${WRKSRC} -name "Makefile" | ${XARGS} ${REINPLACE_CMD} -e \
		's|gcc|$${CC}| ; \
		 s|g++|$${CXX}| ; \
		 s|-L$${QTROOT}/lib -lqt|-lqt-mt $${QTCFGLIBS}| ; \
		 s|-I$${QTROOT}/include|$${QTCPPFLAGS}| ; \
		 s|-O2|$${CXXFLAGS}| ; \
		 /WARN.*:=/d'
	@${REINPLACE_CMD} -e 's|/tools/qt-3.0.4|$${LOCALBASE}|' \
		${WRKSRC}/directories.inc
	@${REINPLACE_CMD} -e 's|\(VariableComplexNode::\(evaluate\)\)|\2|' \
		${WRKSRC}/lib/fractal/VariableComplexNode.h

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/../fractorama.exe ${PREFIX}/bin/fractorama
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	cd ${WRKSRC}/../doc && ${FIND} . | \
		${CPIO} -pdm -L -R ${SHAREOWN}:${SHAREGRP} ${DOCSDIR}
	${MKDIR} ${EXAMPLESDIR}
	cd ${WRKSRC}/../examples && ${FIND} . | \
		${CPIO} -pdm -L -R ${SHAREOWN}:${SHAREGRP} ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
