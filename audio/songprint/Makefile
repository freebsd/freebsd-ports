# New ports collection makefile for:	Freetantrum SongPrint
# Date created:				Sat Dec  8 22:27:55 BRST 2001
# Whom:			Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	songprint
PORTVERSION=	1.2
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	freetantrum

MAINTAINER=	lioux@FreeBSD.org
COMMENT=	Library for acoustic fingerprinting of music from Freetantrum (TM)

LIB_DEPENDS=	fftw.2:${PORTSDIR}/math/fftw

USE_GNOME=	glib12
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
INSTALLS_SHLIB=	yes

# turn off mp3 codec in reference code
.ifdef(WITHOUT_MP3)
CONFIGURE_ARGS+=	--disable-mp3
.endif
# turn off OggVorbis codec in reference code
.ifdef(WITHOUT_OGG)
CONFIGURE_ARGS+=	--disable-oggvorbis
.endif
# turn off wave codec in reference code
.ifdef(WITHOUT_WAV)
CONFIGURE_ARGS+=	--disable-wav
.endif

DOC_FILES=	AUTHORS COPYING NEWS README

pre-everything::
.ifndef(WITHOUT_MP3)
	@${ECHO_MSG} "You can disable MP3 audio file support by defining WITHOUT_MP3."
.endif
.ifndef(WITHOUT_OGG)
	@${ECHO_MSG} "You can disable OGG audio file support by defining WITHOUT_OGG."
.endif
.ifndef(WITHOUT_WAV)
	@${ECHO_MSG} "You can disable WAV audio file support by defining WITHOUT_WAV."
.endif

post-install:
.ifndef(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for doc in ${DOC_FILES}
	@${INSTALL_DATA} ${WRKSRC}/${doc} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
