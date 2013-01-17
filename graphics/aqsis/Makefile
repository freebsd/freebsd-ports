# ex:ts=8
# Ports collection Makefile for:	aqsis
# Date created:			Sep 12, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	aqsis
PORTVERSION=	1.8.2
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-source/${PORTVERSION}

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	A photorealistic rendering system

LICENSE=	BSD GPLv2
LICENSE_COMB=	multi

BUILD_DEPENDS=	bison:${PORTSDIR}/devel/bison \
		xsltproc:${PORTSDIR}/textproc/libxslt
LIB_DEPENDS=	IlmImf:${PORTSDIR}/graphics/OpenEXR \
    		boost_filesystem.4:${PORTSDIR}/devel/boost-libs \
		tiff.4:${PORTSDIR}/graphics/tiff \
		fltk.1:${PORTSDIR}/x11-toolkits/fltk

LDFLAGS+=	-L${LOCALBASE}/lib

USE_LDCONFIG=	yes
USE_CMAKE=	yes
CMAKE_OUTSOURCE=	yes
CMAKE_VERBOSE=	yes
USE_QT4=	opengl qmake_build moc_build rcc_build uic_build
PLIST_SUB+=	LIBVERS=${PORTVERSION:R}

INSTALLS_ICONS=	yes

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 800000
BROKEN=		does not compile on FreeBSD 7.X
.endif

.include <bsd.port.post.mk>
