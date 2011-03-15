# New ports collection makefile for:	gtkpod
# Date created: 			28 January 2003
# Whom: 				David Le Brun <david@dyn-ns.net>
#
# $FreeBSD$
#

PORTNAME=	gtkpod
PORTVERSION=	1.0.0
CATEGORIES=	audio
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	GUI for Apple iPod using GTK2

LICENSE=	GPLv2

LIB_DEPENDS=	id3tag.0:${PORTSDIR}/audio/libid3tag \
		gpod.7:${PORTSDIR}/audio/libgpod

USE_GETTEXT=	yes
USE_GMAKE=	yes
USE_GNOME=	gtk20 libglade2
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" LDFLAGS="-L${LOCALBASE}/lib"
INSTALLS_ICONS=	yes
MAN1=		gtkpod.1

PORTDOCS=	ChangeLog NEWS README TODOandBUGS.txt TROUBLESHOOTING

OPTIONS=	VORBIS	"Enable Ogg/Vorbis support"		on \
		FLAC	"Enable FLAC support"			on \
		CURL	"Enable coverart download support"	on

.include <bsd.port.pre.mk>

.if defined(WITH_VORBIS)
LIB_DEPENDS+=	vorbisfile.6:${PORTSDIR}/audio/libvorbis
.else
CONFIGURE_ARGS+=	--without-ogg
.endif

.if defined(WITH_FLAC)
LIB_DEPENDS+=	FLAC.10:${PORTSDIR}/audio/flac
.else
CONFIGURE_ARGS+=	--without-flac
.endif

.if defined(WITH_CURL)
LIB_DEPENDS+=	curl.6:${PORTSDIR}/ftp/curl
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
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
