# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	audiere
PORTVERSION=	1.9.4
PORTREVISION=	4
CATEGORIES=	audio
MASTER_SITES=	SF

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	High-level audio API

GNU_CONFIGURE=	yes
USES=		gmake
WANT_WX=	yes
USE_AUTOTOOLS=	autoconf
USE_LDCONFIG=	yes

CONFIGURE_ENV=	PTHREAD_LIBS="${PTHREAD_LIBS}" PTHREAD_CFLAGS="${PTHREAD_CFLAGS}"
CPPFLAGS+=	-I${LOCALBASE}/include/speex -I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

PORTDOCS=	changelog.txt cvs.txt dependencies.txt faq.txt glossary.txt \
		license.txt overview.txt readme.txt release-howto.txt \
		tutorial.txt

CONFIGURE_REPLACES='s|wx_config|no_&|'

OPTIONS_DEFINE=		DUMB CDAUDIO VORBIS SPEEX DOCS
OPTIONS_DEFAULT=	DUMB CDAUDIO VORBIS SPEEX

DUMB_DESC=	DUMB support
CDAUDIO_DESC=	libcdaudio support

.include <bsd.port.options.mk>

# Broken with recent FLAC
#.if !defined(WITHOUT_FLAC)
#LIB_DEPENDS+=	FLAC:${PORTSDIR}/audio/flac
#.else
CONFIGURE_REPLACES+='/AC_CHECK_LIB/ s|FLAC|no_&|'
#.endif

.if ${PORT_OPTIONS:MDUMB}
BUILD_DEPENDS+=	${LOCALBASE}/lib/libdumb.a:${PORTSDIR}/audio/dumb
.else
CONFIGURE_REPLACES+='/AC_CHECK_LIB/ s|dumb|no_&|'
.endif

.if ${PORT_OPTIONS:MCDAUDIO}
LIB_DEPENDS+=	libcdaudio.so:${PORTSDIR}/audio/libcdaudio
.else
CONFIGURE_REPLACES+='/AC_CHECK_LIB/ s|cdaudio|no_&|'
.endif

# since dumb is a static lib and it depends on ogg, we should
# link audiere with ogg as well
.if ${PORT_OPTIONS:MVORBIS} || ${PORT_OPTIONS:MDUMB}
LIB_DEPENDS+=	libvorbis.so:${PORTSDIR}/audio/libvorbis \
		libogg.so:${PORTSDIR}/audio/libogg
.else
CONFIGURE_REPLACES+='/AC_CHECK_HEADER/ s|vorbis|no_&|'
.endif

.if ${PORT_OPTIONS:MSPEEX}
LIB_DEPENDS+=	libspeex.so:${PORTSDIR}/audio/speex
.else
CONFIGURE_REPLACES+='/AC_CHECK_HEADER/ s|speex|no_&|'
.endif

post-patch:
	@${REINPLACE_CMD} ${CONFIGURE_REPLACES:C/.*/-e &/} \
		-e 's|-lpthread|${PTHREAD_LIBS}|' \
		${WRKSRC}/configure.in

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/doc/${f} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
