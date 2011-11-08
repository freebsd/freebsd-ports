# New ports collection makefile for:	darktable
# Date created:				11 March 2010
# Whom:					Alexey Dokuchaev <danfe@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	darktable
PORTVERSION=	0.9.3
CATEGORIES=	graphics
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTVERSION:R}

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	A virtual lighttable and darkroom for photographers

LICENSE=	GPLv3

LIB_DEPENDS=	exiv2.10:${PORTSDIR}/graphics/exiv2 \
		IlmImf.6:${PORTSDIR}/graphics/OpenEXR \
		lensfun.2:${PORTSDIR}/graphics/lensfun \
		lcms2.2:${PORTSDIR}/graphics/lcms2 \
		curl.6:${PORTSDIR}/ftp/curl

USE_CMAKE=	yes
CMAKE_OUTSOURCE=	yes
USE_GNOME=	librsvg2
USE_SQLITE=	yes
USE_LDCONFIG=	${PREFIX}/lib/${PORTNAME}
INSTALLS_ICONS=	yes
MAN1=		${PORTNAME}.1

OPTIONS=	GCONF	"Enable GConf backend"			off \
		GPHOTO	"Enable camera support via libgphoto2"	on \
		FLICKR	"Enable Flickr support via flickcurl"	off \
		RAWSPEED "Compile with rawspeed backend"	on \
		SLIDESHOW "Build OpenGL/SDL slideshow viewer"	off \
		KWALLET	"Enable KWallet support (requires dbus-glib)" off \
		GKEYRING "Enable GNOME Keyring support"		off \
		NLS	"Enable Native Language Support"	on

.include <bsd.port.pre.mk>

.if ${ARCH} == "sparc64"
BROKEN=		does not compile on sparc64: invokes i386 assembler
.endif

.if defined(WITH_GCONF)
USE_GNOME+=	gconf2
CMAKE_ARGS+=	-DDONT_INSTALL_GCONF_SCHEMAS:BOOL=ON	# bogus name, no typo
GCONF_SCHEMAS=	${PORTNAME}.schemas
.else
CMAKE_ARGS+=	-DUSE_GCONF_BACKEND:BOOL=OFF
PLIST_FILES+=	share/darktable/darktablerc
.endif

.if defined(WITH_GPHOTO)
LIB_DEPENDS+=	gphoto2.2:${PORTSDIR}/graphics/libgphoto2
PLIST_FILES+=	lib/darktable/plugins/lighttable/libcamera.so \
		lib/darktable/plugins/lighttable/libcapture.so \
		lib/darktable/views/libcapture.so
.else
CMAKE_ARGS+=	-DUSE_CAMERA_SUPPORT:BOOL=OFF
.endif

.if defined(WITH_FLICKR)
LIB_DEPENDS+=	flickcurl.0:${PORTSDIR}/www/flickcurl
PLIST_FILES+=	lib/darktable/plugins/imageio/storage/libflickr.so
.else
CMAKE_ARGS+=	-DUSE_FLICKR:BOOL=OFF
.endif

.if !defined(WITH_RAWSPEED)
CMAKE_ARGS+=	-DDONT_USE_RAWSPEED:BOOL=ON
.endif

.if defined(WITH_SLIDESHOW)
USE_GL=		gl
USE_SDL=	sdl
PLIST_FILES+=	bin/darktable-viewer
.else
CMAKE_ARGS+=	-DBUILD_SLIDESHOW:BOOL=OFF
.endif

.if defined(WITH_KWALLET)
LIB_DEPENDS+=	dbus-glib-1.2:${PORTSDIR}/devel/dbus-glib
.else
CMAKE_ARGS+=	-DUSE_KWALLET:BOOL=OFF
.endif

.if defined(WITH_GKEYRING)
LIB_DEPENDS+=	gnome-keyring.0:${PORTSDIR}/security/libgnome-keyring
.else
CMAKE_ARGS+=	-DUSE_GNOME_KEYRING:BOOL=OFF
.endif

.if defined(WITH_NLS)
USE_GETTEXT=	yes
.else
CMAKE_ARGS+=	-DUSE_NLS:BOOL=OFF
.endif

post-patch:
# Do not install useless (to end-user) documentation files
	@${REINPLACE_CMD} -e '/DOC_FILES/d' ${WRKSRC}/doc/CMakeLists.txt
# Respect CFLAGS for release builds; remove `-g' from common CFLAGS which
# are used for release builds as well
	@${REINPLACE_CMD} -e '/-O3/s,^,#, ; /-msse2/s, -g,,' \
		${WRKSRC}/src/CMakeLists.txt
# Fix GConf schemas installation prefix
	@${REINPLACE_CMD} -e 's,/etc/gconf/schemas,.&,' \
		${WRKSRC}/data/CMakeLists.txt
# Adjust manpages path
	@${REINPLACE_CMD} -e 's,share/man/man1,man/man1,' \
		${WRKSRC}/doc/CMakeLists.txt

post-install:
.if !defined(WITH_RAWSPEED)
	@${REINPLACE_CMD} -e '/rawspeed/d' ${TMPPLIST}
.endif
.if !defined(WITH_NLS)
	@${REINPLACE_CMD} -e '/LC_MESSAGES/d' ${TMPPLIST}
.endif

.include <bsd.port.post.mk>
