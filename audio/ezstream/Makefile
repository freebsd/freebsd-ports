PORTNAME=	ezstream
PORTVERSION=	0.5.6
PORTREVISION=	11
CATEGORIES=	audio
MASTER_SITES=	https://downloads.xiph.org/releases/ezstream/ \
		https://ftp.osuosl.org/pub/xiph/releases/ezstream/

MAINTAINER=	ayu@commun.jp
COMMENT=	Command line utility for streaming to icecast servers
WWW=		http://www.icecast.org/ezstream.php

LIB_DEPENDS=	libshout.so:audio/libshout \
		libvorbis.so:audio/libvorbis

OPTIONS_DEFINE=	TAGLIB DOCS EXAMPLES
OPTIONS_DEFAULT=	TAGLIB

TAGLIB_DESC=	TagLib support

USES=		gnome iconv pkgconfig
USE_GNOME=	libxml2
USE_RC_SUBR=	${PORTNAME}
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share

PORTDOCS=	NEWS README
PORTEXAMPLES=	ezstream_metadata.xml ezstream_mp3.xml \
		ezstream_reencode_mp3.xml ezstream_reencode_theora.xml \
		ezstream_reencode_vorbis.xml ezstream_stdin_vorbis.xml \
		ezstream_vorbis.xml meta.sh play.sh
PLIST_FILES=	bin/ezstream bin/ezstream-file.sh etc/ezstream/ezstream.xml \
		share/man/man1/ezstream-file.sh.1.gz share/man/man1/ezstream.1.gz

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-lpthread -L${LOCALBASE}/lib

TAGLIB_CONFIGURE_OFF=	--without-taglib
TAGLIB_LIB_DEPENDS=		libtag.so:audio/taglib
TAGLIB_CONFIGURE_ON=	--with-taglib=${LOCALBASE}

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e '/^SUBDIRS =/s|examples||g ; \
		s|: install-dist_docDATA|:|g' ${WRKSRC}/Makefile.in

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/
.for file in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${file} ${STAGEDIR}${DOCSDIR}/
.endfor
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/
.for f in ${PORTEXAMPLES}
	${INSTALL_DATA} ${WRKSRC}/examples/${f} ${STAGEDIR}${EXAMPLESDIR}/
.endfor
	@${MKDIR} ${STAGEDIR}${ETCDIR}/
	${INSTALL_DATA} ${WRKSRC}/examples/ezstream_vorbis.xml ${STAGEDIR}${ETCDIR}/ezstream.xml

.include <bsd.port.mk>
