PORTNAME=	ladish
DISTVERSION=	1.2
PORTREVISION=	2
DISTVERSIONSUFFIX=	-g4dcd67d7
CATEGORIES=	audio
MASTER_SITES=	https://dl.ladish.org/ladish/

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Session management system for JACK
WWW=		https://ladish.org/

LICENSE=	GPLv3

LIB_DEPENDS=	libasound.so:audio/alsa-lib \
		libdbus-1.so:devel/dbus \
		libexpat.so:textproc/expat2 \
		libjack.so:audio/jack \
		libuuid.so:misc/libuuid

USES=		tar:bz2 localbase:ldflags pkgconfig python shebangfix waf
USE_PERL5=	configure

SHEBANG_FILES=	ladish_control
TESTING_UNSAFE=	No function 'test' defined in ${WRKSRC}/wscript

OPTIONS_DEFINE=		GUI
OPTIONS_DEFAULT=	GUI
OPTIONS_SUB=		yes

GUI_USES=		gettext gnome
GUI_USE=		GNOME=atkmm,cairo,gdkpixbuf,gtk20,gtkmm24,libgnomecanvas,pango,intltool:build
GUI_VARS=		CONFIGURE_ARGS=--enable-gladish
GUI_BUILD_DEPENDS=	${LOCALBASE}/include/boost/shared_ptr.hpp:devel/boost-libs
GUI_LIB_DEPENDS=	libdbus-glib-1.so:devel/dbus-glib \
			libfontconfig.so:x11-fonts/fontconfig \
			libfreetype.so:print/freetype2 \
			libgnomecanvasmm-2.6.so:graphics/libgnomecanvasmm26 \
			libharfbuzz.so:print/harfbuzz

post-install:
	# strip
	@cd ${STAGEDIR}${PREFIX} && \
		${STRIP_CMD} \
			bin/jmcore \
			bin/ladishd \
			bin/ladiconfd \
			lib/libalsapid.so
	# remove unnecessary files
	@${RM} -rf \
		${STAGEDIR}${DATADIR}/COPYING

post-install-GUI-on:
	#/usr/local/share/ladish/gladish.ui
	# strip
	@cd ${STAGEDIR}${PREFIX} && \
		${STRIP_CMD} \
			bin/gladish

.include <bsd.port.mk>
