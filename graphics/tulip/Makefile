# ex:ts=8
# Ports collection makefile for:	tulip
# Date created:			Feb 8, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	tulip
PORTVERSION=	3.8.0
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	SF/auber/${PORTNAME}/${PORTNAME}-${PORTVERSION}
DISTFILES=	${DISTNAME}-src${EXTRACT_SUFX}

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	A system dedicated to the visualization of huge graphs

LIB_DEPENDS=	freetype.9:${PORTSDIR}/print/freetype2 \
   		gzstream.0:${PORTSDIR}/devel/gzstream \
		ftgl.2:${PORTSDIR}/graphics/ftgl \
		qscintilla2:${PORTSDIR}/devel/qscintilla2 \
		jpeg.11:${PORTSDIR}/graphics/jpeg

USE_QT4=	corelib moc_build uic_build rcc_build gui opengl xml network qmake_build \
		designer assistant assistantclient
USE_GL=		glew glut
USE_GNOME=	libxml2
USE_PYTHON=	yes
USE_CMAKE=	yes
CMAKE_OUTSOURCE=yes
CMAKE_ARGS+=	-DLOCALBASE:PATH=${LOCALBASE} \
		-DPYTHON_INCLUDEDIR:PATH=${PYTHON_INCLUDEDIR}
USE_LDCONFIG=	${PREFIX}/lib/tlp

WRKSRC=		${WRKDIR}/${DISTNAME}-src

PLIST_SUB+=	TULIP_VERSION=${PORTVERSION} \
		TULIP_VERS=${PORTVERSION:R}

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64" || ${ARCH} == "ia64"
CFLAGS+=	-fPIC
.endif

.if ${OSVERSION} < 800000
BROKEN=		does not compile on FreeBSD 7.X
.endif

.if !defined(NOPORTDOCS)
DISTFILES+=	${PORTNAME}-${PORTVERSION}-html.tar.bz2
PORTDOCS=	*
post-install:
	${INSTALL} -d ${DOCSDIR}
	(cd ${WRKDIR}/${PORTNAME}-${PORTVERSION}-html && ${COPYTREE_SHARE} \* ${DOCSDIR})
.endif

.include <bsd.port.post.mk>
