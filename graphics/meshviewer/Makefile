# ex:ts=8
# Ports collection makefile for:	meshviewer
# Date created:			Jun 10, 2002
# Whom:				ijliao
#
# $FreeBSD$

PORTNAME=	meshviewer
PORTVERSION=	0.3.3
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	SF/mview/mview/${PORTVERSION}
DISTNAME=	mview-src-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Mesh Viewer

WRKSRC=		${WRKDIR}/mview-${PORTVERSION}

USE_QT_VER=	4
QT_COMPONENTS=	corelib gui opengl moc_build
USE_GMAKE=	yes
LDFLAGS+=	${PTHREAD_LIBS}
MAKE_ARGS=	QTDIR="${QT_PREFIX}" CC="${CXX}" MOC="${MOC}" \
		CPPFLAGS="${CPPFLAGS}" FLAGS="${CXXFLAGS}" \
		LIBPATH="" LIBS_QT4="${LDFLAGS}"

PORTDOCS=	*
PLIST_FILES=	bin/mview

CPPFLAGS+=	-I. -Imesh -Imathvector \
		`pkg-config --cflags QtOpenGL glu`
LDFLAGS+=	`pkg-config --libs QtOpenGL glu`

post-patch:
	@${REINPLACE_CMD} -e 's|make |$$(MAKE) |g' ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's|<values.h>|<cmath>|g' ${WRKSRC}/mesh/mesh.cpp

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mview ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@(cd ${WRKSRC}/Documentation && ${COPYTREE_SHARE} . ${DOCSDIR})
.endif

.include <bsd.port.mk>
