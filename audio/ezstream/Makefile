# Created by: Frank Laszlo <laszlof@vonostingroup.com>
# $FreeBSD$

PORTNAME=	ezstream
PORTVERSION=	0.5.6
PORTREVISION=	3
CATEGORIES=	audio
MASTER_SITES=	http://downloads.xiph.org/releases/ezstream/ \
		http://svn.xiph.org/releases/ezstream/

MAINTAINER=	ayu@commun.jp
COMMENT=	A command line utility for streaming to icecast servers

LIB_DEPENDS=	libshout.so:${PORTSDIR}/audio/libshout2 \
		libvorbis.so:${PORTSDIR}/audio/libvorbis

OPTIONS_DEFINE=	TAGLIB
OPTIONS_DEFAULT=	TAGLIB

TAGLIB_DESC=	TagLib support

USES=		iconv pkgconfig
NO_STAGE=	yes
USE_GNOME=	libxml2
USE_RC_SUBR=	${PORTNAME}
GNU_CONFIGURE=	yes

MAN1=		ezstream.1 ezstream-file.sh.1
PORTDOCS=	NEWS README
PORTEXAMPLES=	ezstream_metadata.xml ezstream_mp3.xml \
		ezstream_reencode_mp3.xml ezstream_reencode_theora.xml \
		ezstream_reencode_vorbis.xml ezstream_stdin_vorbis.xml \
		ezstream_vorbis.xml meta.sh play.sh
PLIST_FILES=	bin/ezstream bin/ezstream-file.sh etc/ezstream/ezstream.xml '@dirrm etc/ezstream'

CPPFLAGS+=	-I${LOCALBASE}/include ${PTHREAD_CFLAGS}
LDFLAGS+=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MTAGLIB}
CONFIGURE_ARGS+=	--without-taglib
.else
LIB_DEPENDS+=		libtag.so:${PORTSDIR}/audio/taglib
CONFIGURE_ARGS+=	--with-taglib=${LOCALBASE}
.endif

post-patch:
	@${REINPLACE_CMD} -e '/^SUBDIRS =/s|examples||g ; \
		s|: install-dist_docDATA|:|g' ${WRKSRC}/Makefile.in

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}/
.for file in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}/
.endfor
.endif
.if !defined(NOPORTEXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}/
.for f in ${PORTEXAMPLES}
	${INSTALL_DATA} ${WRKSRC}/examples/${f} ${EXAMPLESDIR}/
.endfor
.endif
	@${MKDIR} ${ETCDIR}/
	@${INSTALL_DATA} ${WRKSRC}/examples/ezstream_vorbis.xml ${ETCDIR}/ezstream.xml

.include <bsd.port.mk>
