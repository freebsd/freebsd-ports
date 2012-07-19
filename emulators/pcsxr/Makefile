# New ports collection makefile for:	pcsxr
# Date created:		11 June 2010
# Whom:			Ganael Laplanche <ganael.laplanche@martymac.org>
#
# $FreeBSD$
#

PORTNAME=	pcsxr
PORTVERSION=	1.9.92.r78288
PORTREVISION=	1
CATEGORIES=	emulators
MASTER_SITES=	http://contribs.martymac.org/FreeBSD-ports/distfiles/ \
		LOCAL/martymac
DISTFILES=	${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX}

MAINTAINER=	martymac@FreeBSD.org
COMMENT=	Playstation (PSX) emulator

LICENSE=	GPLv2

BUILD_DEPENDS=	gawk:${PORTSDIR}/lang/gawk
LIB_DEPENDS=	vorbis:${PORTSDIR}/audio/libvorbis \
		cdio:${PORTSDIR}/sysutils/libcdio

ONLY_FOR_ARCHS=	i386 amd64

USE_BZIP2=	yes
USE_AUTOTOOLS=	autoconf:env aclocal:env automake:env libtool
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
USE_CSTD=	gnu89
CONFIGURE_ARGS=	--enable-opengl --enable-libcdio
USE_LDCONFIG=	yes

USE_DOS2UNIX=	yes
DOS2UNIX_REGEX=	.*\.(c|h|cpp|hpp|am)

USE_GNOME=	gtk20 desktopfileutils glib20 libglade2
USE_ICONV=	yes
USE_XORG=	x11 xv xext xxf86vm xtst
USE_SDL=	sdl
USE_GL=	gl

MAN1=	pcsxr.1
PORTDOCS=	ChangeLog README

# Default CDROM device to use with dfcdrom,
# accessed through libcdio (using cam(4) and pass(4))
DEFAULT_DVD_DEVICE?=	/dev/cd0

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64"
CONFIGURE_ARGS+=	--enable-dynarec=x86_64
.endif

.if ${PORT_OPTIONS:MNLS}
USE_GETTEXT=	yes
CONFIGURE_ARGS+=	--enable-nls
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS="@comment "
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
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
.for doc in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${doc} ${DOCSDIR}
.endfor
.endif
	@-update-desktop-database

.include <bsd.port.post.mk>
