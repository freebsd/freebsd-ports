# ex:ts=8
# Ports collection Makefile for:	aqsis
# Date created:			Sep 12, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	aqsis
PORTVERSION=	1.2.0
PORTREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	A photorealistic rendering system

BUILD_DEPENDS=	scons:${PORTSDIR}/devel/scons \
   		bjam:${PORTSDIR}/devel/boost \
		bison:${PORTSDIR}/devel/bison \
		xsltproc:${PORTSDIR}/textproc/libxslt
LIB_DEPENDS=	fltk.1:${PORTSDIR}/x11-toolkits/fltk \
   		IlmImf.6:${PORTSDIR}/graphics/OpenEXR \
		tiff.4:${PORTSDIR}/graphics/tiff

USE_LDCONFIG=	yes

SCONS_FLAGS=	boost_include_path='${LOCALBASE}/include' \
		install_prefix='${PREFIX}'

post-patch:
	${REINPLACE_CMD} \
	   -e 's|/usr/lib|${LOCALBASE}/lib|g' \
	   -e 's|/usr/include|${LOCALBASE}/include|g' \
	   -e 's|dl|c|g' \
	   ${WRKSRC}/platform/default/SConscript
	${REINPLACE_CMD} \
	   -e 's|/usr/bin/bison|${LOCALBASE}/bin/bison|g' \
	   ${WRKSRC}/platform/default/Options.py

do-build:
	cd ${WRKSRC} && scons ${SCONS_FLAGS} build

do-install:
	cd ${WRKSRC} && scons ${SCONS_FLAGS} install

.include <bsd.port.mk>
