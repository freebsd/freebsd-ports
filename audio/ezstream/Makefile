# New ports collection makefile for:	ezstream
# Date created:				27 Nov 2004
# Whom:					Frank Laszlo <laszlof@vonostingroup.com>
#
# $FreeBSD$
#

PORTNAME=	ezstream
PORTVERSION=	0.2.1
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	http://svn.xiph.org/releases/ezstream/

MAINTAINER=	laszlof@vonostingroup.com
COMMENT=	A command line utility for streaming to icecast servers

LIB_DEPENDS=	shout.5:${PORTSDIR}/audio/libshout2 \
		vorbis.3:${PORTSDIR}/audio/libvorbis \
		xml2.5:${PORTSDIR}/textproc/libxml2

GNU_CONFIGURE=  yes

CFLAGS+=	${PTHREAD_CFLAGS} -I${LOCALBASE}/include
LDFLAGS+=	${PTHREAD_LIBS} -L${LOCALBASE}/lib

CONFIGURE_ENV+=	CFLAGS="${CFLAGS}" LDFLAGS="${LDFLAGS}"

PLIST_FILES=	bin/ezstream
PORTDOCS=	ezstream_mp3.xml ezstream_reencoding_example_vorbis.xml \
		ezstream_reencoding_example_mp3.xml ezstream_vorbis.xml \
		ezstream_reencoding_example_theora.xml

.if !defined(NOPORTDOCS)
post-install:
	${MKDIR} ${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/conf/${f} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
