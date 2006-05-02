# ex:ts=8
# New ports collection makefile for:	libsndfile
# Date created:			Jul 20, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	libsndfile
PORTVERSION=	1.0.16
CATEGORIES=	audio
MASTER_SITES=	http://www.mega-nerd.com/libsndfile/

MAINTAINER=	ahze@FreeBSD.org
COMMENT=	Reading and writing files containing sampled sound (like WAV or AIFF)

USE_GNOME=	gnomehack gnometarget pkgconfig
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-justsrc --disable-gcc-pipe
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
INSTALLS_SHLIB=	yes

MAN1=		sndfile-convert.1 sndfile-info.1 sndfile-play.1

OPTIONS=	FLAC "Enable flac support" On \
		SQLITE3 "Enable Sqlite3 support" Off

.include <bsd.port.pre.mk>

.if defined(WITH_SQLITE3)
LIB_DEPENDS+=	sqlite3.8:${PORTSDIR}/databases/sqlite3
.else
CONFIGURE_ARGS=	--disable-sqlite
.endif

.if !defined(WITHOUT_FLAC) || exists(${LOCALBASE}/lib/libFLAC.a)
LIB_DEPENDS+=	FLAC.7:${PORTSDIR}/audio/flac
.endif

post-patch:
	@${REINPLACE_CMD} -e '/^SUBDIRS =/s/ doc / /g' ${WRKSRC}/Makefile.in

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in AUTHORS ChangeLog NEWS README TODO
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
	${TAR} -C ${WRKSRC}/doc --exclude "*Makefile*" --exclude "*.in" \
		-cf - . | ${TAR} -C ${DOCSDIR} --unlink -xf -
	@${CHOWN} ${SHAREOWN}:${SHAREGRP} ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
