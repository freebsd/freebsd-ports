# New ports collection makefile for:	Open Scene Graph
# Date created:				26 Apr 2001
# Whom:					Randall Hopper <aa8vb@nc.rr.com>
#
# $FreeBSD$
#

PORTNAME=	osg
PORTVERSION=	0.8.38
CATEGORIES=	graphics
MASTER_SITES=	http://www.openscenegraph.org/download/snapshots/
DISTNAME=	${PORTNAME}_src-0.8-38

MAINTAINER=	aa8vb@nc.rr.com

LIB_DEPENDS=	png.5:${PORTSDIR}/graphics/png \
		jpeg.9:${PORTSDIR}/graphics/jpeg

WRKSRC=		${WRKDIR}/OpenSceneGraph-0.8

USE_X_PREFIX=	yes
USE_MESA=	yes
INSTALLS_SHLIB=	yes
USE_GMAKE=	yes
MAKE_ENV=	CXX="${CXX}" \
		PTHREAD_LIBS="${PTHREAD_LIBS}" \
		PTHREAD_CFLAGS="${PTHREAD_CFLAGS}"

ALL_TARGET=	freebsd

post-patch:
.for suf in defs rules
	@${LN} -sf ${WRKSRC}/Make/make${suf}.linux \
		${WRKSRC}/Make/make${suf}.freebsd
.endfor

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/* ${PREFIX}/bin
	${TAR} -C ${WRKSRC}/include -c -f - . | \
		${TAR} -C ${PREFIX}/include --unlink -x -f -
.for lib in osg osgUtil osgGLUT
	${INSTALL_PROGRAM} ${WRKSRC}/lib/lib${lib}.so \
		${PREFIX}/lib/lib${lib}.so.1
	${LN} -sf lib${lib}.so.1 ${PREFIX}/lib/lib${lib}.so
.endfor
	${MKDIR} ${PREFIX}/lib/osgPlugins
	${INSTALL_PROGRAM} ${WRKSRC}/lib/osgPlugins/*.so \
		${PREFIX}/lib/osgPlugins
	${MKDIR} ${PREFIX}/share/doc/osg
	${TAR} -C ${WRKSRC}/doc -c -f - . | \
		${TAR} -C ${PREFIX}/share/doc/osg --unlink -x -f -

.include <bsd.port.mk>
