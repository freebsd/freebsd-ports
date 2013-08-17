# $FreeBSD$

PORTNAME=	oyranos
PORTVERSION=	0.9.4
CATEGORIES=	graphics
MASTER_SITES=	SF/${PORTNAME}/Oyranos/Oyranos%20${PORTVERSION:C|(.*)\.[0-9]*$|\1|}

MAINTAINER=	bsam@FreeBSD.org
COMMENT=	Colour Management System (CMS)

BUILD_DEPENDS=	${LOCALBASE}/bin/doxygen:${PORTSDIR}/devel/doxygen
RUN_DEPENDS=	${LOCALBASE}/share/color/icc/OpenICC/sRGB.icc:${PORTSDIR}/graphics/icc-profiles-openicc \
		${LOCALBASE}/share/color/icc/basICColor/ISOcoated_v2_300_bas.ICC:${PORTSDIR}/graphics/icc-profiles-basiccolor
LIB_DEPENDS=	raw:${PORTSDIR}/graphics/libraw \
		xml2:${PORTSDIR}/textproc/libxml2 \
		exiv2:${PORTSDIR}/graphics/exiv2 \
		png15:${PORTSDIR}/graphics/png \
		cairo:${PORTSDIR}/graphics/cairo \
		yajl:${PORTSDIR}/devel/yajl \
		fltk:${PORTSDIR}/x11-toolkits/fltk \
		cups:${PORTSDIR}/print/cups-client \
		xdot:${PORTSDIR}/graphics/graphviz \
		lcms:${PORTSDIR}/graphics/lcms \
		lcms2:${PORTSDIR}/graphics/lcms2 \
		Xcm:${PORTSDIR}/x11/libXcm

USES=		cmake gettext pkgconfig
USE_BZIP2=	yes
USE_GL=		yes
USE_LDCONFIG=	yes
USE_GNOME=	libxml2
USE_QT4=	gui moc_build qmake_build rcc_build uic_build
USE_XORG=	xfixes xinerama xrandr xxf86vm
CMAKE_ARGS+=	-DXDG_CONFIG_DIR=${PREFIX}/etc/xdg
LDFLAGS+=	-L${LOCALBASE}/lib -liconv

MAN1=		oyranos-config-fltk.1 oyranos-monitor-daemon.1 oyranos-monitor.1 \
		oyranos-policy.1 oyranos-profile-graph.1 oyranos-profile-install.1 \
		oyranos-profile.1 oyranos-profiles.1 oyranos-xforms-modules.1 qcmsevents.1
MAN3=		oyranos-config.3 oyranos.3

.include <bsd.port.pre.mk>

.if exists(/usr/bin/clang) && ${OSVERSION} > 901502
CC=		/usr/bin/clang
CXX=		/usr/bin/clang++
.else
USE_GCC=	yes
.endif

.include <bsd.port.post.mk>
