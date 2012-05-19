# ex:ts=8
# Ports collection Makefile for:	aqsis
# Date created:			Sep 12, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	aqsis
PORTVERSION=	1.8.0
PORTREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-source/${PORTVERSION}
DISTNAME=	Aqsis-${PORTVERSION}-Source

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	A photorealistic rendering system

LICENSE=	BSD GPLv2
LICENSE_COMB=	multi

BUILD_DEPENDS=	bison:${PORTSDIR}/devel/bison \
		xsltproc:${PORTSDIR}/textproc/libxslt
LIB_DEPENDS=	IlmImf.6:${PORTSDIR}/graphics/OpenEXR \
    		boost_filesystem.4:${PORTSDIR}/devel/boost-libs \
		tiff.4:${PORTSDIR}/graphics/tiff \
		fltk.1:${PORTSDIR}/x11-toolkits/fltk

LDFLAGS+=	-L${LOCALBASE}/lib

USE_LDCONFIG=	yes
USE_CMAKE=	yes
CMAKE_OUTSOURCE=	yes
CMAKE_VERBOSE=	yes
USE_QT_VER=	4
QT_COMPONENTS=	opengl qmake_build moc_build rcc_build uic_build
PLIST_SUB+=	LIBVERS=${PORTVERSION:R}

INSTALLS_ICONS=	yes

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 700000
BROKEN=		does not compile on 6.X
.endif

.include <bsd.port.post.mk>
