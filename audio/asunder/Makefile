# Created by: Fraser Tweedale <frase@frase.id.au>
# $FreeBSD$

PORTNAME=	asunder
PORTVERSION=	2.3
CATEGORIES=	audio
MASTER_SITES=	http://littlesvr.ca/asunder/releases/

MAINTAINER=	frase@frase.id.au
COMMENT=	Lightweight GTK+ CD ripper

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	cddb:${PORTSDIR}/audio/libcddb
RUN_DEPENDS=	${LOCALBASE}/bin/cdparanoia:${PORTSDIR}/audio/cdparanoia

OPTIONS_DEFINE=	LAME OGG FLAC OPUS WAVPACK APE WINDOWS_CHARS NLS DOCS
OPUS_DESC=	OPUS support
OPTIONS_DEFAULT=	LAME OGG FLAC

WINDOWS_CHARS_DESC=	Allow Windows special chars in filenames

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USES=		gettext
USE_GMAKE=	yes
USE_GNOME=	gtk20

PORTDOCS=	AUTHORS ChangeLog INSTALL NEWS README TODO

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MLAME}
RUN_DEPENDS+=	lame:${PORTSDIR}/audio/lame
.endif

.if ${PORT_OPTIONS:MOGG}
RUN_DEPENDS+=	oggenc:${PORTSDIR}/audio/vorbis-tools
.endif

.if ${PORT_OPTIONS:MFLAC}
RUN_DEPENDS+=	flac:${PORTSDIR}/audio/flac
.endif

.if ${PORT_OPTIONS:MOPUS}
RUN_DEPENDS+=	opusenc:${PORTSDIR}/audio/opus-tools
.endif

.if ${PORT_OPTIONS:MWAVPACK}
RUN_DEPENDS+=	wavpack:${PORTSDIR}/audio/wavpack
.endif

.if ${PORT_OPTIONS:MAPE}
RUN_DEPENDS+=	mac:${PORTSDIR}/audio/mac
.endif

.if ${PORT_OPTIONS:MNLS}
PLIST_SUB+=	NLS=''
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS='@comment '
.endif

post-patch:
	@${REINPLACE_CMD} -e 's/^itlocaledir = .*/itlocaledir = @datarootdir@\/locale/' ${WRKSRC}/po/Makefile.in.in
.if ${PORT_OPTIONS:MWINDOWS_CHARS}
	@${REINPLACE_CMD} -e 's^#define[[:blank:]]*BADCHARS.*^#define BADCHARS "/"^' ${WRKSRC}/src/util.h
.endif

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${DOCSDIR}/
.endif

.include <bsd.port.mk>
