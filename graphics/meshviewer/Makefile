# ex:ts=8
# Ports collection makefile for:	meshviewer
# Date created:			Jun 10, 2002
# Whom:				ijliao
#
# $FreeBSD$

PORTNAME=	meshviewer
PORTVERSION=	0.3.2
CATEGORIES=	graphics
MASTER_SITES=	SF/mview/mview/${PORTVERSION}
DISTNAME=	mview-src-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Mesh Viewer

USE_QT_VER=	4
QT_COMPONENTS=	corelib gui opengl moc_build qmake_build

PORTDOCS=	*
PLIST_FILES=	bin/mview

post-extract:
	@${RM} -f ${WRKSRC}/qt4/*.moc.cpp

post-patch:
	@${ECHO_CMD} "QT += opengl" >> ${WRKSRC}/mview.pro
	@${REINPLACE_CMD} -e 's|<values.h>|<cmath>|g' ${WRKSRC}/mesh/mesh.cpp

do-configure:
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} \
		${QMAKE} -spec ${QMAKESPEC} GUI="QT4"

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mview ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@(cd ${WRKSRC}/Documentation && ${COPYTREE_SHARE} . ${DOCSDIR})
.endif

.include <bsd.port.mk>
