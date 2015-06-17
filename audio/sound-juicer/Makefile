# Created by: Alexander Nedotsukov <bland@FreeBSD.org>
# $FreeBSD$

PORTNAME=	sound-juicer
PORTVERSION=	3.14.0
PORTREVISION=	1
CATEGORIES=	audio gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Clean, mean, and lean CD ripper for GNOME

BUILD_DEPENDS=	itstool:${PORTSDIR}/textproc/itstool
LIB_DEPENDS=	libmusicbrainz5.so:${PORTSDIR}/audio/libmusicbrainz5 \
		libdiscid.so:${PORTSDIR}/audio/libdiscid \
		libtag.so:${PORTSDIR}/audio/taglib \
		libcanberra.so:${PORTSDIR}/audio/libcanberra \
		libdbus-glib-1.so:${PORTSDIR}/devel/dbus-glib \
		libbrasero-media3.so:${PORTSDIR}/sysutils/brasero

USES=		desktop-file-utils gettext gmake pathfix pkgconfig tar:xz
USE_GNOME=	gnomeprefix intlhack
USE_GSTREAMER1=	cdparanoia flac good vorbis
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-ignore-missing-cd
INSTALLS_ICONS=	yes
CFLAGS+=	-I${LOCALBASE}/include -Wno-error=format-nonliteral
LDFLAGS+=	-L${LOCALBASE}/lib
MAKE_ENV=	XDG_CACHE_HOME=${WRKDIR}
INSTALL_TARGET=	install-strip

GLIB_SCHEMAS=	org.gnome.sound-juicer.gschema.xml

post-patch:
	@${REINPLACE_CMD} -e 's|^\(SUBDIRS = .*\)tests\(.*\)|\1\2|' \
		${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e 's|" == "|" = "|g' ${WRKSRC}/configure

.include <bsd.port.mk>
