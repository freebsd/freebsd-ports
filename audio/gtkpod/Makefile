# Created by: David Le Brun <david@dyn-ns.net>
# $FreeBSD$

PORTNAME=	gtkpod
PORTVERSION=	1.0.0
PORTREVISION=	4
CATEGORIES=	audio
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	GUI for Apple iPod using GTK2

LICENSE=	GPLv2

LIB_DEPENDS=	libid3tag.so:${PORTSDIR}/audio/libid3tag \
		libgpod.so:${PORTSDIR}/audio/libgpod

USES=		gettext gmake pkgconfig
NO_STAGE=	yes
USE_GNOME=	gtk20 libglade2
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
INSTALLS_ICONS=	yes

MAN1=		${PORTNAME}.1
PORTDOCS=	ChangeLog NEWS README TODOandBUGS.txt TROUBLESHOOTING

OPTIONS_DEFINE=	VORBIS FLAC CURL
OPTIONS_DEFAULT=	VORBIS FLAC CURL

CURL_DESC=	Cover art download support via libcurl

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MVORBIS}
LIB_DEPENDS+=	libvorbisfile.so:${PORTSDIR}/audio/libvorbis
.else
CONFIGURE_ARGS+=	--without-ogg
.endif

.if ${PORT_OPTIONS:MFLAC}
LIB_DEPENDS+=	libFLAC.so:${PORTSDIR}/audio/flac
.else
CONFIGURE_ARGS+=	--without-flac
.endif

.if ${PORT_OPTIONS:MCURL}
LIB_DEPENDS+=	libcurl.so:${PORTSDIR}/ftp/curl
.else
CONFIGURE_ARGS+=	--without-curl
.endif

post-patch:
# Install locale files correctly (to share dir instead of lib dir)
	@${REINPLACE_CMD} -e 's|DATADIRNAME=lib|DATADIRNAME=share|' \
		${WRKSRC}/configure
# FreeBSD does not have libdl
	@${REINPLACE_CMD} -e 's| -ldl||' ${WRKSRC}/src/Makefile.in
# Adjust location of <endian.h> header
	@${REINPLACE_CMD} -e 's|endian\.h|sys/&|' ${WRKSRC}/configure \
		${WRKSRC}/src/mp4file.c

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
