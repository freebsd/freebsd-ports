# New ports collection makefile for:	BEAST
# Date created:			23 Jun 2004
# Whom:				Jean-Yves Lefort <jylefort@brutele.be>
#
# $FreeBSD$
#

PORTNAME=		beast
PORTVERSION=		0.6.4
PORTREVISION=	2
CATEGORIES=		audio
MASTER_SITES=		ftp://beast.gtk.org/pub/beast/v0.6/ \
			http://beast.gtk.org/beast-ftp/v0.6/

MAINTAINER=		jylefort@brutele.be
COMMENT=		A powerful music composition and modular synthesis application

LIB_DEPENDS=		vorbisfile:${PORTSDIR}/audio/libvorbis \
			mad:${PORTSDIR}/audio/libmad \
			guile:${PORTSDIR}/lang/guile

USE_X_PREFIX=		yes
USE_GMAKE=		yes
USE_GCC=		3.4
USE_REINPLACE=		yes
USE_GNOME=		gnomehack gnomeprefix intlhack libgnomecanvas
USE_INC_LIBTOOL_VER=	15
INSTALLS_SHLIB=		yes
CONFIGURE_ENV=		CPPFLAGS="-I${LOCALBASE}/include" \
			LDFLAGS="-L${LOCALBASE}/lib ${PTHREAD_LIBS}"
CONFIGURE_ARGS=		--disable-debug \
			--enable-osspcm=/dev/dsp \
			--enable-ossmidi=/dev/midi

MAN1=			beast.1 bsesh.1 sfidl.1
MAN3=			beast-gxk.3 bse-procs.3 bse-structs.3 bse.3 sfi.3

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
IGNORE=	does not compile on FreeBSD 4.x, missing library function isfinite
.endif

.if ${ARCH} == "sparc64"
BROKEN=		"Does not compile on sparc64"
.endif

post-patch:
	@${REINPLACE_CMD} -E \
		-e 's|(bseladspapath=)\$${libdir}/ladspa|\1"${LOCALBASE}/lib/ladspa"|' \
		-e 's/(FLAGS) (-g.*|-pipe|-O2|-f.*)"/\1"/g' \
		${WRKSRC}/${CONFIGURE_SCRIPT}
	@${REINPLACE_CMD} -e 's|-DG_DISABLE_DEPRECATED||g' \
		${WRKSRC}/bse/Makefile.in \
		${WRKSRC}/bse/zintern/Makefile.in

.include <bsd.port.post.mk>
