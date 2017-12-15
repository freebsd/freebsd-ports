# Created by: kbyanc@posi.net
# $FreeBSD$
#    $MCom: ports/audio/grip/Makefile,v 1.4 2007/05/19 21:35:57 marcus Exp $

PORTNAME=	grip
PORTVERSION=	3.6.1
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	SF/grip/${PORTVERSION}

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	GTK front-end to external cd rippers and audio encoders

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libcurl.so:ftp/curl \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libid3.so:audio/id3lib \
		libpopt.so:devel/popt

USES=		gmake libtool pathfix pkgconfig
USE_XORG=	ice sm x11 xext
USE_GNOME=	cairo gdkpixbuf2 gnomeprefix libgnomeui vte
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--disable-werror
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

OPTIONS_DEFINE=	CDPARANOIA CDDA2WAV LAME VORBIS FAAC FLAC NLS
OPTIONS_DEFAULT=	CDPARANOIA VORBIS

.if !defined(PACKAGE_BUILDING)
OPTIONS_DEFAULT+=	LAME
.endif

OPTIONS_SUB=	yes

CDPARANOIA_LIB_DEPENDS=	libcdda_paranoia.so:audio/cdparanoia
CDPARANOIA_CONFIGURE_ENABLE=	cdpar
CDDA2WAV_RUN_DEPENDS=	cdda2wav:sysutils/cdrtools
FAAC_RUN_DEPENDS=	faac:audio/faac
FLAC_RUN_DEPENDS=	flac:audio/flac
LAME_RUN_DEPENDS=	lame:audio/lame
VORBIS_RUN_DEPENDS=	ogg123:audio/vorbis-tools
NLS_USES=	gettext
NLS_CONFIGURE_OFF=	--disable-nls

.if defined(WITH_CDROM_DEVICE)
DEFAULT_CDROM_DEVICE=${WITH_CDROM_DEVICE}
.else
DEFAULT_CDROM_DEVICE=/dev/cd0
.endif

pre-everything:
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
