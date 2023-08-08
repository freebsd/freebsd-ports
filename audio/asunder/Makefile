PORTNAME=	asunder
PORTVERSION=	2.9.6
PORTREVISION=	3
CATEGORIES=	audio
MASTER_SITES=	http://littlesvr.ca/asunder/releases/

MAINTAINER=	frase@frase.id.au
COMMENT=	Lightweight GTK+ CD ripper
WWW=		http://littlesvr.ca/asunder/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libcddb.so:audio/libcddb \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libharfbuzz.so:print/harfbuzz

RUN_DEPENDS=	${LOCALBASE}/bin/cdparanoia:audio/cdparanoia

USES=		compiler:c11 desktop-file-utils gettext gmake gnome pkgconfig \
		tar:bzip2
USE_GNOME=	cairo gdkpixbuf2 gtk20 glib20 intltool intlhack

GNU_CONFIGURE=	yes

PORTDOCS=	AUTHORS ChangeLog INSTALL NEWS README TODO

OPTIONS_DEFINE=	LAME OGG FLAC OPUS WAVPACK APE WINDOWS_CHARS NLS DOCS
OPTIONS_DEFAULT=	OGG FLAC
OPTIONS_SUB=	yes

WINDOWS_CHARS_DESC=	Allow Windows special chars in filenames

APE_RUN_DEPENDS=	mac:audio/mac
FLAC_RUN_DEPENDS=	flac:audio/flac
LAME_RUN_DEPENDS=	lame:audio/lame
NLS_CONFIGURE_ENABLE=	yes
OGG_RUN_DEPENDS=	oggenc:audio/vorbis-tools
OPUS_RUN_DEPENDS=	opusenc:audio/opus-tools
WAVPACK_RUN_DEPENDS=	wavpack:audio/wavpack

.include <bsd.port.pre.mk>

.if ${OPSYS} == FreeBSD && ( ${OSVERSION} >= 1400079 || ( ${OSVERSION} >= 1302505 && ${OSVERSION} < 1400000 ))
CFLAGS+=	-Wno-error=int-conversion
.endif

post-patch-WINDOWS_CHARS-on:
	@${REINPLACE_CMD} -e 's^#define[[:blank:]]*BADCHARS.*^#define BADCHARS "/"^' ${WRKSRC}/src/util.h

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.post.mk>
