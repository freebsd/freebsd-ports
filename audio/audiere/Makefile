# New ports collection makefile for:	audiere
# Date created:		12 Sep 2007
# Whom:			Dmitry Marakasov <amdmi3@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	audiere
PORTVERSION=	1.9.4
PORTREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	SF

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	High-level audio API

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
WANT_WX=	yes
USE_AUTOTOOLS=	autoconf:262
USE_LDCONFIG=	yes

CONFIGURE_ENV=	LDFLAGS="-L${LOCALBASE}/lib" \
		CPPFLAGS="-I${LOCALBASE}/include/speex -I${LOCALBASE}/include" \
		PTHREAD_LIBS="${PTHREAD_LIBS}" PTHREAD_CFLAGS="${PTHREAD_CFLAGS}"

PORTDOCS=	changelog.txt cvs.txt dependencies.txt faq.txt glossary.txt \
		license.txt overview.txt readme.txt release-howto.txt \
		tutorial.txt

CONFIGURE_REPLACES='s|wx_config|no_&|'

OPTIONS=	DUMB	"Enable DUMB support"	on \
		CDAUDIO	"Enable libcdaudio support"	on \
		VORBIS	"Enable ogg vorbis support"	on \
		SPEEX	"Enable speex support"	on
#		FLAC	"Enable FLAC support"	on

.include <bsd.port.pre.mk>

# Broken with recent FLAC
#.if !defined(WITHOUT_FLAC)
#LIB_DEPENDS+=	FLAC:${PORTSDIR}/audio/flac
#.else
CONFIGURE_REPLACES+='/AC_CHECK_LIB/ s|FLAC|no_&|'
#.endif

.if !defined(WITHOUT_DUMB)
BUILD_DEPENDS+=	${LOCALBASE}/lib/libdumb.a:${PORTSDIR}/audio/dumb
.else
CONFIGURE_REPLACES+='/AC_CHECK_LIB/ s|dumb|no_&|'
.endif

.if !defined(WITHOUT_CDAUDIO)
LIB_DEPENDS+=	cdaudio.1:${PORTSDIR}/audio/libcdaudio
.else
CONFIGURE_REPLACES+='/AC_CHECK_LIB/ s|cdaudio|no_&|'
.endif

.if !defined(WITHOUT_VORBIS)
LIB_DEPENDS+=	vorbis.4:${PORTSDIR}/audio/libvorbis \
		ogg.7:${PORTSDIR}/audio/libogg
.else
CONFIGURE_REPLACES+='/AC_CHECK_HEADER/ s|vorbis|no_&|'
.endif

.if !defined(WITHOUT_SPEEX)
LIB_DEPENDS+=	speex.1:${PORTSDIR}/audio/speex
.else
CONFIGURE_REPLACES+='/AC_CHECK_HEADER/ s|speex|no_&|'
.endif

post-patch:
	@${REINPLACE_CMD} ${CONFIGURE_REPLACES:C/.*/-e &/} \
		-e 's|-lpthread|${PTHREAD_LIBS}|' \
		${WRKSRC}/configure.in

.if !defined(NOPORTDOCS)
post-install:
	${MKDIR} ${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/doc/${f} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>
