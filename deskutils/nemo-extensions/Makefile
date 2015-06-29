# Created by: Gustau Perez i Querol <gustau.perez@gmail.com>
# $FreeBSD$

PORTNAME=	nemo-extensions
PORTVERSION=	2.4.0
PORTREVISION=	2
CATEGORIES=	deskutils gnome
DIST_SUBDIR=	gnome3

MAINTAINER=	gustau.perez@gmail.com
COMMENT=	File manager extensions for the Cinnamon desktop

BUILD_DEPENDS=	gnome-icon-theme>=0:${PORTSDIR}/misc/gnome-icon-theme \
		gtkdocize:${PORTSDIR}/textproc/gtk-doc \
		rst2html:${PORTSDIR}/textproc/py-docutils \
		automake>=0:${PORTSDIR}/devel/automake \
		autoconf>=0:${PORTSDIR}/devel/autoconf \
		libtool:${PORTSDIR}/devel/libtool \
		gnome-autogen.sh:${PORTSDIR}/devel/gnome-common \
		${LOCALBASE}/libdata/pkgconfig/gsettings-desktop-schemas.pc:${PORTSDIR}/devel/gsettings-desktop-schemas
LIB_DEPENDS=	libexif.so:${PORTSDIR}/graphics/libexif \
		libcinnamon-desktop.so:${PORTSDIR}/x11/cinnamon-desktop \
		libnemo-extension.so:${PORTSDIR}/x11-fm/nemo \
		libnotify.so:${PORTSDIR}/devel/libnotify \
		libexempi.so:${PORTSDIR}/textproc/exempi \
		libcjs.so:${PORTSDIR}/lang/cjs \
		libclutter-1.0.so:${PORTSDIR}/graphics/clutter \
		libevdocument3.so:${PORTSDIR}/graphics/evince \
		libclutter-gtk-1.0.so:${PORTSDIR}/graphics/clutter-gtk3 \
		libclutter-gst-2.0.so:${PORTSDIR}/multimedia/clutter-gst \
		libmusicbrainz5.so:${PORTSDIR}/audio/libmusicbrainz5 \
		libwebkitgtk-3.0.so:${PORTSDIR}/www/webkit-gtk3
RUN_DEPENDS=	gnome-icon-theme>=0:${PORTSDIR}/misc/gnome-icon-theme \
		gsettings-desktop-schemas>=0:${PORTSDIR}/devel/gsettings-desktop-schemas

BROKEN_FreeBSD_9=	does not build

USE_GITHUB=	yes
GH_ACCOUNT=	linuxmint
GH_TAGNAME=	6c8ec3a

USE_GNOME=	gconf2 gnomeprefix gnomedocutils gtksourceview3 intlhack \
		introspection:build libxml2 pygtk2
USES=		gettext gmake libtool pathfix pkgconfig shebangfix
SHEBANG_FILES=  nemo-dropbox/dropbox.in
INSTALLS_ICONS=	yes
USE_LDCONFIG=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
INSTALL_TARGET=	install-strip

NON_AUTO_EXTENSIONS=	nemo-dropbox nemo-fileroller nemo-preview
AUTO_EXTENSIONS=	nemo-share

post-patch:
	@${REINPLACE_CMD} -e 's|AM_GNU_GETTEXT_VERSION(\[0.17\])||g ;\
		s|AM_GNU_GETTEXT(\[external\])||g' \
		${WRKSRC}/nemo-preview/configure.ac

do-configure:
.for i in ${NON_AUTO_EXTENSIONS}
	cd ${WRKSRC}/${i} && NOCONFIGURE=yes ${SH} autogen.sh && ./configure --prefix=${PREFIX} \
		--with-nemo-extension-dir=${PREFIX}/lib/nemo/extensions-3.0 \
		--mandir=${PREFIX}/man
.endfor

.for i in ${AUTO_EXTENSIONS}
	cd ${WRKSRC}/${i} && ./configure --prefix=${PREFIX} \
		--with-nemo-extension-dir=${PREFIX}/lib/nemo/extensions-3.0 \
		--mandir=${PREFIX}/man
.endfor

do-build:
.for i in ${NON_AUTO_EXTENSIONS} ${AUTO_EXTENSIONS}
	cd ${WRKSRC}/${i} && ${MAKE_ENV} ${MAKE_CMD} ${MAKE_FLAGS} ${MAKEFILE} ${_MAKE_JOBS} ${MAKE_ARGS} ${ALL_TARGET}
.endfor

do-install:
.for i in ${NON_AUTO_EXTENSIONS} ${AUTO_EXTENSIONS}
	cd ${WRKSRC}/${i} && ${MAKE_ENV} ${MAKE_CMD} ${MAKE_FLAGS} ${MAKEFILE} ${_MAKE_JOBS} ${MAKE_ARGS} ${INSTALL_TARGET}
.endfor

.include <bsd.port.mk>
