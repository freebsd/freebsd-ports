PORTNAME=	fillets-ng
PORTVERSION=	1.0.1
PORTREVISION=	10
CATEGORIES=	games
MASTER_SITES=	SF/fillets/Fish%20Fillets%20-%20Next%20Generation/${PORTVERSION} \
		SF/fillets/Fish%20Fillets%20-%20Next%20Generation/${DATAVERSION}:data
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		${PORTNAME}-data-${DATAVERSION}${EXTRACT_SUFX}:data

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Wonderful puzzle game
WWW=		https://fillets.sourceforge.net/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

ONLY_FOR_ARCHS=	amd64 i386 powerpc powerpc64 powerpc64le

USES=		gmake lua:51 pkgconfig sdl
USE_CXXSTD=	c++14
USE_SDL=	sdl mixer image ttf

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share
CONFIGURE_ARGS=	--datadir="${DATADIR}"
CONFIGURE_ENV=	LUA_LIBS="-L${LUA_LIBDIR} -llua-${LUA_VER}" \
		LUA_CFLAGS="-I${LUA_INCDIR}"

DESKTOP_ENTRIES="Fish Fillets - Next Generation" \
		"" \
		"${DATADIR}/images/icon.png" \
		"fillets" \
		"Game;LogicGame;" \
		false

PLIST_FILES=	bin/fillets share/man/man6/fillets.6.gz
PORTDATA=	*
PORTDOCS=	*

OPTIONS_DEFINE=	DOCS FRIBIDI SMPEG X11
OPTIONS_DEFAULT=FRIBIDI SMPEG X11

SMPEG_DESC=		Video playback support
X11_DESC=		X11 window manager support

FRIBIDI_LIB_DEPENDS=	libfribidi.so:converters/fribidi
SMPEG_LIB_DEPENDS=	libsmpeg.so:multimedia/smpeg
X11_USES=		xorg
X11_USE=		xorg=x11
X11_CONFIGURE_ON=	--with-X=yes
X11_CONFIGURE_OFF=	--with-X=no
X11_LDFLAGS=		-L${LOCALBASE}/lib

DATAVERSION=	1.0.1

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
