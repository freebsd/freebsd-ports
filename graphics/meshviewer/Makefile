# Created by: ijliao
# $FreeBSD$

PORTNAME=	meshviewer
PORTVERSION=	0.3.3
PORTREVISION=	5
CATEGORIES=	graphics
MASTER_SITES=	SF/mview/mview/${PORTVERSION}
DISTNAME=	mview-src-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Mesh viewer

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

WRKSRC=		${WRKDIR}/mview-${PORTVERSION}

USES=		gmake pkgconfig
USE_GL=		glu
USE_QT4=	corelib gui opengl moc_build
CXXFLAGS+=	-I. -Imesh -Imathvector \
		`pkg-config --cflags QtOpenGL glu`
LDFLAGS+=	-lpthread `pkg-config --libs QtOpenGL glu`
MAKE_ARGS=	QTDIR="${QT_PREFIX}" CC="${CXX}" MOC="${MOC}" \
		CXXFLAGS="${CXXFLAGS}" \
		LIBPATH="" LIBS_QT4="${LDFLAGS}"

PLIST_FILES=	bin/${PORTNAME}
PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's|make |$$(MAKE) |g' -e 's|CPPFLAGS|CXXFLAGS|g' \
		${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's|<values.h>|<cmath>|g' ${WRKSRC}/mesh/mesh.cpp

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mview ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

do-install-DOCS-on:
	@cd ${WRKSRC} && ${COPYTREE_SHARE} "AUTHORS README TODO Documentation" \
		${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
