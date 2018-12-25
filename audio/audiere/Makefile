# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	audiere
PORTVERSION=	1.9.4
PORTREVISION=	7
CATEGORIES=	audio
MASTER_SITES=	SF

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	High-level audio API

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/doc/license.txt

USES=		autoreconf gmake libtool
GNU_CONFIGURE=	yes
USE_CXXSTD=	c++98
USE_LDCONFIG=	yes

CONFIGURE_ENV=	PTHREAD_LIBS="-lpthread"
CPPFLAGS+=	-I${LOCALBASE}/include/speex -I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

PORTDOCS=	changelog.txt cvs.txt dependencies.txt faq.txt glossary.txt \
		license.txt overview.txt readme.txt release-howto.txt \
		tutorial.txt

OPTIONS_DEFINE=		DUMB CDAUDIO VORBIS SPEEX DOCS
OPTIONS_DEFAULT=	DUMB CDAUDIO VORBIS SPEEX

DUMB_DESC=	DUMB support
CDAUDIO_DESC=	libcdaudio support

# since dumb is a static lib and it depends on ogg, we should
# link audiere with ogg as well
DUMB_IMPLIES=	VORBIS

DUMB_BUILD_DEPENDS=	${LOCALBASE}/lib/libdumb.a:audio/dumb
CDAUDIO_LIB_DEPENDS=	libcdaudio.so:audio/libcdaudio
VORBIS_LIB_DEPENDS=	libvorbis.so:audio/libvorbis \
			libogg.so:audio/libogg
SPEEX_LIB_DEPENDS=	libspeex.so:audio/speex

post-patch:
# could be an option, but build is broken with recent FLAC
	@${REINPLACE_CMD} -e '/AC_CHECK_LIB/ s|FLAC|no_&|; \
		s|wx_config|no_&|' \
		${WRKSRC}/configure.in

post-patch-DUMB-off:
	@${REINPLACE_CMD} -e '/AC_CHECK_LIB/ s|dumb|no_&|' \
		${WRKSRC}/configure.in

post-patch-CDAUDIO-off:
	@${REINPLACE_CMD} -e '/AC_CHECK_LIB/ s|cdaudio|no_&|' \
		${WRKSRC}/configure.in

post-patch-VORBIS-off:
	@${REINPLACE_CMD} -e '/AC_CHECK_HEADER/ s|vorbis|no_&|' \
		${WRKSRC}/configure.in

post-patch-SPEEX-off:
	@${REINPLACE_CMD} -e '/AC_CHECK_HEADER/ s|speex|no_&|' \
		${WRKSRC}/configure.in

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libaudiere.so

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/doc/${f} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
