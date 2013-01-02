# Created by: Jean-Baptiste Quenot <jb.quenot@caraldi.com>
# $FreeBSD$

PORTNAME=	efax-gtk
PORTVERSION=	3.2.11
CATEGORIES=	comms
MASTER_SITES=	SF
EXTRACT_SUFX=	.src.tgz

MAINTAINER=	pawel@FreeBSD.org
COMMENT=	GUI front end for the efax fax program

LICENSE=	GPLv2

LIB_DEPENDS=	pthread-stubs:${PORTSDIR}/devel/libpthread-stubs \
		sigc-1.2.5:${PORTSDIR}/devel/libsigc++12 \
		pcre:${PORTSDIR}/devel/pcre \
		cairo:${PORTSDIR}/graphics/cairo \
		jbig:${PORTSDIR}/graphics/jbigkit \
		jpeg:${PORTSDIR}/graphics/jpeg \
		png15:${PORTSDIR}/graphics/png \
		tiff:${PORTSDIR}/graphics/tiff \
		freetype:${PORTSDIR}/print/freetype2 \
		expat:${PORTSDIR}/textproc/expat2 \
		fontconfig:${PORTSDIR}/x11-fonts/fontconfig \
		cxx-gtk-utils-2-2.0:${PORTSDIR}/x11-toolkits/c++-gtk-utils \
		xcb:${PORTSDIR}/x11/libxcb
RUN_DEPENDS=	ggv:${PORTSDIR}/print/ggv

USE_ICONV=	yes
USE_GHOSTSCRIPT_RUN=yes
USE_GNOME=	gdkpixbuf2 gtk20
GNU_CONFIGURE=	yes
USE_PKGCONFIG=	build
USE_GCC=	4.4+
USE_XORG=	pixman x11 xau xcomposite xcursor xdamage xdmcp xext xfixes \
		xi xinerama xrandr xrender
MAKE_JOBS_SAFE=	yes

CONFLICTS=	efax-[0-9]*

MAN1=		efax.1 efix.1 efax-gtk.1

CPPFLAGS+=	-I${LOCALBASE}/include ${PTHREAD_CFLAGS}
LDFLAGS+=	-L${LOCALBASE}/lib ${PTHREAD_LIBS} -lintl

CONFIGURE_ARGS+=--with-gtk-version=gtk2

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

post-install:
	@${ECHO}
	@${ECHO_CMD} "********************************************************************************"
	@${CAT} ${PKGMESSAGE}
	@${ECHO_CMD} "********************************************************************************"
	@${ECHO}

.include <bsd.port.mk>
