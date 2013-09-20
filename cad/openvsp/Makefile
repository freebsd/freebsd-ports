# Created by: Fernando Apesteguia <fernando.apesteguia@gmail.com>
# $FreeBSD$

PORTNAME=	openvsp
PORTVERSION=	2.2.4
CATEGORIES=	cad

MAINTAINER=	fernando.apesteguia@gmail.com
COMMENT=	Create a 3D model of an aircraft defined by engineering parameters

BUILD_DEPENDS=	${LOCALBASE}/lib/libopenNURBS.a:${PORTSDIR}/graphics/opennurbs
LIB_DEPENDS=	pthread-stubs:${PORTSDIR}/devel/libpthread-stubs \
		jpeg:${PORTSDIR}/graphics/jpeg \
		drm:${PORTSDIR}/graphics/libdrm \
		png15:${PORTSDIR}/graphics/png \
		freetype:${PORTSDIR}/print/freetype2 \
		expat:${PORTSDIR}/textproc/expat2 \
		fontconfig:${PORTSDIR}/x11-fonts/fontconfig \
		fltk:${PORTSDIR}/x11-toolkits/fltk

USE_GITHUB=	yes
GH_PROJECT=	OpenVSP
GH_ACCOUNT=	${GH_PROJECT}
GH_TAGNAME=	${GH_PROJECT}_${PORTVERSION}
GH_COMMIT=	5e7532c

CMAKE_SOURCE_PATH=	${WRKSRC}/src
USES=		cmake:outsource iconv
USE_DOS2UNIX=	yes
USE_XORG=	ice sm x11 xau xcb xdamage xdmcp xext xfixes xft \
		xinerama xrender xxf86vm
USE_GL=		glu
USE_GNOME=	libxml2

PORTEXAMPLES=	*

PLIST_FILES=	bin/vsp

CFLAGS+=	-I${LOCALBASE}/include/openNURBS

NO_STAGE=	yes
.include <bsd.port.options.mk>

do-install:
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/vsp/vsp ${PREFIX}/bin
.if ${PORT_OPTIONS:MEXAMPLES}
	@${MKDIR} ${EXAMPLESDIR}
	(cd ${WRKSRC}/examples && ${COPYTREE_SHARE} \* ${EXAMPLESDIR})
.endif

.include <bsd.port.mk>
