# Created by: ijliao
# $FreeBSD$

PORTNAME=	meshviewer
PORTVERSION=	0.3.3
PORTREVISION=	5
CATEGORIES=	graphics
MASTER_SITES=	SF/mview/mview/${PORTVERSION}
DISTNAME=	mview-src-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Mesh Viewer

LICENSE=	GPLv2

WRKSRC=		${WRKDIR}/mview-${PORTVERSION}

USES=		gmake pkgconfig
USE_GL=		glu
USE_QT4=	corelib gui opengl moc_build
CXXFLAGS+=	-I. -Imesh -Imathvector \
		`pkg-config --cflags QtOpenGL glu`
LDFLAGS+=	${PTHREAD_LIBS} \
		`pkg-config --libs QtOpenGL glu`
MAKE_ARGS=	QTDIR="${QT_PREFIX}" CC="${CXX}" MOC="${MOC}" \
		CXXFLAGS="${CXXFLAGS}" \
		LIBPATH="" LIBS_QT4="${LDFLAGS}"

DOCSRCDIR1=	${WRKSRC}
DOC_FILES1=	AUTHORS README TODO

DOCSRCDIR2=	${WRKSRC}/Documentation/pics
DOCSDIR2=	${DOCSDIR}/Documentation/pics
DOC_FILES2=	*.jpg

DOCSRCDIR3=	${WRKSRC}/Documentation
DOCSDIR3=	${DOCSDIR}/Documentation
DOC_FILES3=	*.html *.ico

PLIST_FILES=	bin/${PORTNAME}
PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's|make |$$(MAKE) |g' -e 's|CPPFLAGS|CXXFLAGS|g' ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's|<values.h>|<cmath>|g' ${WRKSRC}/mesh/mesh.cpp

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mview ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	@${MKDIR} ${STAGEDIR}${DOCSDIR2}
	${INSTALL_DATA} ${DOC_FILES1:S|^|${DOCSRCDIR1}/|} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${DOC_FILES2:S|^|${DOCSRCDIR2}/|} ${STAGEDIR}${DOCSDIR2}
	${INSTALL_DATA} ${DOC_FILES3:S|^|${DOCSRCDIR3}/|} ${STAGEDIR}${DOCSDIR3}

.include <bsd.port.mk>
