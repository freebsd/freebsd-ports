# Created by: Martin Dieringer <martin.dieringe@gmx.de>
# $FreeBSD$

PORTNAME=	repsnapper
PORTVERSION=	2.2.0a4
CATEGORIES=	cad
MASTER_SITES=	https://codeload.github.com/timschmidt/repsnapper/tar.gz/
DISTNAME=	${PORTVERSION}
EXTRACT_SUFX=	#
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	martin.dieringer@gmx.de
COMMENT=	Controller and GCode generator for RepRap 3D printers

LICENSE=	GPLv2 BSD MIT
LICENSE_COMB=	multi

BUILD_DEPENDS=	p5-XML-Parser>=0:${PORTSDIR}/textproc/p5-XML-Parser
LIB_DEPENDS=	gtkglext:${PORTSDIR}/x11-toolkits/gtkglext \
		gtkmm-2:${PORTSDIR}/x11-toolkits/gtkmm24 \
		glademm-2:${PORTSDIR}/devel/libglademm24 \
		cairomm-1:${PORTSDIR}/graphics/cairomm \
		zip:${PORTSDIR}/archivers/libzip \
		atkmm-1.6:${PORTSDIR}/accessibility/atkmm \
		glibmm-2.4:${PORTSDIR}/devel/glibmm \
		pthread-stubs:${PORTSDIR}/devel/libpthread-stubs \
		sigc-2.0:${PORTSDIR}/devel/libsigc++20 \
		pcre:${PORTSDIR}/devel/pcre \
		drm:${PORTSDIR}/graphics/libdrm \
		png15:${PORTSDIR}/graphics/png \
		freetype:${PORTSDIR}/print/freetype2 \
		expat:${PORTSDIR}/textproc/expat2 \
		xml++-2.6:${PORTSDIR}/textproc/libxml++26 \
		fontconfig:${PORTSDIR}/x11-fonts/fontconfig \
		pangomm-1.4:${PORTSDIR}/x11-toolkits/pangomm

USES=		pkgconfig iconv
USE_GNOME=	gdkpixbuf2 gtk20 libxml2
USE_GL=		glu glut
USE_AUTOTOOLS=	automake libtool
USE_GMAKE=	yes
USE_XORG=	ice pixman sm x11 xau xcb composite xcursor xdamage xdmcp \
		xext xfixes xi xinerama xmu xrandr xrender xt xxf86vm

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
INSTALL_TARGET=	install-strip
CONFIGURE_ARGS=	--prefix=${PREFIX}

pre-configure:
	cd ${WRKSRC} && ./autogen.sh

post-configure:
	@${REINPLACE_CMD} 's|src/repsnapper.conf||' \
		${WRKSRC}/Makefile
	@${REINPLACE_CMD} 's|DATADIRNAME = lib|DATADIRNAME = share|' \
		${WRKSRC}/po/Makefile

post-install:
	${MKDIR} ${PREFIX}/etc/xdg/repsnapper
	${INSTALL_DATA} ${WRKSRC}/src/repsnapper.conf \
		${PREFIX}/etc/xdg/repsnapper/repsnapper.conf.sample
	@if [ ! -f ${PREFIX}/etc/xdg/repsnapper/repsnapper.conf ]; then \
		${CP} -p ${PREFIX}/etc/xdg/repsnapper/repsnapper.conf.sample \
			${PREFIX}/etc/xdg/repsnapper/repsnapper.conf ; \
	fi

.include <bsd.port.mk>
