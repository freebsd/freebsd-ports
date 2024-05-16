PORTNAME=	gsequencer
DISTVERSION=	6.12.5
CATEGORIES=	audio

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Advanced Gtk+ sequencer
WWW=		https://nongnu.org/gsequencer/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	dssi>0:audio/dssi \
		gtkdocize:textproc/gtk-doc \
		lv2>0:audio/lv2
LIB_DEPENDS=	libasound.so:audio/alsa-lib \
		libfftw3.so:math/fftw3 \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libgraphene-1.0.so:graphics/graphene \
		libharfbuzz.so:print/harfbuzz \
		libinstpatch-1.0.so:audio/libinstpatch \
		libjson-glib-1.0.so:devel/json-glib \
		libsamplerate.so:audio/libsamplerate \
		libsndfile.so:audio/libsndfile \
		libsoup-3.0.so:devel/libsoup3 \
		libuuid.so:misc/e2fsprogs-libuuid \
		libvulkan.so:graphics/vulkan-loader \
		libwebkit2gtk-4.0.so:www/webkit2-gtk3
RUN_DEPENDS=	dssi>0:audio/dssi

USES=		autoreconf desktop-file-utils gettext-runtime gettext-tools gmake gnome gstreamer libtool localbase pkgconfig shared-mime-info xorg
USE_GNOME=	atk cairo gdkpixbuf2 glib20 gtk40 libxml2 pango
USE_XORG=	x11
USE_GCC=	yes # the project uses gnu99 extensions, clang fails even with USE_CSTD=gnu99. Suggestions how to build with clang are welcome.
USE_CSTD=	gnu99
USE_LDCONFIG=	yes

USE_GITHUB=	yes

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share
CONFIGURE_ARGS=	--disable-alsa --enable-oss --disable-introspection --disable-rt

CPPFLAGS+=	-DAGS_LICENSE_FILENAME=\\\"${LOCALBASE}/share/licenses/${PKGNAME}/${LICENSE}\\\" \
		-DAGS_LOGO_FILENAME=\\\"${DATADIR}/images/ags.png\\\" # there should be no need to supply AGS_LOGO_FILENAME here since the app knows its location
LDFLAGS+=	-luuid

INSTALL_TARGET=	install-strip

PLIST_SUB=	PORTVERSION=${PORTVERSION}

OPTIONS_DEFINE=			DOCS JACK PULSEAUDIO

DOCS_CONFIGURE_ON=		HTMLHELP_XSL=${LOCALBASE}/share/xsl/docbook/htmlhelp/htmlhelp.xsl --docdir=${DOCSDIR} --enable-single-docdir
DOCS_BUILD_DEPENDS=		docbook-xsl>0:textproc/docbook-xsl
DOCS_USE=			GNOME=libxslt:build
DOCS_ALL_TARGET=		html
DOCS_INSTALL_TARGET=		install-html

JACK_CONFIGURE_ENABLE=		jack # the JACK option is probably broken, see https://github.com/gsequencer/gsequencer/issues/62
JACK_LIB_DEPENDS=		libjack.so:audio/jack

PULSEAUDIO_CONFIGURE_ENABLE=	pulse
PULSEAUDIO_LIB_DEPENDS=		libpulse.so:audio/pulseaudio

PORTDOCS=	*

post-extract:
	${RM} ${WRKSRC}/configure.ac.orig

.include <bsd.port.mk>
