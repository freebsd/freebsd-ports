# New ports collection makefile for:	fuse
# Date created:			2003-10-28
# Whom:				Alexey V. Antipovsky <kemm@in-line.ru>
#
# $FreeBSD$
#

PORTNAME=	fuse
PORTVERSION=	0.6.1.1
PORTREVISION=	1
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	fuse-emulator

MAINTAINER=	kemm@in-line.ru
COMMENT=	Free Unix (Sinclair ZX-)Spectrum Emulator

LIB_DEPENDS=	spectrum.2:${PORTSDIR}/emulators/libspectrum \
		765.3:${PORTSDIR}/emulators/lib765 \
		xml2.5:${PORTSDIR}/textproc/libxml2 \
		png.5:${PORTSDIR}/graphics/png

USE_XLIB=		yes
USE_PERL5_BUILD=	yes
USE_GETOPT_LONG=	yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS=		--with-plus3-disk-prefix=${LOCALBASE}

.if defined(WITH_SMALLMEM)
CONFIGURE_ARGS+=	--enable-smallmem
.endif

.if !defined(WITHOUT_GTK)
USE_GNOME=		gtk12
.else
CONFIGURE_ARGS+=	--without-gtk
.endif

.if defined(WITH_SDL)
CONFIGURE_ARGS+=	--with-sdl
USE_SDL=		yes
.endif

.if defined(WITH_SVGALIB)
CONFIGURE_ARGS+=	--with-svgalib
LIB_DEPENDS+=		vga.1:${PORTSDIR}/graphics/svgalib
.endif

.if defined(WITH_GGI)
CONFIGURE_ARGS+=	--with-ggi
LIB_DEPENDS+=		ggi.2:${PORTSDIR}/graphics/libggi
.endif

.if defined(WITH_GTK2)
CONFIGURE_ARGS+=	--with-gtk2
USE_GNOME+=		gtk20
.endif

.if defined(WITH_GCRYPT) || exists(${LOCALBASE}/include/gcrypt.h)
CONFIGURE_ENV+=	LDFLAGS="-L${LOCALBASE}/lib"
LIB_DEPENDS+=	gcrypt.6:${PORTSDIR}/security/libgcrypt
.endif

MAN1=	fuse.1
DOCS=	AUTHORS ChangeLog README THANKS

pre-everything::
	@${ECHO_MSG} ${CONFIGURE_ARGS}
	@${ECHO_MSG} ""
	@${ECHO_MSG} "You may use the following build options:"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "  WITH_SMALLMEM=yes     low memory compile needed"
	@${ECHO_MSG} "  WITHOUT_GTK=yes       don't use GTK1 user interface"
	@${ECHO_MSG} "  WITH_SDL=yes          use SDL user interface"
	@${ECHO_MSG} "  WITH_SVGALIB=yes      use SVGAlib user interface"
	@${ECHO_MSG} "  WITH_GGI=yes          use GGI user interface"
	@${ECHO_MSG} "  WITH_GTK2=yes         use GTK2 user interface"
	@${ECHO_MSG} "  WITH_GCRYPT=yes       support digital signing of .RZX files"
	@${ECHO_MSG} ""

.if !defined(NOPORTDOCS)
post-install:
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
