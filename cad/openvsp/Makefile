# Created by: Fernando Apesteguia <fernando.apesteguia@gmail.com>
# $FreeBSD$

PORTNAME=	openvsp
PORTVERSION=	2.2.1
CATEGORIES=	cad
MASTER_SITES=	https://github.com/OpenVSP/OpenVSP/archive/

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
		fltk:${PORTSDIR}/x11-toolkits/fltk \
		xcb:${PORTSDIR}/x11/libxcb
WRKSRC=		${WRKDIR}/OpenVSP-OpenVSP_${PORTVERSION}/src

USE_CMAKE=	yes
USE_DOS2UNIX=	yes
USE_ICONV=	yes
USE_XORG=	ice sm x11 xau xdamage xdmcp xext xfixes xft \
		xinerama xrender xxf86vm
USE_GL=		glu
USE_GNOME=	libxml2

PORTEXAMPLES=	*
INSTALL_PORTEXAMPLES=	@(cd ${WRKSRC}/../examples/ && ${COPYTREE_SHARE} \* ${EXAMPLESDIR})

PLIST_FILES=	bin/vsp

CFLAGS+=	-I${LOCALBASE}/include/openNURBS

do-fetch:
	if [ ! -f ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX} ]; then \
		${FETCH_BINARY} -o ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX} \
			${MASTER_SITES}OpenVSP_${PORTVERSION}${EXTRACT_SUFX}; \
	fi

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/vsp/vsp ${PREFIX}/bin
.if !defined(NOPORTEXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}
	@${INSTALL_PORTEXAMPLES}
.endif

.include <bsd.port.mk>
