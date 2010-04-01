# ex:ts=8
# Ports collection Makefile for:	aqsis
# Date created:			Sep 12, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	aqsis
PORTVERSION=	1.6.0
PORTREVISION=	3
CATEGORIES=	graphics
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-source/${PORTVERSION}

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	A photorealistic rendering system

LIB_DEPENDS=	IlmImf.6:${PORTSDIR}/graphics/OpenEXR \
    		boost_filesystem.4:${PORTSDIR}/devel/boost-libs \
		tiff.4:${PORTSDIR}/graphics/tiff \
		fltk.1:${PORTSDIR}/x11-toolkits/fltk

BUILD_DEPENDS=	bison:${PORTSDIR}/devel/bison \
		xsltproc:${PORTSDIR}/textproc/libxslt

LDFLAGS+=	-L${LOCALBASE}/lib

USE_LDCONFIG=	yes
USE_CMAKE=	yes
CMAKE_USE_PTHREAD=	yes
CMAKE_OUTSOURCE=	yes

INSTALLS_ICONS=	yes

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 700000
BROKEN=		does not compile on 6.X
.endif

.include <bsd.port.post.mk>
