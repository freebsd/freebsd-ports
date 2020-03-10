# Created by: kbyanc@posi.net
# $FreeBSD$

PORTNAME=	grip
PORTVERSION=	4.1.0
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	SF/grip/${PORTVERSION}

MAINTAINER=	freebsd-ports@jan0sch.de
COMMENT=	GTK front-end to external cd rippers and audio encoders

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libcurl.so:ftp/curl \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libid3.so:audio/id3lib \
		libpopt.so:devel/popt

USES=		compiler:c++11-lang gmake gnome libtool localbase \
		pathfix pkgconfig xorg gnome
USE_XORG=	ice sm x11 xext
USE_GNOME=	cairo gdkpixbuf2 gtk20

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--disable-werror
INSTALLS_ICONS=	yes

OPTIONS_DEFINE=	CDPARANOIA CDDA2WAV LAME VORBIS FAAC FLAC NLS
OPTIONS_DEFAULT=	CDPARANOIA FLAC VORBIS

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

.if defined(WITH_CDROM_DEVICE)
DEFAULT_CDROM_DEVICE=${WITH_CDROM_DEVICE}
.else
DEFAULT_CDROM_DEVICE=/dev/cd0
.endif

.include <bsd.port.pre.mk>

pre-everything::
.if !defined(WITH_CDROM_DEVICE)
	@${ECHO_MSG} "===> The default CDROM device is ${DEFAULT_CDROM_DEVICE}"
	@${ECHO_MSG} "===> Define WITH_CDROM_DEVICE if you want to change the default"
	@${ECHO_MSG} "===> For example, 'make WITH_CDROM_DEVICE=\"/dev/somedevice\"'"
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|/dev/cdrom|${DEFAULT_CDROM_DEVICE}|' \
		${WRKSRC}/src/grip.c
.if ${CHOSEN_COMPILER_TYPE} == gcc && ${COMPILER_VERSION} <= 42
	${REINPLACE_CMD} -e '/pragma/d' ${WRKSRC}/src/cdpar.c
.endif

.include <bsd.port.post.mk>
