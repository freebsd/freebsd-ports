# New ports collection makefile for:	libshout
# Date created:				06 Jun 2000
# Whom:					zach@pabst.bendnet.com
#
# $FreeBSD$
#

PORTNAME=	libshout2
PORTVERSION=	20021112
PORTREVISION=	1
CATEGORIES=	audio net
MASTER_SITES=	http://tigress.com/lofi/ \
		http://lofi.dyndns.org/
DISTNAME=	libshout-devel-${PORTVERSION}

MAINTAINER=	michaelnottebrock@gmx.net

LIB_DEPENDS=	ogg.4:${PORTSDIR}/audio/libogg \
		vorbis.2:${PORTSDIR}/audio/libvorbis

CONFIGURE_ENV=	CFLAGS="${PTHREAD_CFLAGS} -I${LOCALBASE}/include" \
		LDFLAGS="${PTHREAD_LIBS} -L${LOCALBASE}/lib"
INSTALLS_SHLIB=	yes
USE_GMAKE=	yes
USE_AUTOMAKE=	yes
USE_LIBTOOL=	yes
USE_REINPLACE=	yes

WRKSRC=		${WRKDIR}/libshout

post-configure:
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|'\
					${WRKSRC}/examples/Makefile
	@${REINPLACE_CMD} -E -e 's|(INCLUDES \=.*)|\1 -I${LOCALBASE}/include|'\
					${WRKSRC}/src/Makefile
	@${REINPLACE_CMD} -e 's|-O20|${CFLAGS}|' ${WRKSRC}/examples/Makefile \
						${WRKSRC}/include/Makefile \
						${WRKSRC}/include/shout/Makefile \
						${WRKSRC}/src/avl/Makefile \
						${WRKSRC}/src/httpp/Makefile \
						${WRKSRC}/src/net/Makefile \
						${WRKSRC}/src/timing/Makefile \
						${WRKSRC}/src/thread/Makefile \
						${WRKSRC}/src/Makefile \
						${WRKSRC}/Makefile

.include <bsd.port.mk>
