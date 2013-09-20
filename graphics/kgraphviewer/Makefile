# $FreeBSD$

PORTNAME=	kgraphviewer
PORTVERSION=	${APP_VER}.${EXTRA_VER}
PORTREVISION=	5
CATEGORIES=	graphics kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	stable/extragear
DISTNAME=	${PORTNAME}-${APP_VER}-kde${EXTRA_VER}
DIST_SUBDIR=	KDE/extragear

MAINTAINER=	kde@FreeBSD.org
COMMENT=	GraphViz dot graph viewer for KDE

LIB_DEPENDS=	gvc:${PORTSDIR}/graphics/graphviz

NO_STAGE=	yes
# Several problems at once here:
# - The port does not include graphviz's include directory, assuming it is
#   always in the compiler's default path (ie. /usr/include).
# - The port includes <graphviz/foo.h>, while code is expected to include
#   <foo.h> instead, and pass -I${LOCALBASE}/graphviz instead of just
#   -I${LOCALBASE} to the compiler.
# - The code in the development repository does a better job at fixing the
#   problems above, but it still relies on the deprecated libgraph library that
#   graphics/graphviz in ports does not install anymore.
BROKEN=		does not build

USE_BZIP2=	yes
USE_KDE4=	kdelibs pimlibs kdeprefix kdehier automoc4
USE_QT4=	corelib qmake_build moc_build rcc_build uic_build
USES=		cmake

APP_VER=	2.0.2
EXTRA_VER=	4.4.0

post-patch:
#Fix build with kdelibs>=4.5.0
	${REINPLACE_CMD} -e 's,V4.1.2-Based,V4.2-Based,g' \
		${WRKSRC}/doc-translations/*_kgraphviewer/kgraphviewer/index.docbook \
		${WRKSRC}/doc/index.docbook

.include <bsd.port.mk>
