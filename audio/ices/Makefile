# New ports collection makefile for: ices
# Date created:         11 Nov 2002
# Whom:                 Michael Nottebrock <michaelnottebrock@gmx.net>
#
# $FreeBSD$
#

PORTNAME=	ices
PORTVERSION=	20021112
CATEGORIES=	audio net
MASTER_SITES=	http://tigress.com/lofi/ \
		http://lofi.dyndns.org/
DISTNAME=	${PORTNAME}-devel-${PORTVERSION}

MAINTAINER=	michaelnottebrock@gmx.net

LIB_DEPENDS=	ogg.4:${PORTSDIR}/audio/libogg \
		shout.3:${PORTSDIR}/audio/libshout2 \
		vorbis.2:${PORTSDIR}/audio/libvorbis \
		xml2.5:${PORTSDIR}/textproc/libxml2

CONFIGURE_ARGS=	--disable-oggtest --disable-vorbistest --disable-shouttest
CONFIGURE_ENV=	CFLAGS="${PTHREAD_CFLAGS} -I${LOCALBASE}/include" \
		LDFLAGS="${PTHREAD_LIBS} -L${LOCALBASE}/lib"
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_LIBTOOL=	yes
USE_REINPLACE=	yes

WRKSRC=		${WRKDIR}/ices

post-configure:
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|g' ${WRKSRC}/src/Makefile
	@${REINPLACE_CMD} -e 's|-O20|${CFLAGS}|g' ${WRKSRC}/conf/Makefile \
						${WRKSRC}/src/avl/Makefile \
						${WRKSRC}/src/log/Makefile \
						${WRKSRC}/src/net/Makefile \
						${WRKSRC}/src/thread/Makefile \
						${WRKSRC}/src/timing/Makefile \
						${WRKSRC}/src/Makefile \
						${WRKSRC}/Makefile

post-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/contrib/run_ices ${LOCALBASE}/bin

.include <bsd.port.mk>
