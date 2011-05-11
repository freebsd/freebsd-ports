# New ports collection makefile for:	linuxsampler
# Date created:		2007-01-24
# Whom:			trasz <trasz@pin.if.uz.zgora.pl>
#
# $FreeBSD$
#

PORTNAME=	linuxsampler
PORTVERSION=	1.0.0
CATEGORIES=	audio
MASTER_SITES=	http://download.linuxsampler.org/packages/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Modular MIDI sampler

LIB_DEPENDS=	jack.0:${PORTSDIR}/audio/jack \
		gig.10:${PORTSDIR}/audio/libgig \

RESTRICTED=	no commercial use
BROKEN=		unfetchable

ONLY_FOR_ARCHS=	i386 amd64
ONLY_FOR_ARCHS_REASON=	"not yet ported"

USE_BZIP2=	yes
USE_GNOME=	gnomehack
USE_SQLITE=	3
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool
CONFIGURE_ENV=	HAVE_UNIX98=1
CONFIGURE_ARGS=	LDFLAGS="${LDFLAGS}"
USE_LDCONFIG=	yes

MAN1=		linuxsampler.1

CPPFLAGS=	-I${LOCALBASE}/include
LDFLAGS=	-L${LOCALBASE}/lib

.include <bsd.port.pre.mk>

#.if ${OSVERSION} >= 900000
#BROKEN=		Does not compile
#.endif

post-patch:
	@${REINPLACE_CMD} -e \
		's|CXX_CPU_SWITCH=.*|CXX_CPU_SWITCH=|g' ${WRKSRC}/configure

.include <bsd.port.post.mk>
