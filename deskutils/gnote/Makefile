# Created by: Gustau Perez i Querol <gustau.perez@gmail.com>
# $FreeBSD$
#   $MCom: ports/trunk/deskutils/gnote/Makefile 19593 2014-04-28 11:41:58Z gusi $

PORTNAME=	gnote
PORTVERSION=	3.12.0
PORTREVISION=	1
CATEGORIES=	deskutils gnome
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	C++ version of Tomboy, note taking application

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	itstool:${PORTSDIR}/textproc/itstool
LIB_DEPENDS=	libpcre.so:${PORTSDIR}/devel/pcre \
		libgtkspell3-3.so:${PORTSDIR}/textproc/gtkspell3 \
		libboost_filesystem.so:${PORTSDIR}/devel/boost-libs \
		libsecret-1.so:${PORTSDIR}/security/libsecret \
		libuuid.so:${PORTSDIR}/misc/e2fsprogs-libuuid

USE_GNOME=	gnomeprefix gtk30 gtkmm30 intltool \
		libxml2 libxslt
USES=		desktop-file-utils gettext gmake libtool:keepla \
		pathfix pkgconfig tar:xz
GLIB_SCHEMAS=	org.gnome.gnote.gschema.xml
INSTALLS_ICONS=	yes
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS=	--with-dbus-service-dir=${PREFIX}/share/dbus-1/services
DOCS=		AUTHORS ChangeLog NEWS README TODO

.include <bsd.port.options.mk>

PLIST_SUB+=	VERSION=${PORTVERSION}

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in ${DOCS}
	@${INSTALL_DATA} ${WRKSRC}/${i} ${STAGEDIR}${DOCSDIR}
.endfor
.endif
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libgnote-3.12.so.0.0.0
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/gnote/addins/${PORTVERSION}/*.so

.include <bsd.port.mk>
