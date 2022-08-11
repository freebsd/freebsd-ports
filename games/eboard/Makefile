PORTNAME=	eboard
PORTVERSION=	1.1.3
DISTVERSIONPREFIX=	v
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/eboard-extras/pack%201%20patchlevel%202/:p1 \
		SF/${PORTNAME}/eboard-extras/pack%202/:p2
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		eboard-extras-1pl2.tar.gz:p1 \
		eboard-extras-2.tar.gz:p2
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	rhurlin@FreeBSD.org
COMMENT=	GTK+ chess board interface (mainly for FICS and chessd)

LICENSE=	GPLv2

LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libpng.so:graphics/png

USES=		compiler:c++11-lang gnome gstreamer perl5 pkgconfig shebangfix tar:bzip2
USE_GITHUB=	yes
GH_ACCOUNT=	fbergo
USE_GNOME=	cairo gdkpixbuf2 gtk20
USE_PERL5=	build

SHEBANG_FILES=	configure

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX} \
		--extra-inc=${LOCALBASE}/include \
		--extra-ld=${LOCALBASE}/lib

INSTALL_TARGET=	install install-man

DESKTOP_ENTRIES="eboard" \
		"Play chess" \
		"${PREFIX}/share/pixmaps/eboard.xpm" \
		"eboard" \
		"Game;BoardGame;GTK;" \
		true

OPTIONS_DEFINE=	DOCS

EXTRAS=		1pl2 2

post-extract:
.for e in ${EXTRAS}
	@cd ${WRKDIR} && ${GZIP_CMD} -dc \
		${_DISTDIR}/eboard-extras-${e}.tar.gz | ${TAR} -xf -
.endfor

post-patch:
	@${REINPLACE_CMD} -e 's,g++,${CXX},' -e 's|-O6|${CXXFLAGS}|' \
		${WRKSRC}/configure

pre-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}

post-install:
# There is no timeseal port ATM :(
#	@${LN} -sf ${LOCALBASE}/bin/timeseal \
#		${STAGEDIR}${DATADIR}/timeseal.FreeBSD
.for extra in ${EXTRAS}
	@cd ${WRKDIR}/eboard-extras-${extra} && ${SETENV} EBOARDCONFIG=${STAGEDIR}${PREFIX}/bin/eboard-config ${CONFIGURE_CMD} --prefix=${PREFIX}
	@cd ${WRKDIR}/eboard-extras-${extra} && ${SETENV} ${MAKE_ENV} ${MAKE} install DATADIR=${STAGEDIR}${DATADIR}
.endfor

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}
.for file in Crafty.txt FICS-Timeseal.txt GNUChess4.txt GNUChess5.txt \
	Scripts.txt Sjeng.txt Themes.txt
	${INSTALL_DATA} ${WRKSRC}/Documentation/${file} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
