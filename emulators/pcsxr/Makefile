# Created by: Ganael Laplanche <ganael.laplanche@martymac.org>
# $FreeBSD$

PORTNAME=	pcsxr
PORTVERSION=	1.9.94.r87113
PORTREVISION=	1
CATEGORIES=	emulators
MASTER_SITES=	http://contribs.martymac.org/FreeBSD-ports/distfiles/ \
		LOCAL/martymac

MAINTAINER=	martymac@FreeBSD.org
COMMENT=	Playstation (PSX) emulator

LICENSE=	GPLv2

BUILD_DEPENDS=	gawk:${PORTSDIR}/lang/gawk
LIB_DEPENDS=	libvorbis.so:${PORTSDIR}/audio/libvorbis \
		libcdio.so:${PORTSDIR}/sysutils/libcdio

ONLY_FOR_ARCHS=	i386 amd64

USE_BZIP2=	yes
USE_AUTOTOOLS=	autoconf:env aclocal:env automake:env libtool
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
USE_CSTD=	gnu89
CONFIGURE_ARGS=	--enable-opengl --enable-libcdio
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes

USE_DOS2UNIX=	yes
DOS2UNIX_REGEX=	.*\.(c|h|cpp|hpp|am)

USE_GNOME=	gtk30 glib20
USES=		iconv gmake pkgconfig desktop-file-utils
USE_XORG=	x11 xv xext xxf86vm xtst
USE_SDL=	sdl
USE_GL=	gl

PORTDOCS=	ChangeLog README

# Default CDROM device to use with dfcdrom,
# accessed through libcdio (using cam(4) and pass(4))
DEFAULT_DVD_DEVICE?=	/dev/cd0

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes
NLS_USES=	gettext
NLS_CONFIGURE_ENABLE=	nls

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64"
CONFIGURE_ARGS+=	--enable-dynarec=x86_64
.endif

# Add ${PREFIX} to plugins' lookup directories and set default CDROM device
post-patch:
	@${REINPLACE_CMD} "s|%%PREFIX%%|${PREFIX}|" \
		${WRKSRC}/gui/LnxMain.c
	@${REINPLACE_CMD} "s|%%DVD_DEVICE%%|${DEFAULT_DVD_DEVICE}|" \
		${WRKSRC}/plugins/dfcdrom/cdr.h

pre-configure:
	@(cd ${WRKSRC} && ${AUTORECONF} -fi)

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.post.mk>
