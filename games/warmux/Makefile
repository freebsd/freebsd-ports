# Created by: Anton Yudin <toha@FreeBSD.org>
# $FreeBSD$

PORTNAME=	warmux
DISTVERSION=	11.04.1
PORTREVISION=	7
CATEGORIES=	games
MASTER_SITES=	http://download.gna.org/${PORTNAME}/ \
		http://download.gna.org/${PORTNAME}/archive/

MAINTAINER=	makc@FreeBSD.org
COMMENT=	Turn-based artillery game with free software mascots

LIB_DEPENDS=	libxml++-2.6.so:${PORTSDIR}/textproc/libxml++26 \
		libcurl.so:${PORTSDIR}/ftp/curl

CONFLICTS_INSTALL=	wormux-*

GNU_CONFIGURE=	yes
USES=		dos2unix gmake pkgconfig tar:bzip2
USE_SDL=	sdl image mixer ttf gfx net
DOS2UNIX_GLOB=	fixed_class.h

OPTIONS_DEFINE=	FRIBIDI SERVER NLS DEBUG
FRIBIDI_DESC=	Enable bi-directional unicode support
SERVER_DESC=	Enable dedicated server

WRKSRC=		${WRKDIR}/${PORTNAME}-${DISTVERSION:R}

.include <bsd.port.options.mk>

post-patch:
	${REINPLACE_CMD} -e "s,-Werror,," ${WRKSRC}/Makefile.in \
	${WRKSRC}/src/Makefile.in ${WRKSRC}/configure
	${REINPLACE_CMD} -e "s,warmux_files.desktop,," ${WRKSRC}/data/Makefile.in
	${FIND} -d ${WRKSRC}/data/ -name "*.*~" -delete

.if ${PORT_OPTIONS:MDEBUG}
CONFIGURE_ARGS+=	--enable-debug \
			--enable-logging
.endif

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
PLIST_SUB+=	NLS=""
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

.if ${PORT_OPTIONS:MSERVER}
PLIST_SUB+=	SERVER=""
CONFIGURE_ARGS+=	--enable-servers
.else
PLIST_SUB+=	SERVER="@comment "
.endif

.if ${PORT_OPTIONS:MFRIBIDI}
LIB_DEPENDS+=	libfribidi.so:${PORTSDIR}/converters/fribidi
CONFIGURE_ARGS+=	--enable-fribidi
.else
CONFIGURE_ARGS+=	--disable-fribidi
.endif

.include <bsd.port.mk>
