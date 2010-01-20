# ex:ts=8
# Ports collection Makefile for:	aqsis
# Date created:			Sep 12, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	aqsis
PORTVERSION=	1.6.0
CATEGORIES=	graphics
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-source/${PORTVERSION}

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	A photorealistic rendering system

LIB_DEPENDS=	IlmImf.6:${PORTSDIR}/graphics/OpenEXR \
		boost_filesystem.4:${PORTSDIR}/devel/boost-libs \
		tiff.4:${PORTSDIR}/graphics/tiff \

BUILD_DEPENDS=	bison:${PORTSDIR}/devel/bison \
		xsltproc:${PORTSDIR}/textproc/libxslt \
		fltk-threads>=0:${PORTSDIR}/x11-toolkits/fltk-threads

LDFLAGS+=	-L${LOCALBASE}/lib

USE_LDCONFIG=	yes
USE_CMAKE=	yes
CMAKE_USE_PTHREAD=	yes

INSTALLS_ICONS=	yes

# Required for off-source building
CMAKE_BUILD_PATH=	${WRKSRC}/build
CMAKE_SOURCE_PATH=	${WRKSRC}/
CONFIGURE_WRKSRC=	${CMAKE_BUILD_PATH}
BUILD_WRKSRC=		${CMAKE_BUILD_PATH}
INSTALL_WRKSRC=		${CMAKE_BUILD_PATH}

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 700000
BROKEN=		does not compile on 6.X
.endif

post-extract:
	${MKDIR} ${CMAKE_BUILD_PATH}

.include <bsd.port.post.mk>
