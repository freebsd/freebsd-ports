# Created by: Ganael Laplanche <ganael.laplanche@martymac.org>
# $FreeBSD$

PORTNAME=	pcsxr
PORTVERSION=	1.9.95.20180604
PORTREVISION=	2
CATEGORIES=	emulators

MAINTAINER=	martymac@FreeBSD.org
COMMENT=	Playstation (PSX) emulator

LICENSE=	GPLv3+

ONLY_FOR_ARCHS=	amd64 i386

LIB_DEPENDS=	libvorbis.so:audio/libvorbis \
		libcdio.so:sysutils/libcdio \
		libavformat.so:multimedia/ffmpeg

USES=		cmake desktop-file-utils dos2unix gettext gl gnome iconv \
		libarchive libtool pkgconfig sdl tar:bzip2 xorg

USE_GITHUB=	yes
GH_ACCOUNT=	martymac
GH_TAGNAME=	codeplex-final

USE_LDCONFIG=	yes

USE_GNOME=	cairo gdkpixbuf2 gtk30 intltool glib20
USE_XORG=	ice sm x11 xv xext xxf86vm xtst
USE_SDL=	sdl2
USE_GL=	gl
INSTALLS_ICONS=	yes

WRKSRC_SUBDIR=	${PORTNAME}

CMAKE_ARGS+=	-DDL_LIB:STRING="" \
		-DMANPREFIX:STRING="${MANPREFIX}" \
		-DBUILD_OPENGL:BOOL=ON \
		-DBUILD_SIO1:BOOL=ON \
		-DUSE_LIBCDIO:BOOL=ON \
		-DENABLE_CCDDA:BOOL=ON \
		-DUSE_LIBARCHIVE:BOOL=ON

DOS2UNIX_REGEX=	.*\.(c|h|cpp|hpp|am)

PORTDOCS=	ChangeLog README

# Default CDROM device to use with dfcdrom,
# accessed through libcdio (using cam(4) and pass(4))
DEFAULT_DVD_DEVICE?=	/dev/cd0

# XXX Gettext support is mandatory and cannot really be disabled.
# The following option only enables/disables building *additional* translations
OPTIONS_DEFINE=	NLS DOCS
OPTIONS_SUB=	yes
NLS_DESC=	Build additional NLS translations
NLS_CMAKE_ON=	-DDISABLE_NLS_TRANSLATIONS:BOOL=OFF
NLS_CMAKE_OFF=	-DDISABLE_NLS_TRANSLATIONS:BOOL=ON

.include <bsd.port.pre.mk>

post-patch:
	# Add ${PREFIX} to plugins' lookup directories
	@${REINPLACE_CMD} "s|%%PREFIX%%|${PREFIX}|" \
		${WRKSRC}/gui/LnxMain.c
	# Set default CDROM device
	@${REINPLACE_CMD} "s|%%DVD_DEVICE%%|${DEFAULT_DVD_DEVICE}|" \
		${WRKSRC}/plugins/dfcdrom/cdr.h
	# Fix PSEMU_DATA_DIR and DEF_PLUGIN_DIR
	@${REINPLACE_CMD} \
		-e "s|games/||g" \
		-e "s|psemu|${PORTNAME}|g" \
			${WRKSRC}/gui/CMakeLists.txt \
			${WRKSRC}/plugins/bladesio1/CMakeLists.txt \
			${WRKSRC}/plugins/dfcdrom/CMakeLists.txt \
			${WRKSRC}/plugins/dfinput/CMakeLists.txt \
			${WRKSRC}/plugins/dfnet/CMakeLists.txt \
			${WRKSRC}/plugins/dfsound/CMakeLists.txt \
			${WRKSRC}/plugins/dfxvideo/CMakeLists.txt \
			${WRKSRC}/plugins/nullsio1/CMakeLists.txt \
			${WRKSRC}/plugins/peopsxgl/CMakeLists.txt

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.post.mk>
