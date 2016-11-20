# Created by: Daniel J. O'Connor <darius@dons.net.au>
# $FreeBSD$

PORTNAME=	quakeforge
PORTVERSION=	0.7.2
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	SF/quake/quake/${PORTVERSION}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}
DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Cleaned up copy of the GPL'ed Quake 1 source code

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libpng.so:graphics/png

USE_CSTD=	gnu89
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	Z_CFLAGS=" " Z_LIBS="-lz"
CONFIGURE_ARGS=	--disable-alsa \
		--disable-debug \
		--disable-optimize \
		--disable-static \
		--enable-xdg \
		--with-cpp="${CPP} %d %i %o" \
		--with-global-cfg=${PREFIX}/etc/quakeforge.conf \
		--with-ipv6 \
		--with-sharepath=${Q1DIR}
INSTALL_TARGET=	install-strip
USES=		bison compiler:c11 gmake libtool localbase tar:bzip2
USE_LDCONFIG=	yes

SUB_FILES=	pkg-message

OPTIONS_DEFINE=		CLIENTS DOCS FLAC JACK OPTIMIZED_CFLAGS SDL SERVERS \
			SKYBOXES VORBIS XMMS XXF86DGA XXF86VM
OPTIONS_DEFAULT=	CLIENTS SERVERS
OPTIONS_SUB=		yes

CLIENTS_DESC=		Clients
CLIENTS_BUILD_DEPENDS=	icotool:graphics/icoutils
CLIENTS_LIB_DEPENDS=	libsamplerate.so:audio/libsamplerate \
			libcurl.so:ftp/curl
CLIENTS_USES=		pkgconfig
CLIENTS_USE=		gl=glu xorg=xext
CLIENTS_CONFIGURE_OFF=	--with-clients=""
CLIENTS_VERS=		INSTALLS_ICONS=yes
FLAC_LIB_DEPENDS=	libFLAC.so:audio/flac
FLAC_CONFIGURE_ON=	--with-libFLAC=${LOCALBASE}
FLAC_CONFIGURE_OFF=	--disable-flac
FLAC_IMPLIES=		CLIENTS
JACK_LIB_DEPENDS=	libjack.so:audio/jack
JACK_CONFIGURE_OFF=	--disable-jack
JACK_IMPLIES=		CLIENTS
OPTIMIZED_CFLAGS_CFLAGS=\
			-O3 -funroll-loops -fomit-frame-pointer -fno-common \
			-fexpensive-optimizations -fstrict-aliasing -ffast-math
SDL_USE=		sdl=sdl
SDL_CONFIGURE_ON=	--with-sdl-prefix=${LOCALBASE}
SDL_CONFIGURE_OFF=	--disable-sdl
SDL_IMPLIES=		CLIENTS
SERVERS_DESC=		Dedicated servers
SERVERS_USES=		ncurses
SERVERS_CONFIGURE_OFF=	--with-servers=""
SKYBOXES_DESC=		Install skyboxes pak
SKYBOXES_MASTER_SITES=	http://www.quakeforge.net/files/:qf
SKYBOXES_DISTFILES=	skyboxes.pak:qf
VORBIS_LIB_DEPENDS=	libvorbis.so:audio/libvorbis
VORBIS_CONFIGURE_ON=	--with-ogg=${LOCALBASE} --with-vorbis=${LOCALBASE}
VORBIS_CONFIGURE_OFF=	--disable-vorbis
VORBIS_IMPLIES=		CLIENTS
XMMS_DESC=		Sound support via XMMS
XMMS_LIB_DEPENDS=	libxmms.so:multimedia/xmms
XMMS_CONFIGURE_ON=	--enable-xmms --with-xmms-prefix=${LOCALBASE}
XMMS_IMPLIES=		CLIENTS
XXF86DGA_DESC=		XFree86 DGA Extension support
XXF86DGA_USE=		xorg=xxf86dga
XXF86DGA_CONFIGURE_OFF=	--disable-dga
XXF86DGA_IMPLIES=	CLIENTS
XXF86VM_DESC=		XFree86 Vidmode Extension support
XXF86VM_USE=		xorg=xxf86vm
XXF86VM_CONFIGURE_OFF=	--disable-vidmode
XXF86VM_IMPLIES=	CLIENTS

post-patch:
	@${REINPLACE_CMD} -e \
		's|^Z_LIBS=""|| ; \
		 /if test/s|==|=| ; \
		 /for qf_t in/s|,qwaq,|,|' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e \
		'/^pkgdatadir/s|@libdir@|@prefix@/libdata|' \
		${WRKSRC}/pkg-config/Makefile.in

post-build-CLIENTS-on:
.for i in 16 32
	@${MKDIR} ${WRKDIR}/icons/hicolor/${i}x${i}/apps
	icotool -x -o ${WRKDIR}/icons/hicolor/${i}x${i}/apps/quake.png \
		-w ${i} -b 8 ${WRKSRC}/doc/qf.ico
.endfor

post-install:
	${INSTALL_MAN} ${WRKSRC}/doc/man/quakeforge.1 ${STAGEDIR}${MANPREFIX}/man/man1

post-install-CLIENTS-on:
	@(cd ${WRKDIR} && ${COPYTREE_SHARE} icons \
		${STAGEDIR}${PREFIX}/share)

post-install-DOCS-on:
	@(cd ${WRKSRC}/doc && ${COPYTREE_SHARE} "config gib" \
		${STAGEDIR}${DOCSDIR})

post-install-SKYBOXES-on:
	@${MKDIR} ${STAGEDIR}${Q1DIR}/QF
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/skyboxes.pak \
		${STAGEDIR}${DATADIR}/QF

.include "${.CURDIR}/../quake-data/Makefile.include"
.include <bsd.port.mk>
