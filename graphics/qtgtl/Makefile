# $FreeBSD$

PORTNAME=	qtgtl
PORTVERSION=	0.9.3
CATEGORIES=	graphics devel
MASTER_SITES=	http://download.opengtl.org/
DISTNAME=	libQtGTL-${PORTVERSION}

MAINTAINER=	avilla@FreeBSD.org
COMMENT=	Qt bindings for the Graphics Transformation Languages

LICENSE=	LGPL20

LIB_DEPENDS=	libGTLCore.so:graphics/opengtl

USE_QT4=	corelib gui moc_build qmake_build rcc_build uic_build
USES=		cmake:outsource pkgconfig tar:bzip2
USE_LDCONFIG=	yes

DESCR=		${.CURDIR:H:H}/graphics/opengtl/pkg-descr

PORTEXAMPLES=	QtCTL QtShiva

OPTIONS_DEFINE=	EXAMPLES

pre-configure:
	@${REINPLACE_CMD} -e 's,set(QTGTL_LIB_SOVERSION.*,set(QTGTL_LIB_SOVERSION "0"),' \
		${PATCH_WRKSRC}/CMakeLists.txt
	@${REINPLACE_CMD} -e 's,$${LIB_INSTALL_DIR}/pkgconfig,${PREFIX}/libdata/pkgconfig,g' \
		${PATCH_WRKSRC}/QtGTL/CMakeLists.txt \
		${PATCH_WRKSRC}/QtShiva/CMakeLists.txt

post-install:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
.for f in ${PORTEXAMPLES}
	cd ${WRKSRC}/examples && ${COPYTREE_SHARE} ${f} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_PROGRAM} ${INSTALL_WRKSRC}/examples/${f}/${f:S/Qt/q/} \
		${STAGEDIR}${EXAMPLESDIR}/${f}
.endfor

.include <bsd.port.mk>
