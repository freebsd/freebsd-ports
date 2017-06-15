# Created by: Frank Laszlo <laszlof@vonostingroup.com>
# $FreeBSD$

PORTNAME=	ezstream
PORTVERSION=	0.5.6
PORTREVISION=	6
CATEGORIES=	audio
MASTER_SITES=	http://downloads.xiph.org/releases/ezstream/ \
		http://svn.xiph.org/releases/ezstream/

MAINTAINER=	ayu@commun.jp
COMMENT=	Command line utility for streaming to icecast servers

LIB_DEPENDS=	libshout.so:audio/libshout \
		libvorbis.so:audio/libvorbis

OPTIONS_DEFINE=	TAGLIB DOCS EXAMPLES
OPTIONS_DEFAULT=	TAGLIB

TAGLIB_DESC=	TagLib support

USES=		iconv pkgconfig
USE_GNOME=	libxml2
USE_RC_SUBR=	${PORTNAME}
GNU_CONFIGURE=	yes

PORTDOCS=	NEWS README
PORTEXAMPLES=	ezstream_metadata.xml ezstream_mp3.xml \
		ezstream_reencode_mp3.xml ezstream_reencode_theora.xml \
		ezstream_reencode_vorbis.xml ezstream_stdin_vorbis.xml \
		ezstream_vorbis.xml meta.sh play.sh
PLIST_FILES=	bin/ezstream bin/ezstream-file.sh etc/ezstream/ezstream.xml \
		man/man1/ezstream-file.sh.1.gz man/man1/ezstream.1.gz

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
