# Created by: Dmitry Marakasov <amdmi3@amdmi3.ru>
# $FreeBSD$

PORTNAME=	fillets-ng
PORTVERSION=	1.0.1
PORTREVISION=	8
CATEGORIES=	games
MASTER_SITES=	SF/fillets/Fish%20Fillets%20-%20Next%20Generation/${PORTVERSION} \
		SF/fillets/Fish%20Fillets%20-%20Next%20Generation/${DATAVERSION}:data
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		${PORTNAME}-data-${DATAVERSION}${EXTRACT_SUFX}:data

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Wonderful puzzle game

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

USE_SDL=	sdl mixer image ttf
USES=		gmake lua:51 pkgconfig sdl
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--datadir="${DATADIR}"
CONFIGURE_ENV=	LUA_LIBS="-L${LUA_LIBDIR} -llua-${LUA_VER}" \
		LUA_CFLAGS="-I${LUA_INCDIR}"

PLIST_FILES=	bin/fillets man/man6/fillets.6.gz

PORTDOCS=	*
PORTDATA=	*

DATAVERSION=	1.0.1

ONLY_FOR_ARCHS=	i386 amd64

DESKTOP_ENTRIES="Fish Fillets - Next Generation" \
		"" \
		"${DATADIR}/images/icon.png" \
		"fillets" \
		"Game;LogicGame;" \
		false

OPTIONS_DEFINE=	DOCS FRIBIDI SMPEG X11
OPTIONS_DEFAULT=FRIBIDI SMPEG X11

FRIBIDI_LIB_DEPENDS=	libfribidi.so:converters/fribidi
SMPEG_DESC=		Video playback support
SMPEG_LIB_DEPENDS=	libsmpeg.so:multimedia/smpeg
X11_DESC=		X11 window manager support
X11_USES=		xorg
X11_USE=		xorg=x11
X11_CONFIGURE_ON=	--with-X=yes
X11_CONFIGURE_OFF=	--with-X=no
X11_LDFLAGS=		-L${LOCALBASE}/lib

post-patch:
	@${REINPLACE_CMD} -e '/LIBS/ s|-llualib[50.]*||g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|^\(AM_CPPFLAGS.*(datadir)\)/.*|\1"\\"|' \
		${WRKSRC}/src/gengine/Makefile.in

post-patch-FRIBIDI-off:
	@${REINPLACE_CMD} -e '/have_fribidi="yes"/ s|yes|no|' ${WRKSRC}/configure

post-patch-SMPEG-off:
	@${REINPLACE_CMD} -e '/have_smpeg="yes"/ s|yes|no|' ${WRKSRC}/configure

post-install:
	cd ${WRKDIR}/${PORTNAME}-data-${DATAVERSION} && \
		${COPYTREE_SHARE} "font	images music script sound" ${STAGEDIR}${DATADIR}/

post-install-DOCS-on:
	cd ${WRKDIR}/${PORTNAME}-data-${DATAVERSION}/doc && \
		${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
