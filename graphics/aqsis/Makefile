# Created by: ijliao
# $FreeBSD$

PORTNAME=	aqsis
PORTVERSION=	1.8.2
PORTREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-source/${PORTVERSION}

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	A photorealistic rendering system

LICENSE=	BSD GPLv2
LICENSE_COMB=	multi

BUILD_DEPENDS=	bison:${PORTSDIR}/devel/bison \
		xsltproc:${PORTSDIR}/textproc/libxslt
LIB_DEPENDS=	IlmImf:${PORTSDIR}/graphics/OpenEXR \
    		boost_filesystem:${PORTSDIR}/devel/boost-libs \
		tiff.4:${PORTSDIR}/graphics/tiff \
		fltk.1:${PORTSDIR}/x11-toolkits/fltk

LDFLAGS+=	-L${LOCALBASE}/lib

USE_LDCONFIG=	yes
USES=		cmake:outsource
USE_QT4=	opengl qmake_build moc_build rcc_build uic_build
PLIST_SUB+=	LIBVERS=${PORTVERSION:R}

INSTALLS_ICONS=	yes

NO_STAGE=	yes
.include <bsd.port.mk>
