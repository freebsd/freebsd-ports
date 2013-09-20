# Created by: Martin Dieringer <martin.dieringe@gmx.de>
# $FreeBSD$

PORTNAME=	repsnapper
PORTVERSION=	2.2.0b3
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
LIB_DEPENDS=	libgtkglextmm-x11-1.2.so:${PORTSDIR}/x11-toolkits/gtkglextmm \
		libgtkmm-2.4.so:${PORTSDIR}/x11-toolkits/gtkmm24 \
		libglademm-2.4.so:${PORTSDIR}/devel/libglademm24 \
		libcairomm-1.0.so:${PORTSDIR}/graphics/cairomm \
		libzip.so:${PORTSDIR}/archivers/libzip \
		libatkmm-1.6.so:${PORTSDIR}/accessibility/atkmm \
		libglibmm-2.4.so:${PORTSDIR}/devel/glibmm \
		libpthread-stubs.so:${PORTSDIR}/devel/libpthread-stubs \
		libsigc-2.0.so:${PORTSDIR}/devel/libsigc++20 \
		libpcre.so:${PORTSDIR}/devel/pcre \
		libdrm.so:${PORTSDIR}/graphics/libdrm \
		libpng15.so:${PORTSDIR}/graphics/png \
		libfreetype.so:${PORTSDIR}/print/freetype2 \
		libexpat.so:${PORTSDIR}/textproc/expat2 \
		libxml++-2.6.so:${PORTSDIR}/textproc/libxml++26 \
		libfontconfig.so:${PORTSDIR}/x11-fonts/fontconfig \
		libpangomm-1.4.so:${PORTSDIR}/x11-toolkits/pangomm

USES=		gmake pkgconfig iconv
USE_GNOME=	gdkpixbuf2 gtk20 libxml2
USE_GL=		gl
USE_AUTOTOOLS=	automake libtool
USE_XORG=	ice pixman sm x11 xau xcb xcomposite xcursor xdamage xdmcp \
		xext xfixes xi xinerama xmu xrandr xrender xt xxf86vm

NO_STAGE=	yes
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
