# New ports collection makefile for:	ezstream
# Date created:				27 Nov 2004
# Whom:					Frank Laszlo <laszlof@vonostingroup.com>
#
# $FreeBSD$
#

PORTNAME=	ezstream
PORTVERSION=	0.5.6
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	http://downloads.xiph.org/releases/ezstream/ \
		http://svn.xiph.org/releases/ezstream/

MAINTAINER=	ayu@commun.jp
COMMENT=	A command line utility for streaming to icecast servers

LIB_DEPENDS=	shout.5:${PORTSDIR}/audio/libshout2 \
		vorbis.4:${PORTSDIR}/audio/libvorbis

OPTIONS=	TAGLIB "TagLib support" on

USE_GNOME=	libxml2
USE_ICONV=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"

MAN1=		ezstream.1 ezstream-file.sh.1
PORTDOCS=	NEWS README
PORTEXAMPLES=	ezstream_metadata.xml ezstream_mp3.xml \
		ezstream_reencode_mp3.xml ezstream_reencode_theora.xml \
		ezstream_reencode_vorbis.xml ezstream_stdin_vorbis.xml \
		ezstream_vorbis.xml meta.sh play.sh
PLIST_FILES=	bin/ezstream bin/ezstream-file.sh

CPPFLAGS=	-I${LOCALBASE}/include ${PTHREAD_CFLAGS}
LDFLAGS=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}

.include <bsd.port.pre.mk>

.if defined(WITHOUT_TAGLIB)
CONFIGURE_ARGS+=	--without-taglib
.else
LIB_DEPENDS+=	tag.1:${PORTSDIR}/audio/taglib
CONFIGURE_ARGS+=	--with-taglib=${LOCALBASE}
.endif

post-patch:
	@${REINPLACE_CMD} -e '/^SUBDIRS =/s|examples||g ; \
		 s|: install-dist_docDATA|:|g' ${WRKSRC}/Makefile.in

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif
.if !defined(NOPORTEXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}
.for file in ${PORTEXAMPLES}
	${INSTALL_DATA} ${WRKSRC}/examples/${file} ${EXAMPLESDIR}
.endfor
.endif

.include <bsd.port.post.mk>
