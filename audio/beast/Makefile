# New ports collection makefile for:	BEAST
# Date created:			23 Jun 2004
# Whom:				Jean-Yves Lefort <jylefort@brutele.be>
#
# $FreeBSD$
#

PORTNAME=	beast
PORTVERSION=	0.7.4
PORTREVISION=	3
CATEGORIES=	audio
MASTER_SITES=	http://dist.testbit.eu/beast/v${PORTVERSION:R}/

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	A powerful music composition and modular synthesis application

LIB_DEPENDS=	vorbisfile:${PORTSDIR}/audio/libvorbis \
		mad:${PORTSDIR}/audio/libmad \
		guile:${PORTSDIR}/lang/guile \
		asound.2:${PORTSDIR}/audio/alsa-lib

USE_XORG=	x11
USE_GMAKE=	yes
USE_GNOME=	gnomehack intlhack libgnomecanvas
USE_BZIP2=	yes
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
USE_GETTEXT=	yes
CPPFLAGS+=	-I${LOCALBASE}/include -L${LOCALBASE}/lib -DENODATA=255
CONFIGURE_ARGS=	--disable-debug \
		--enable-osspcm=/dev/dsp \
		--enable-ossmidi=/dev/midi
MAKE_JOBS_UNSAFE=	yes

.include <bsd.port.pre.mk>

.if ${ARCH} == "powerpc"
BROKEN=		Does not compile on powerpc: array bound is not an integer constant
.endif

HAS_SSE!=	${SYSCTL} -n hw.instruction_sse 2> /dev/null
.if ${HAS_SSE} == 1
PLIST_SUB+=	SSE=""
.else
PLIST_SUB+=	SSE="@comment "
.endif

PLIST_SUB+=	PORTVERSION=${PORTVERSION}

MAN1=		beast.1 bsescm.1 bsewavetool.1 sfidl.1
MAN5=		bse.5

post-patch:
	@${REINPLACE_CMD} -Ee 's|$${libdir}/ladspa|${LOCALBASE}/lib/ladspa|; \
		/FLAGS=/ s/(-g|-ggdb3|-pipe|-O2|-ftracer|-finline-functions|-fno-keep-static-consts)//; \
		s|echo aout|echo elf|g' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|/usr/bin/perl|${PERL}|' \
		${WRKSRC}/autotools/intltool-merge
	@${REINPLACE_CMD} -e 's|/bin/bash|${SH}|' \
		${WRKSRC}/mkrelease.sh
	@${REINPLACE_CMD} -e 's|-DG_DISABLE_DEPRECATED||g' \
		${WRKSRC}/bse/Makefile.in \
		${WRKSRC}/bse/zintern/Makefile.in

.include <bsd.port.post.mk>
