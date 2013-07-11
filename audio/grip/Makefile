# Created by: kbyanc@posi.net
# $FreeBSD$
#    $MCom: ports/audio/grip/Makefile,v 1.4 2007/05/19 21:35:57 marcus Exp $

PORTNAME=	grip
PORTVERSION=	3.3.1
PORTREVISION=	6
CATEGORIES=	audio
MASTER_SITES=	SF

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	GTK front-end to external cd rippers and audio encoders

LIB_DEPENDS=	id3-3.8.3:${PORTSDIR}/audio/id3lib \
		curl:${PORTSDIR}/ftp/curl

USE_XORG=	x11
USES=		pathfix pkgconfig
USE_GNOME=	gnomeprefix libgnomeui vte
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

OPTIONS_DEFINE=	CDPARANOIA CDDA2WAV LAME VORBIS FAAC FLAC NLS
OPTIONS_DEFAULT=	CDPARANOIA VORBIS

.if !defined(PACKAGE_BUILDING)
OPTIONS_DEFAULT+=	LAME
.endif

OPTIONS_SUB=	yes

CDPARANOIA_LIB_DEPENDS=	cdda_paranoia:${PORTSDIR}/audio/cdparanoia
CDPARANOIA_CONFIGURE_ENABLE=	cdpar
CDDA2WAV_RUN_DEPENDS=	cdda2wav:${PORTSDIR}/sysutils/cdrtools
FAAC_RUN_DEPENDS=	faac:${PORTSDIR}/audio/faac
FLAC_RUN_DEPENDS=	flac:${PORTSDIR}/audio/flac
LAME_RUN_DEPENDS=	lame:${PORTSDIR}/audio/lame
VORBIS_RUN_DEPENDS=	ogg123:${PORTSDIR}/audio/vorbis-tools
NLS_USES=	gettext
NLS_CONFIGURE_OFF=	--disable-nls

.if defined(WITH_CDROM_DEVICE)
DEFAULT_CDROM_DEVICE=${WITH_CDROM_DEVICE}
.else
DEFAULT_CDROM_DEVICE=/dev/acd0
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

.include <bsd.port.mk>
