# Created by: TAKAHASHI Kaoru <kaoru@kaisei.org>
# $FreeBSD$

PORTNAME=	gnubg
PORTVERSION=	1.03.001
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	http://www.c-s.li/ports/ \
		http://files.gnubg.org/media/sources/
DISTFILES=	gnubg-release-${PORTVERSION}-sources.tar.gz

MAINTAINER=	cs@FreeBSD.org
COMMENT=	GNU Backgammon

LICENSE=	GPLv3

BUILD_DEPENDS=	bison:${PORTSDIR}/devel/bison
RUN_DEPENDS=	sqlite3:${PORTSDIR}/databases/sqlite3
LIB_DEPENDS=	libpng15.so:${PORTSDIR}/graphics/png \
		libgtkglext-x11-1.0.so:${PORTSDIR}/x11-toolkits/gtkglext \
		libcanberra-gtk.so:${PORTSDIR}/audio/libcanberra

CONFIGURE_ARGS=	--with-board3d --with-sqlite --with-python=${LOCALBASE}/bin/python
CONFIGURE_ENV=	ac_cv_path_ARTSC_CONFIG=no ac_cv_path_LIBART_CONFIG=no
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
INSTALL_TARGET=	install-strip
USES=		gmake libtool pathfix shebangfix python pkgconfig
USE_AUTOTOOLS=	aclocal automake libtoolize
USE_GNOME=	glib20

OPTIONS_DEFINE=	NLS DOCS
OPTIONS_DEFAULT=NLS

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
PLIST_SUB+=	NLS=""
.else
PLIST_SUB+=	NLS="@comment "
CONFIGURE_ARGS+=	--disable-nls
.endif

#pre-configure:
#	cd ${WRKSRC} && ./autogen.sh

.include <bsd.port.mk>
