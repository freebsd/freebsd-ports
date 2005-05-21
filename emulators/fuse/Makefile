# New ports collection makefile for:	fuse
# Date created:			2003-10-28
# Whom:				Alexey V. Antipovsky <kemm@in-line.ru>
#
# $FreeBSD$
#

PORTNAME=	fuse
PORTVERSION=	0.7.0
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	fuse-emulator

MAINTAINER=	kemm@in-line.ru
COMMENT=	Free Unix (Sinclair ZX-)Spectrum Emulator

LIB_DEPENDS=	spectrum.4:${PORTSDIR}/emulators/libspectrum \
		765.4:${PORTSDIR}/emulators/lib765 \
		xml2.5:${PORTSDIR}/textproc/libxml2 \
		png.5:${PORTSDIR}/graphics/png

WANT_GNOME=		yes
WANT_SDL=		yes
USE_XLIB=		yes
USE_PERL5_BUILD=	yes
USE_GETOPT_LONG=	yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS=		--with-plus3-disk-prefix=${LOCALBASE}

OPTIONS=	SMALLMEM "Low memory compile needed" off \
		GTK      "Use GTK1 user interface" off \
		GTK2	 "Use GTK2 user interface" on \
		SDL	 "Use SDL user interface" on \
		SVGALIB  "Use SVGAlib user interface" off \
		GCRYPT	 "Support digital signing of .RZX files" off

.include <bsd.port.pre.mk>

.if defined(WITH_SMALLMEM)
CONFIGURE_ARGS+=	--enable-smallmem
.endif

.if !defined(WITHOUT_GTK)
USE_GNOME=		gtk12
.else
CONFIGURE_ARGS+=	--without-gtk
.endif

.if defined(WITH_GTK2)
CONFIGURE_ARGS+=	--with-gtk2
USE_GNOME+=		gtk20
.endif

.if defined(WITH_SDL)
CONFIGURE_ARGS+=	--with-sdl
USE_SDL=		yes
.endif

.if defined(WITH_SVGALIB)
CONFIGURE_ARGS+=	--with-svgalib
LIB_DEPENDS+=		vga.1:${PORTSDIR}/graphics/svgalib
.endif

.if defined(WITH_GCRYPT) || exists(${LOCALBASE}/include/gcrypt.h)
CONFIGURE_ENV+=	LDFLAGS="-L${LOCALBASE}/lib"
LIB_DEPENDS+=	gcrypt.13:${PORTSDIR}/security/libgcrypt
.endif

MAN1=	fuse.1

.if !defined(NOPORTDOCS)
post-install:
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} AUTHORS ChangeLog README THANKS \
		${DOCSDIR}
.endif

.include <bsd.port.post.mk>
