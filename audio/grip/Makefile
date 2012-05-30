# New ports collection makefile for:	grip
# Date created:				31 May 2000
# Whom:					kbyanc@posi.net
#
# $FreeBSD$
#    $MCom: ports/audio/grip/Makefile,v 1.4 2007/05/19 21:35:57 marcus Exp $

PORTNAME=	grip
PORTVERSION=	3.3.1
PORTREVISION=	4
CATEGORIES=	audio
MASTER_SITES=	SF

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	GTK front-end to external cd rippers and audio encoders

LIB_DEPENDS=	id3-3.8.3:${PORTSDIR}/audio/id3lib \
		curl.6:${PORTSDIR}/ftp/curl

USE_XORG=	x11
USE_GNOME=	gnomehack gnomeprefix libgnomeui vte
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

OPTIONS_DEFINE=	CDPARANOIA CDDA2WAV LAME VORBIS FAAC FLAC GOGO
OPTIONS_DEFAULT=	CDPARANOIA VORBIS

.if !defined(PACKAGE_BUILDING)
OPTIONS_DEFAULT+=	LAME
.endif

.include <bsd.port.pre.mk>

.if defined(WITH_CDROM_DEVICE)
DEFAULT_CDROM_DEVICE=${WITH_CDROM_DEVICE}
.else
DEFAULT_CDROM_DEVICE=/dev/acd0
.endif

.if ${PORT_OPTIONS:MCDPARANOIA}
LIB_DEPENDS+=	cdda_paranoia.0:${PORTSDIR}/audio/cdparanoia
CONFIGURE_ARGS+=	--enable-cdpar
.else
CONFIGURE_ARGS+=	--disable-cdpar
.endif

.if ${PORT_OPTIONS:MCDDA2WAV}
USE_CDRTOOLS=	yes
.endif

.if ${PORT_OPTIONS:MFAAC}
RUN_DEPENDS+=	faac:${PORTSDIR}/audio/faac
.endif

.if ${PORT_OPTIONS:MFLAC}
RUN_DEPENDS+=	flac:${PORTSDIR}/audio/flac
.endif

.if ${PORT_OPTIONS:MGOGO}
RUN_DEPENDS+=	gogo:${PORTSDIR}/audio/gogo
.endif

.if ${PORT_OPTIONS:MLAME}
RUN_DEPENDS+=	lame:${PORTSDIR}/audio/lame
.endif

.if ${PORT_OPTIONS:MVORBIS}
RUN_DEPENDS+=	ogg123:${PORTSDIR}/audio/vorbis-tools
.endif

.if !defined(WITHOUT_NLS)
USE_GETTEXT=		yes
PLIST_SUB+=		NLS=""
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=		NLS="@comment "
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
		s|{"l3enc","-br %b %w %m","mp3"},|{"faac","--no-midside -w -q 100 --artist %a --album %d --track %t --title %n --year %y --genre %g -b %b %w -o %m", "m4a"},|' \
		${WRKSRC}/src/gripcfg.c

.include <bsd.port.post.mk>
