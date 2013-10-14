# Created by: Fernando Apesteguia <fernando.apesteguia@gmail.com>
# $FreeBSD$

PORTNAME=	openvsp
PORTVERSION=	2.2.5
CATEGORIES=	cad
MASTER_SITES=	GH

MAINTAINER=	fernando.apesteguia@gmail.com
COMMENT=	Create a 3D model of an aircraft defined by engineering parameters

LICENSE=	NOSA13
LICENSE_NAME=	NASA Open Source Agreement version 1.3
LICENSE_FILE=	${WRKSRC}/LICENSE
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

BUILD_DEPENDS=	${LOCALBASE}/lib/libopenNURBS.a:${PORTSDIR}/graphics/opennurbs
LIB_DEPENDS=	libpthread-stubs.so:${PORTSDIR}/devel/libpthread-stubs \
		libjpeg.so:${PORTSDIR}/graphics/jpeg \
		libdrm.so:${PORTSDIR}/graphics/libdrm \
		libpng15.so:${PORTSDIR}/graphics/png \
		libfreetype.so:${PORTSDIR}/print/freetype2 \
		libexpat.so:${PORTSDIR}/textproc/expat2 \
		libfontconfig.so:${PORTSDIR}/x11-fonts/fontconfig \
		libfltk.so:${PORTSDIR}/x11-toolkits/fltk

USE_GITHUB=	yes
GH_PROJECT=	OpenVSP
GH_ACCOUNT=	${GH_PROJECT}
GH_TAGNAME=	${GH_PROJECT}_${PORTVERSION}
GH_COMMIT=	4c359c8

CMAKE_SOURCE_PATH=	${WRKSRC}/src
USES=		cmake:outsource iconv
USE_DOS2UNIX=	yes
USE_XORG=	ice sm x11 xau xcb xdamage xdmcp xext xfixes xft \
		xinerama xrender xxf86vm
USE_GL=		glu
USE_GNOME=	libxml2
CFLAGS+=	-I${LOCALBASE}/include/openNURBS

PLIST_FILES=	bin/vsp
PORTEXAMPLES=	*

OPTIONS_DEFINE=	EXAMPLES

.include <bsd.port.options.mk>

do-install:
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/vsp/vsp ${STAGEDIR}${PREFIX}/bin
.if ${PORT_OPTIONS:MEXAMPLES}
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	(cd ${WRKSRC}/examples && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR})
.endif

.include <bsd.port.mk>
