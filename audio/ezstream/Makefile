# New ports collection makefile for: ezstream
# Date created:         27 Nov 2004
# Whom:                 Frank Laszlo <laszlof@vonostingroup.com>
#
# $FreeBSD$
#

PORTNAME=	ezstream
PORTVERSION=	0.1.2
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	http://svn.xiph.org/releases/ezstream/

MAINTAINER=	laszlof@vonostingroup.com
COMMENT=	A command line utility for streaming to icecast servers

LIB_DEPENDS=	shout.4:${PORTSDIR}/audio/libshout2 \
		vorbis.3:${PORTSDIR}/audio/libvorbis \
		xml2.5:${PORTSDIR}/textproc/libxml2

CONFIGURE_ENV=	CFLAGS="${PTHREAD_CFLAGS} -I${LOCALBASE}/include" \
		LDFLAGS="${PTHREAD_LIBS} -L${LOCALBASE}/lib"
USE_GMAKE=	yes
USE_LIBTOOL_VER=	15

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/conf/ezstream_m3u.xml \
	${WRKSRC}/conf/ezstream_mp3.xml \
	${WRKSRC}/conf/ezstream_vorbis.xml \
	${DOCSDIR}
.endif

.include <bsd.port.mk>
