# New ports collection makefile for:	musicpd
# Date created:		Tue Oct 02 2003
# Whom:			Mark Reidel <ports@mark.reidel.info>
#
# $FreeBSD$
#

PORTNAME=	musicpd
PORTVERSION=	0.12.2
CATEGORIES=	audio ipv6
MASTER_SITES=	http://musicpd.org/uploads/files/
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	mpd-${PORTVERSION}

MAINTAINER=	ports@mark.reidel.info
COMMENT=	A remote-controllable music-daemon

LIB_DEPENDS+=	mad.2:${PORTSDIR}/audio/libmad

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_RC_SUBR=	musicpd.sh
PKGMESSAGE=	${WRKDIR}/pkg-message

OPTIONS=	FLAC "Support for FLAC Audio" on \
		VORBIS "Support for OGG Vorbis Audio" on \
		WAV "Support for WAV Audio" on \
		AAC "Support for MP4/AAC Audio" off \
		MUSEPACK "Support for MPC Audio" off \
		MOD "Support for MOD Audio" off \
		ICONV "Support for international characters" on \
	        ID3TAG "Support for id3v1 tag encoding" off \
		IPV6 "Support for IPV6" on \
		AO "Support for libao" off

CONFIGURE_TARGET=--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ARGS=	--disable-pulse \
		--disable-shout \
		--mandir=${MANPREFIX}/man

.include <bsd.port.pre.mk>

.ifdef(WITHOUT_FLAC)
CONFIGURE_ARGS+=--disable-flac \
		--disable-oggflac
.else
LIB_DEPENDS+=	FLAC.7:${PORTSDIR}/audio/flac
.endif

.ifdef(WITHOUT_VORBIS)
CONFIGURE_ARGS+=--disable-ogg
.else
LIB_DEPENDS+=	vorbis.3:${PORTSDIR}/audio/libvorbis
.endif

.ifdef(WITHOUT_WAV)
CONFIGURE_ARGS+=--disable-audiofile
.else
LIB_DEPENDS+=	audiofile.0:${PORTSDIR}/audio/libaudiofile
.endif

.ifdef(WITH_AAC)
LIB_DEPENDS+=	faad.0:${PORTSDIR}/audio/faad
.else
CONFIGURE_ARGS+=--disable-aac
.endif

.ifdef(WITH_MUSEPACK)
LIB_DEPENDS+=	mpcdec.5:${PORTSDIR}/audio/libmpcdec
.else
CONFIGURE_ARGS+=--disable-mpc
.endif

.ifdef(WITH_MOD)
LIB_DEPENDS+=	mikmod.2:${PORTSDIR}/audio/libmikmod
.else
CONFIGURE_ARGS+=--disable-mod
.endif

.ifdef(WITHOUT_ICONV)
CONFIGURE_ARGS+=--disable-iconv
.else
USE_ICONV=	yes
.endif

.ifdef(WITH_ID3TAG)
LIB_DEPENDS+=	id3tag.0:${PORTSDIR}/audio/libid3tag
CONFIGURE_ARGS+=--enable-mpd-id3tag
.endif

.ifdef(WITHOUT_IPV6)
CONFIGURE_ARGS+=--disable-ipv6
.endif

.ifdef(WITH_AO)
CONFIGURE_ARGS+=--enable-ao
LIB_DEPENDS+=	ao.3:${PORTSDIR}/audio/libao
.endif

CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

CFLAGS+=	-I${PREFIX}/include

MAN1=		mpd.1
MAN5=		mpd.conf.5

DOCSDIR=	${PREFIX}/share/doc/mpd
DOCS=	COMMANDS \
		mpdconf.example \
		README \
		UPGRADING

SED_SCRIPT+=	-e 's,%%PREFIX%%,${PREFIX},g'

post-build:
	@${SED} ${SED_SCRIPT} ${MASTERDIR}/pkg-message >${PKGMESSAGE}

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
