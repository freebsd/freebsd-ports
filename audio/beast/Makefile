# New ports collection makefile for:	BEAST
# Date created:			23 Jun 2004
# Whom:				Jean-Yves Lefort <jylefort@brutele.be>
#
# $FreeBSD$
#

PORTNAME=	beast
PORTVERSION=	0.7.2
CATEGORIES=	audio
MASTER_SITES=	http://beast.testbit.eu/_dist/beast/v${PORTVERSION:R}/

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	A powerful music composition and modular synthesis application

LIB_DEPENDS=	vorbisfile:${PORTSDIR}/audio/libvorbis \
		mad:${PORTSDIR}/audio/libmad \
		guile:${PORTSDIR}/lang/guile

USE_XORG=	x11
USE_GMAKE=	yes
USE_GNOME=	gnomehack intlhack libgnomecanvas
USE_BZIP2=	yes
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
USE_GETTEXT=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -DENODATA=255" \
		LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--disable-debug \
		--enable-osspcm=/dev/dsp \
		--enable-ossmidi=/dev/midi
MAKE_JOBS_UNSAFE=	yes

PLIST_SUB+=	PORTVERSION=${PORTVERSION}

MAN1=		beast.1 bsescm.1 bsewavetool.1 sfidl.1
MAN5=		bse.5

post-patch:
	@${REINPLACE_CMD} -Ee 's|$${libdir}/ladspa|${LOCALBASE}/lib/ladspa|; \
		/FLAGS=/ s/(-g|-ggdb3|-pipe|-O2|-ftracer|-finline-functions|-fno-keep-static-consts)//; \
		s|echo aout|echo elf|g' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|-DG_DISABLE_DEPRECATED||g' \
		${WRKSRC}/bse/Makefile.in \
		${WRKSRC}/bse/zintern/Makefile.in

.include <bsd.port.mk>
