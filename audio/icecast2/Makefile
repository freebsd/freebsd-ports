# New ports collection makefile for: icecast
# Date created:         28 Jan 1999
# Whom:                 Chip Marshall <chip@eboai.org>
#
# $FreeBSD$
#

PORTNAME=	icecast2
PORTVERSION=	20021112
CATEGORIES=	audio net ipv6
MASTER_SITES=	http://tigress.com/lofi/\
		http://lofi.dyndns.org/
DISTNAME=	icecast-devel-${PORTVERSION}

MAINTAINER=	michaelnottebrock@gmx.net

LIB_DEPENDS=	ogg.4:${PORTSDIR}/audio/libogg \
		shout.3:${PORTSDIR}/audio/libshout2 \
		vorbis.2:${PORTSDIR}/audio/libvorbis \
		xslt.1:${PORTSDIR}/textproc/libxslt

AUTOMAKE_ARGS=	--add-missing
AUTOMAKE_ENV=	CFLAGS="${PTHREAD_CFLAGS} -I${LOCALBASE}/include" \
		LDFLAGS="${PTHREAD_LIBS} -L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--disable-oggtest --disable-vorbistest --disable-shouttest
CONFIGURE_ENV=	CFLAGS="${PTHREAD_CFLAGS} -I${LOCALBASE}/include" \
		LDFLAGS="${PTHREAD_LIBS} -L${LOCALBASE}/lib"
USE_AUTOMAKE=	yes
USE_GMAKE=	yes
USE_LIBTOOL=	yes
USE_REINPLACE=	yes

WRKSRC=		${WRKDIR}/icecast

post-configure:
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|' ${WRKSRC}/src/Makefile
	@${REINPLACE_CMD} -e 's|-O20|${CFLAGS}|' ${WRKSRC}/conf/Makefile \
						${WRKSRC}/doc/Makefile \
						${WRKSRC}/src/avl/Makefile \
						${WRKSRC}/src/log/Makefile \
						${WRKSRC}/src/net/Makefile \
						${WRKSRC}/src/httpp/Makefile \
						${WRKSRC}/src/thread/Makefile \
						${WRKSRC}/src/timing/Makefile \
						${WRKSRC}/src/Makefile \
						${WRKSRC}/web/Makefile \
						${WRKSRC}/win32/res/Makefile \
						${WRKSRC}/win32/Makefile \
						${WRKSRC}/Makefile
post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/conf/icecast.xml ${DOCSDIR}
.endif

.include <bsd.port.mk>
