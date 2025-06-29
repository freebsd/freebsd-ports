PORTNAME=	gsequencer
DISTVERSION=	7.5.5
PORTREVISION=	2
CATEGORIES=	audio

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Advanced Gtk+ sequencer
WWW=		https://nongnu.org/gsequencer/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	dssi>0:audio/dssi \
		gtkdocize:textproc/gtk-doc \
		lv2>0:audio/lv2
BUILD_DEPENDS+=	p5-File-Find-Rule>0:devel/p5-File-Find-Rule # only for bsd steps in custom configure
LIB_DEPENDS=	libfftw3.so:math/fftw3 \
		libgraphene-1.0.so:graphics/graphene \
		libharfbuzz.so:print/harfbuzz \
		libinstpatch-1.0.so:audio/libinstpatch \
		libjson-glib-1.0.so:devel/json-glib \
		libsamplerate.so:audio/libsamplerate \
		libsndfile.so:audio/libsndfile \
		libsoup-3.0.so:devel/libsoup3 \
		libuuid.so:misc/libuuid \
		libvulkan.so:graphics/vulkan-loader \
		libwebkit2gtk-4.0.so:www/webkit2-gtk@40
RUN_DEPENDS=	dssi>0:audio/dssi

USES=		autoreconf desktop-file-utils gettext-runtime gettext-tools gmake gnome gstreamer \
		libtool localbase:ldflags perl5 pkgconfig shared-mime-info
USE_GNOME=	cairo gdkpixbuf glib20 gtk40 libxml2 pango
USE_XORG=	x11
USE_CSTD=	gnu99
USE_LDCONFIG=	yes
USE_PERL5=	build # only for custom bsd steps in configure

USE_GITHUB=	yes

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share
CONFIGURE_ENV=	CFLAGS="${CFLAGS}" CXXFLAGS="${CXXFLAGS}" LDFLAGS="${LDFLAGS}" \
		INTROSPECTION_SCANNER=g-ir-scanner INTROSPECTION_COMPILER=g-ir-compiler MAKE=${GMAKE} CC=${CC} CXX=${CXX} LD=clang
CONFIGURE_ARGS=	--disable-alsa --enable-oss --enable-introspection --disable-rt

CPPFLAGS+=	-DAGS_LICENSE_FILENAME=\\\"${LOCALBASE}/share/licenses/${PKGNAME}/${LICENSE}\\\" \
		-DAGS_LOGO_FILENAME=\\\"${DATADIR}/images/ags.png\\\" # there should be no need to supply AGS_LOGO_FILENAME here since the app knows its location
LDFLAGS+=	-luuid

INSTALL_TARGET=	install-strip

PLIST_SUB=	PORTVERSION=${PORTVERSION}

OPTIONS_DEFINE=			DOCS JACK PULSEAUDIO X11
OPTIONS_DEFAULT=		X11

DOCS_CONFIGURE_ON=		HTMLHELP_XSL=${LOCALBASE}/share/xsl/docbook/htmlhelp/htmlhelp.xsl --docdir=${DOCSDIR} --enable-single-docdir
DOCS_BUILD_DEPENDS=		docbook-xsl>0:textproc/docbook-xsl
DOCS_USE=			GNOME=libxslt:build
DOCS_ALL_TARGET=		html
DOCS_INSTALL_TARGET=		install-html

JACK_CONFIGURE_ENABLE=		jack # the JACK option is probably broken, see https://github.com/gsequencer/gsequencer/issues/62
JACK_LIB_DEPENDS=		libjack.so:audio/jack

PULSEAUDIO_CONFIGURE_ENABLE=	pulse
PULSEAUDIO_LIB_DEPENDS=		libpulse.so:audio/pulseaudio

X11_CONFIGURE_ENABLE=		x11 # not sure what does X11 support realy mean, because it also shows the window wuth X11=OFF
X11_USES=			xorg

PORTDOCS=	*

post-extract:
	@${RM} ${WRKSRC}/configure.ac.orig

do-configure: # it fails to build with clang without this custom configure step
	@${ECHO} "==> Configure, patch symbols, and re-run configure again"
	@cd ${WRKSRC} && \
		${CONFIGURE_ENV} ${CONFIGURE_CMD} ${CONFIGURE_ARGS} && \
		${MAKE_CMD} gen-symbols-all-bsd && \
		${MAKE_CMD} fix-symbols-all-bsd && \
		${CONFIGURE_ENV} ${CONFIGURE_CMD} ${CONFIGURE_ARGS}

.include <bsd.port.mk>
