# Created by: petef@FreeBSD.org
# $FreeBSD$

PORTNAME=	eboard
PORTVERSION=	1.1.1
PORTREVISION=	7
CATEGORIES=	games
MASTER_SITES=	SF \
		SF/${PORTNAME}/eboard-extras/pack%201%20patchlevel%202/:p1 \
		SF/${PORTNAME}/eboard-extras/pack%202/:p2
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		eboard-extras-1pl2.tar.gz:p1 \
		eboard-extras-2.tar.gz:p2
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GTK+ chess board interface (mainly for FICS and chessd)

LIB_DEPENDS=	libpng.so:graphics/png

EXTRAS=		1pl2 2
USES=		compiler:c++11-lang gnome perl5 pkgconfig shebangfix tar:bzip2
HAS_CONFIGURE=	yes
USE_PERL5=	build
USE_GNOME=	gtk20
SHEBANG_FILES=	configure

CONFIGURE_ARGS=	--prefix=${PREFIX} \
		--extra-inc=${LOCALBASE}/include \
		--extra-ld=${LOCALBASE}/lib

INSTALL_TARGET=	install install-man

OPTIONS_DEFINE=	JOYSTICK DOCS
JOYSTICK_DESC=	Enable joystick support
JOYSTICK_BUILD_DEPENDS=	${LOCALBASE}/include/linux/joystick.h:devel/evdev-proto

DESKTOP_ENTRIES="eboard" \
		"Play chess" \
		"${PREFIX}/share/pixmaps/eboard.xpm" \
		"eboard" \
		"Game;BoardGame;GTK;" \
		true

.include <bsd.port.options.mk>

post-extract:
.for e in ${EXTRAS}
	@cd ${WRKDIR} && ${GZIP_CMD} -dc \
		${_DISTDIR}/eboard-extras-${e}.tar.gz | ${TAR} -xf -
.endfor

post-patch:
	@${REINPLACE_CMD} -e 's,g++,${CXX},' -e 's|-O6|${CXXFLAGS}|' \
		${WRKSRC}/configure

.if empty(PORT_OPTIONS:MJOYSTICK)
post-configure:
	@${REINPLACE_CMD} -e '/^#define HAVE_LINUX_JOYSTICK_H 1/ d' \
		${WRKSRC}/config.h
.endif

post-install:
	@${LN} -sf ${LOCALBASE}/bin/timeseal \
		${STAGEDIR}${DATADIR}/timeseal.FreeBSD
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}
.for file in Crafty.txt FICS-Timeseal.txt GNUChess4.txt GNUChess5.txt \
	Scripts.txt Sjeng.txt Themes.txt
	${INSTALL_DATA} ${WRKSRC}/Documentation/${file} ${STAGEDIR}${DOCSDIR}
.endfor
.endif
.for extra in ${EXTRAS}
	@cd ${WRKDIR}/eboard-extras-${extra} && ${SETENV} EBOARDCONFIG=${STAGEDIR}${PREFIX}/bin/eboard-config ${CONFIGURE_CMD} --prefix=${PREFIX}
	@cd ${WRKDIR}/eboard-extras-${extra} && ${SETENV} ${MAKE_ENV} ${MAKE} install DATADIR=${STAGEDIR}${DATADIR}
.endfor
	@${INSTALL_DATA} ${WRKSRC}/icon-eboard.xpm ${STAGEDIR}${PREFIX}/share/pixmaps/eboard.xpm

.include <bsd.port.mk>
