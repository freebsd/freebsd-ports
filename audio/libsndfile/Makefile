# New ports collection makefile for:	libsndfile
# Date created:			Jul 20, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	libsndfile
PORTVERSION=	1.0.21
PORTREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	http://www.mega-nerd.com/libsndfile/files/

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	Reading and writing files containing sampled sound (like WAV or AIFF)

USE_GNOME=	gnomehack gnometarget pkgconfig
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
CONFIGURE_ARGS=	--disable-gcc-pipe \
		--disable-sqlite \
		--disable-octave
CONFIGURE_ENV=	CPPFLAGS="-isystem /usr/include -isystem ${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
USE_LDCONFIG=	yes

MAN1=		sndfile-concat.1 sndfile-cmp.1 sndfile-convert.1 sndfile-info.1 sndfile-metadata-get.1 sndfile-metadata-set.1 sndfile-play.1

OPTIONS=	EXTERNAL "Enable FLAC and Ogg Vorbis support" on

.include <bsd.port.pre.mk>

.if defined(WITHOUT_EXTERNAL)
CONFIGURE_ARGS+=--disable-external-libs
.else
LIB_DEPENDS+=	FLAC.10:${PORTSDIR}/audio/flac \
		vorbis.4:${PORTSDIR}/audio/libvorbis
.endif

post-patch:
	@${REINPLACE_CMD} -e '/^SUBDIRS =/s/ doc / /g' ${WRKSRC}/Makefile.in

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${TAR} -C ${WRKSRC}/doc --exclude "*Makefile*" --exclude "*.in" \
		-cf - . | ${TAR} -C ${DOCSDIR} --unlink -xf -
	@${CHOWN} ${SHAREOWN}:${SHAREGRP} ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
