# New ports collection makefile for:	ezstream
# Date created:				27 Nov 2004
# Whom:					Frank Laszlo <laszlof@vonostingroup.com>
#
# $FreeBSD$
#

PORTNAME=	ezstream
PORTVERSION=	0.5.3
CATEGORIES=	audio
MASTER_SITES=	http://svn.xiph.org/releases/ezstream/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A command line utility for streaming to icecast servers

LIB_DEPENDS=	shout.5:${PORTSDIR}/audio/libshout2 \
		vorbis.4:${PORTSDIR}/audio/libvorbis \
		xml2.5:${PORTSDIR}/textproc/libxml2

GNU_CONFIGURE=	yes

CFLAGS+=	${PTHREAD_CFLAGS} -I${LOCALBASE}/include
LDFLAGS+=	${PTHREAD_LIBS} -L${LOCALBASE}/lib

CONFIGURE_ENV+=	CFLAGS="${CFLAGS}" LDFLAGS="${LDFLAGS}"

PLIST_FILES=	bin/ezstream
PORTEXAMPLES=	ezstream_metadata.xml ezstream_mp3.xml ezstream_reencode_mp3.xml \
		ezstream_reencode_theora.xml ezstream_reencode_vorbis.xml \
		ezstream_stdin_vorbis.xml ezstream_vorbis.xml meta.sh play.sh

MAN1=	ezstream.1

post-patch:
	${REINPLACE_CMD} -e 's|COPYING NEWS README||g; s|examples||g; \
	    s|install-dist_docDATA||g' ${WRKSRC}/Makefile.am ${WRKSRC}/Makefile.in

.if !defined(NOPORTEXAMPLES)
post-install:
	${INSTALL} -d ${EXAMPLESDIR}
.for ex in ${PORTEXAMPLES}
	${INSTALL_DATA} ${WRKSRC}/examples/${ex} ${EXAMPLESDIR}
.endfor
.endif

.include <bsd.port.mk>
