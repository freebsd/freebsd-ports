# New ports collection makefile for:	musicpd
# Date created:		Tue Oct 02 2003
# Whom:			Mark Reidel <ports@mark.reidel.info>
#
# $FreeBSD$
#

PORTNAME=	musicpd
PORTVERSION=	0.9.4
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	mpd-${PORTVERSION}

MAINTAINER=	ports@mark.reidel.info
COMMENT=	A remote-controllable music-daemon

LIB_DEPENDS+=	ao.3:${PORTSDIR}/audio/libao \
		mad.2:${PORTSDIR}/audio/mad

GNU_CONFIGURE=	yes
PKGMESSAGE=	${WRKDIR}/pkg-message

OPTIONS=	FLAC "Support for FLAC Audio" on \
		VORBIS "Support for OGG Vorbis Audio" on \
		WAV "Support for WAV Audio" on \
		ICONV "Support for international characters" on

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 500038
RC_SUBR?=	${DESTDIR}/etc/rc.subr
RC_SUFX=
.else
USE_RC_SUBR=	yes
RC_SUFX=	.sh
.endif

.ifdef(WITHOUT_FLAC)
CONFIGURE_ARGS+=--disable-flac
.else
LIB_DEPENDS+=	FLAC.5:${PORTSDIR}/audio/flac
.endif

.ifdef(WITHOUT_VORBIS)
CONFIGURE_ARGS+=--disable-ogg
.else
LIB_DEPENDS+=	vorbis.3:${PORTSDIR}/audio/libvorbis
.endif

.ifdef(WITHOUT_WAV)
CONFIGURE_ARGS+=--disable-audiofile
.else
LIB_DEPENDS+=	ao.3:${PORTSDIR}/audio/libaudiofile
.endif

.ifdef(WITHOUT_ICONV)
CONFIGURE_ARGS+=--disable-iconv
.else
LIB_DEPENDS+=	iconv.3:${PORTSDIR}/converters/libiconv
.endif

CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

CFLAGS+=	-I${PREFIX}/include

MAN1=		mpd.1

DOCS=		README \
		UPGRADING \
		doc/COMMANDS

SED_SCRIPT+=	-e 's,%%PREFIX%%,${PREFIX},g' \
		-e 's,%%EXAMPLESDIR%%,${EXAMPLESDIR},g' \
		-e 's,%%RC_SUBR%%,${RC_SUBR},g' \
		-e 's,%%RC_SUFX%%,${RC_SUFX},g'
PLIST_SUB+=	RC_SUFX=${RC_SUFX}

post-build:
	@${SED} ${SED_SCRIPT} ${FILESDIR}/musicpd.sh >${WRKDIR}/musicpd.sh
	@${SED} ${SED_SCRIPT} ${MASTERDIR}/pkg-message >${PKGMESSAGE}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/mpd ${PREFIX}/bin/
	${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${FILESDIR}/mpd.conf.sample ${EXAMPLESDIR}/mpd.conf
	${INSTALL_SCRIPT} ${WRKDIR}/musicpd.sh ${PREFIX}/etc/rc.d/musicpd${RC_SUFX}
	${INSTALL_MAN} ${WRKSRC}/doc/mpd.1 ${MAN1PREFIX}/man/man1/
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	@cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${DOCSDIR}/
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
