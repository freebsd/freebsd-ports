# New ports collection makefile for:	glosm
# Date created:		15 Jan 2011
# Whom:			Dmitry Marakasov <amdmi3@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	glosm
PORTVERSION=	0.0.1
CATEGORIES=	graphics geography
MASTER_SITES=	http://github.com/downloads/AMDmi3/glosm/ \
		http://mirror.amdmi3.ru/distfiles/

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	3D OpenGL renderer for OpenStreetMap

LIB_DEPENDS=	png.6:${PORTSDIR}/graphics/png \
		expat.6:${PORTSDIR}/textproc/expat2

USE_BZIP2=	yes
USE_CMAKE=	yes
USE_GL=		gl glu glut
MAKE_JOBS_SAFE=	yes

PORTDOCS=	README

PLIST_FILES=	bin/glosm-tiler bin/glosm-viewer lib/libglosm.so

regression-test:
	cd ${BUILD_WRKSRC} && ctest

.if !defined(NOPORTDOCS)
post-install:
	${MKDIR} ${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}/
.endfor
.endif

.include <bsd.port.mk>
