PORTNAME=	grip
DISTVERSION=	4.2.4
PORTREVISION=	3
CATEGORIES=	audio
MASTER_SITES=	SF/grip/${DISTVERSION}

MAINTAINER=	freebsd-ports@jan0sch.de
COMMENT=	GTK front-end to external cd rippers and audio encoders
WWW=		https://sourceforge.net/projects/grip/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libcurl.so:ftp/curl \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libid3.so:audio/id3lib

USES=		compiler:c++11-lang gmake gnome libtool localbase \
		pkgconfig xorg
USE_GNOME=	cairo gdkpixbuf gtk20
USE_XORG=	ice sm x11 xext

GNU_CONFIGURE=		yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share
CONFIGURE_ARGS+=	--disable-werror

CONFLICTS_INSTALL=	py*-grip # bin/grip

OPTIONS_DEFINE=		CDDA2WAV CDPARANOIA FAAC FLAC LAME NLS VORBIS
OPTIONS_DEFAULT=	CDPARANOIA FLAC VORBIS

.if !defined(PACKAGE_BUILDING)
OPTIONS_DEFAULT+=	LAME
.endif

OPTIONS_SUB=	yes

CDDA2WAV_RUN_DEPENDS=		cdda2wav:sysutils/cdrtools
CDPARANOIA_LIB_DEPENDS=		libcdda_paranoia.so:audio/cdparanoia
CDPARANOIA_CONFIGURE_ENABLE=	cdpar
FAAC_RUN_DEPENDS=		faac:audio/faac
FLAC_RUN_DEPENDS=		flac:audio/flac
LAME_RUN_DEPENDS=		lame:audio/lame
VORBIS_RUN_DEPENDS=		ogg123:audio/vorbis-tools
NLS_USES=			gettext

.if defined(WITH_CDROM_DEVICE)
DEFAULT_CDROM_DEVICE=	${WITH_CDROM_DEVICE}
.else
DEFAULT_CDROM_DEVICE=	/dev/cd0
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

.include <bsd.port.mk>
