# New ports collection makefile for:	grip
# Date created:				31 May 2000
# Whom:					kbyanc@posi.net
#
# $FreeBSD$
#

PORTNAME=	grip
PORTVERSION=	3.2.0
PORTREVISION=	7
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_EXTENDED}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ahze@FreeBSD.org
COMMENT=	GTK front-end to external cd rippers and audio encoders

LIB_DEPENDS=	id3-3.8.3:${PORTSDIR}/audio/id3lib \
		curl.3:${PORTSDIR}/ftp/curl
PATCH_DEPENDS=	iconv:${PORTSDIR}/converters/libiconv

USE_X_PREFIX=	yes
USE_GNOME=	gnomehack gnomeprefix gnometarget libgnomeui vte
USE_GMAKE=	yes
USE_LIBTOOL_VER=	15
USE_REINPLACE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

OPTIONS=	CDPARANOIA "Ripper: Enable cdparanoia support" on \
		CDDA2WAV "Ripper: cdda2wav: Install sysutils/cdrtools" off
.if defined(PACKAGE_BUILDING)
OPTIONS+=	LAME "Encoder: lame: Install audio/lame" off \
		VORBIS "Encoder: oggenc: Install audio/vorbis-tools" on
.else
OPTIONS+=	LAME "Encoder: lame: Install audio/lame" on \
		VORBIS "Encoder: oggenc: Install audio/vorbis-tools" off
.endif
OPTIONS+=	BLADEENC "Encoder: bladeenc: Install audio/bladeenc" off \
		FAAC "Encoder: faac: Install audio/faac" off \
		FLAC "Encoder: flac: Install audio/flac" off \
		GOGO "Encoder: gogo: Install audio/gogo" off \
		MP3ENCODE "Encoder: mp3encode: Install audio/mp3encode" off

ISO_LOCALES=	de es fr pt_BR

.include <bsd.port.pre.mk>

.if defined(WITH_CDROM_DEVICE)
DEFAULT_CDROM_DEVICE=${WITH_CDROM_DEVICE}
.else
.if ${OSVERSION} < 500000
DEFAULT_CDROM_DEVICE=/dev/acd0c
.else
DEFAULT_CDROM_DEVICE=/dev/acd0
.endif
.endif

.if !defined(WITHOUT_CDPARANOIA)
LIB_DEPENDS+=	cdda_paranoia.0:${PORTSDIR}/audio/cdparanoia
CONFIGURE_ARGS+=	--enable-cdpar
.else
CONFIGURE_ARGS+=	--disable-cdpar
.endif

.if defined(WITH_CDDA2WAV)
RUN_DEPENDS+=	cdda2wav:${PORTSDIR}/sysutils/cdrtools
.endif

.if defined(WITH_BLADEENC)
RUN_DEPENDS+=	bladeenc:${PORTSDIR}/audio/bladeenc
.endif

.if defined(WITH_FAAC)
RUN_DEPENDS+=	faac:${PORTSDIR}/audio/faac
.endif

.if defined(WITH_FLAC)
RUN_DEPENDS+=	flac:${PORTSDIR}/audio/flac
.endif

.if defined(WITH_GOGO)
RUN_DEPENDS+=	gogo:${PORTSDIR}/audio/gogo
.endif

.if defined(WITH_MP3ENCODE)
RUN_DEPENDS+=	encode:${PORTSDIR}/audio/mp3encode
.endif

.if !defined(WITHOUT_LAME)
RUN_DEPENDS+=	lame:${PORTSDIR}/audio/lame
.endif

.if defined(WITH_BLADEENC)
RUN_DEPENDS+=	bladeenc:${PORTSDIR}/audio/bladeenc
.endif

.if defined(WITH_VORBIS)
RUN_DEPENDS+=	ogg123:${PORTSDIR}/audio/vorbis-tools
.endif

pre-everything::
.if !defined(WITH_CDROM_DEVICE)
	@${ECHO_MSG} "===> The default CDROM device is ${DEFAULT_CDROM_DEVICE}"
	@${ECHO_MSG} "===> Define WITH_CDROM_DEVICE if you want to change the default"
	@${ECHO_MSG} "===> For example, 'make WITH_CDROM_DEVICE=\"/dev/somedevice\"'"
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|/dev/cdrom|${DEFAULT_CDROM_DEVICE}|' \
		${WRKSRC}/src/grip.c
	@${REINPLACE_CMD} -e 's|{"xingmp3enc","-B %b -Q %w","mp3"},||; \
		s|{"l3enc","-br %b %w %m","mp3"},|{"faac","--no-midside -w --artist %a --album %d --track %t --year %y --genre %g -b %b %w -o %m", "m4a"},|; \
		s|mp3encode|encode|' \
		${WRKSRC}/src/gripcfg.c
.for l in ${ISO_LOCALES}
	@${MV} ${WRKSRC}/po/${l}.po ${WRKSRC}/po/_${l}.po
	${LOCALBASE}/bin/iconv -f ISO-8859-15 -t UTF-8 \
		${WRKSRC}/po/_${l}.po > ${WRKSRC}/po/${l}.po
.endfor
	@${MV} ${WRKSRC}/po/ru.po ${WRKSRC}/po/_ru.po
	${LOCALBASE}/bin/iconv -f koi8-r -t UTF-8 \
		${WRKSRC}/po/_ru.po > ${WRKSRC}/po/ru.po

.include <bsd.port.post.mk>
