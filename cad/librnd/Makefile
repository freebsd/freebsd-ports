PORTNAME=	librnd
DISTVERSION=	4.4.0
CATEGORIES=	cad
MASTER_SITES=	http://www.repo.hu/projects/${PORTNAME}/releases/

MAINTAINER=	alven@FreeBSD.org
COMMENT=	Flexible, modular two-dimensional CAD engine
WWW=		http://www.repo.hu/projects/librnd/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libfungw.so:devel/fungw \
		libgenht.so:devel/genht

USES=		gmake pkgconfig tar:bz2
USE_LDCONFIG=	yes

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	${WITH_DEBUG:D--debug} \
		--all=plugin \
		--CC=${CC} \
		--CFLAGS='${CFLAGS}' \
		--LDFLAGS='${LDFLAGS}' \
		--plugin-hid_remote

TEST_TARGET=	test

BINARY_ALIAS=	make=${MAKE_CMD}

PLIST_SUB=	SOVERSION=${DISTVERSION}

OPTIONS_DEFINE=		DOCS GD GTK2 GTK2GL GTK4 MOTIF STROKE WGET
OPTIONS_DEFAULT=	GD GTK2 GTK2GL STROKE WGET
OPTIONS_SUB=		yes

GTK2GL_DESC=		GTK 2 GUI with OpenGL support
WGET_DESC=		Wget support

GD_LIB_DEPENDS=		libgd.so:graphics/gd
GD_CONFIGURE_OFF=	--disable-gd
GTK2GL_IMPLIES=		GTK2
GTK2GL_LIB_DEPENDS=	libgtkglext-x11-1.0.so:x11-toolkits/gtkglext
GTK2GL_USES=		gl
GTK2GL_USE=		GL=gl,glu \
			GNOME=pangox-compat \
			XORG=x11
GTK2GL_CONFIGURE_OFF=	--disable-hid_gtk2_gl
GTK2_LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
			libfreetype.so:print/freetype2 \
			libharfbuzz.so:print/harfbuzz
GTK2_USES=		gnome
GTK2_USE=		GNOME=cairo,gdkpixbuf,gtk20
GTK2_CONFIGURE_OFF=	--disable-hid_gtk2_gdk

GTK4_IMPLIES=		GTK2
GTK4_LIB_DEPENDS=	libepoxy.so:graphics/libepoxy \
			libgraphene-1.0.so:graphics/graphene \
			libharfbuzz.so:print/harfbuzz \
			libvulkan.so:graphics/vulkan-loader
GTK4_USES=		gl gnome
GTK4_USE=		GL=gl,glu \
			GNOME=cairo,gdkpixbuf,gtk40
GTK4_CONFIGURE_OFF=	--disable-hid_gtk4_gl
MOTIF_BROKEN=		Fails to build
MOTIF_USES=		motif
MOTIF_USE=		XORG=x11,xinerama,xrender,xt
MOTIF_CONFIGURE_OFF=	--disable-hid_lesstif
STROKE_LIB_DEPENDS=	libstroke.so:devel/libstroke
STROKE_CONFIGURE_OFF=	--disable-stroke
WGET_RUN_DEPENDS=	wget:ftp/wget
WGET_CONFIGURE_OFF=	--disable-lib_wget

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/*.so
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/librnd4/plugins/*.so
.for l in puplug sphash scconfig/cquote scconfig/sccbox
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/librnd4/${l}
.endfor

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MGTK2} || ${PORT_OPTIONS:MGTK4} || ${PORT_OPTIONS:MMOTIF}
PLIST_SUB+=	GUI=""
.else
PLIST_SUB+=	GUI="@comment "
.endif

pre-configure:
	${REINPLACE_CMD} -e 's,%%LOCALBASE%%,${LOCALBASE},' \
		-e 's,%%MOTIFLIB%%,${MOTIFLIB},' \
		${WRKSRC}/scconfig/src/gui/find_gl.c \
		${WRKSRC}/scconfig/src/gui/find_lesstif2.c \
		${WRKSRC}/scconfig/src/gui/find_misc.c \
		${WRKSRC}/scconfig/src/gui/find_x.c

.include <bsd.port.post.mk>
