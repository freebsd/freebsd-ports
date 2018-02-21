# Created by: Gustau Perez i Querol <gustau.perez@gmail.com>
# $FreeBSD$

PORTNAME=	nemo-extensions
PORTVERSION=	2.4.0
PORTREVISION=	3
CATEGORIES=	deskutils gnome
DIST_SUBDIR=	gnome3

MAINTAINER=	gustau.perez@gmail.com
COMMENT=	File manager extensions for the Cinnamon desktop

BUILD_DEPENDS=	gnome-icon-theme>=0:misc/gnome-icon-theme \
		gtkdocize:textproc/gtk-doc \
		rst2html:textproc/py-docutils \
		gnome-autogen.sh:devel/gnome-common \
		${LOCALBASE}/libdata/pkgconfig/gsettings-desktop-schemas.pc:devel/gsettings-desktop-schemas
LIB_DEPENDS=	libexif.so:graphics/libexif \
		libcinnamon-desktop.so:x11/cinnamon-desktop \
		libnemo-extension.so:x11-fm/nemo \
		libnotify.so:devel/libnotify \
		libexempi.so:textproc/exempi \
		libcjs.so:lang/cjs \
		libclutter-1.0.so:graphics/clutter \
		libevdocument3.so:graphics/evince \
		libclutter-gtk-1.0.so:graphics/clutter-gtk3 \
		libclutter-gst-2.0.so:multimedia/clutter-gst \
		libmusicbrainz5.so:audio/libmusicbrainz5
RUN_DEPENDS=	gnome-icon-theme>=0:misc/gnome-icon-theme \
		gsettings-desktop-schemas>=0:devel/gsettings-desktop-schemas

USE_GITHUB=	yes
GH_ACCOUNT=	linuxmint
GH_TAGNAME=	6c8ec3a

USE_GNOME=	gconf2 gnomeprefix gnomedocutils gtksourceview3 intlhack \
		introspection:build libxml2 pygtk2
USES=		autoreconf:build gettext gmake libtool pathfix pkgconfig \
		python shebangfix
SHEBANG_FILES=	nemo-dropbox/dropbox.in
INSTALLS_ICONS=	yes
USE_LDCONFIG=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
INSTALL_TARGET=	install-strip
BINARY_ALIAS=	python=${PYTHON_CMD}

NON_AUTO_EXTENSIONS=	nemo-dropbox nemo-fileroller nemo-preview
AUTO_EXTENSIONS=	nemo-share

post-patch:
	@${REINPLACE_CMD} -e 's|AM_GNU_GETTEXT_VERSION(\[0.17\])||g ;\
		s|AM_GNU_GETTEXT(\[external\])||g' \
		${WRKSRC}/nemo-preview/configure.ac
	@${REINPLACE_CMD} -e 's|webkitgtk-3.0||' \
		${WRKSRC}/nemo-preview/configure.ac

do-configure:
.for i in ${NON_AUTO_EXTENSIONS}
	cd ${WRKSRC}/${i} && NOCONFIGURE=yes ${SH} autogen.sh && ${SETENV} ${CONFIGURE_ENV} ./configure --prefix=${PREFIX} \
		--with-nemo-extension-dir=${PREFIX}/lib/nemo/extensions-3.0 \
		--mandir=${PREFIX}/man
.endfor

.for i in ${AUTO_EXTENSIONS}
	cd ${WRKSRC}/${i} && ${SETENV} ${CONFIGURE_ENV} ./configure --prefix=${PREFIX} \
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
