# Created by: FreeBSD GNOME Team <gnome@freebsd.org>
# $FreeBSD$
#   $MCom: ports/trunk/devel/appstream-glib/Makefile 20031 2014-11-02 21:47:55Z kwm $

PORTNAME=	appstream-glib
PORTVERSION=	0.2.6
PORTREVISION=	1
CATEGORIES=	devel
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Library to help with AppStream metadata

BUILD_DEPENDS=	gtkdoc-check:${PORTSDIR}/textproc/gtk-doc
LIB_DEPENDS=	libsoup-2.4.so:${PORTSDIR}/devel/libsoup

GH_ACCOUNT=	hughsie
GH_TAGNAME=	f4f3230

USES=		autoreconf:build gettext gmake libtool pathfix pkgconfig
USE_GNOME=	gdkpixbuf2 glib20 gtk30
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
USE_GITHUB=	yes
PATHFIX_MAKEFILEIN=	Makefile.am
INSTALL_TARGET=	install-strip

.include <bsd.port.options.mk>

.if ${OSVERSION} < 1000000
LIB_DEPENDS+=	libarchive.so.13:${PORTSDIR}/archivers/libarchive
.else
CONFIGURE_ENV+=	LIBARCHIVE_CFLAGS=" " \
		LIBARCHIVE_LIBS="-larchive"
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|-Wtype-limits||g' \
		${WRKSRC}/configure.ac

pre-configure:
	(cd ${WRKSRC} && ${SETENV} NOCONFIGURE=yes ${SH} ./autogen.sh)
	${REINPLACE_CMD} 's/DATADIRNAME=lib/DATADIRNAME=share/' \
		${WRKSRC}/configure

.include <bsd.port.mk>
