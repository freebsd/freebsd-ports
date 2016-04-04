# Created by: Fernando Apesteguia <fernando.apesteguia@gmail.com>
# $FreeBSD$

PORTNAME=	openvsp
PORTVERSION=	2.3.0
DISTVERSIONPREFIX=	${GH_PROJECT}_
PORTREVISION=	4
CATEGORIES=	cad

MAINTAINER=	fernando.apesteguia@gmail.com
COMMENT=	Create a 3D model of an aircraft defined by engineering parameters

LICENSE=	NOSA13
LICENSE_NAME=	NASA Open Source Agreement version 1.3
LICENSE_FILE=	${WRKSRC}/LICENSE
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

BUILD_DEPENDS=	${LOCALBASE}/lib/libopenNURBS.a:graphics/opennurbs
LIB_DEPENDS=	libpthread-stubs.so:devel/libpthread-stubs \
		libdrm.so:graphics/libdrm \
		libpng.so:graphics/png \
		libfreetype.so:print/freetype2 \
		libexpat.so:textproc/expat2 \
		libfontconfig.so:x11-fonts/fontconfig \
		libfltk.so:x11-toolkits/fltk

USE_GITHUB=	yes
GH_PROJECT=	OpenVSP
GH_ACCOUNT=	${GH_PROJECT}

CMAKE_SOURCE_PATH=	${WRKSRC}/src
USES=		cmake:outsource dos2unix jpeg
USE_XORG=	ice sm x11 xau xcb xdamage xdmcp xext xfixes xft \
		xinerama xrender xxf86vm
USE_GL=		glu
USE_GNOME=	libxml2
CFLAGS+=	-I${LOCALBASE}/include/openNURBS

PLIST_FILES=	bin/vsp
PORTEXAMPLES=	*

OPTIONS_DEFINE=	EXAMPLES

do-install:
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/vsp/vsp ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	(cd ${WRKSRC}/examples && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR})

.include <bsd.port.mk>
