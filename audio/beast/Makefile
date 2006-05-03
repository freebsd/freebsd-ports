# New ports collection makefile for:	BEAST
# Date created:			23 Jun 2004
# Whom:				Jean-Yves Lefort <jylefort@brutele.be>
#
# $FreeBSD$
#

PORTNAME=	beast
PORTVERSION=	0.6.6
PORTREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	ftp://beast.gtk.org/pub/beast/v0.6/ \
		http://beast.gtk.org/beast-ftp/v0.6/

MAINTAINER=	jylefort@FreeBSD.org
COMMENT=	A powerful music composition and modular synthesis application

LIB_DEPENDS=	vorbisfile:${PORTSDIR}/audio/libvorbis \
		mad:${PORTSDIR}/audio/libmad \
		guile:${PORTSDIR}/lang/guile

USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomehack gnomeprefix intlhack libgnomecanvas
GNU_CONFIGURE=  yes
INSTALLS_SHLIB=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -DENODATA=255" \
		LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--disable-debug \
		--enable-osspcm=/dev/dsp \
		--enable-ossmidi=/dev/midi

MAN1=		beast.1 bsesh.1 sfidl.1
MAN3=		beast-gxk.3 bse-procs.3 bse-structs.3 bse.3 sfi.3

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
IGNORE=	does not compile on FreeBSD 4.x, missing library function isfinite
.endif

post-patch:
	@${REINPLACE_CMD} -Ee 's|$${libdir}/ladspa|${LOCALBASE}/lib/ladspa|; \
		/FLAGS=/ s/(-g|-ggdb3|-pipe|-O2|-ftracer|-finline-functions|-fno-keep-static-consts)//' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|-DG_DISABLE_DEPRECATED||g' \
		${WRKSRC}/bse/Makefile.in \
		${WRKSRC}/bse/zintern/Makefile.in

.include <bsd.port.post.mk>
