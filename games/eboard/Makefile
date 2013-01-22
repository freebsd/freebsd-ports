# New ports collection makefile for:	eboard
# Date created:				22 June 2001
# Whom:					petef@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	eboard
PORTVERSION=	1.1.1
PORTREVISION=	4
CATEGORIES=	games
MASTER_SITES=	SF \
		SF/${PORTNAME}/eboard-extras/pack%201%20patchlevel%202/:p1 \
		SF/${PORTNAME}/eboard-extras/pack%202/:p2
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		eboard-extras-1pl2.tar.gz:p1 \
		eboard-extras-2.tar.gz:p2
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	johans@FreeBSD.org
COMMENT=	GTK+ chess board interface (mainly for FICS and chessd)

LIB_DEPENDS=	png15:${PORTSDIR}/graphics/png

EXTRAS=		1pl2 2
USE_BZIP2=	yes
HAS_CONFIGURE=	yes
USE_PERL5_BUILD=yes
USE_GNOME=	gtk20

CONFIGURE_ARGS=	--prefix=${PREFIX} \
		--extra-inc=${LOCALBASE}/include \
		--extra-ld=${LOCALBASE}/lib \
		--data-dir=${DATADIR} \
		--disable-dgt

INSTALL_TARGET=	install install-man

MAN1=	eboard-config.1 eboard-addtheme.1
MAN6=	eboard.6

OPTIONS_DEFINE=	JOYSTICK
JOYSTICK_DESC=	Enable joystick support

DESKTOP_ENTRIES="eboard" \
		"Play chess" \
		"${PREFIX}/share/pixmaps/eboard.xpm" \
		"eboard" \
		"Game;BoardGame;GTK;" \
		true

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MJOYSTICK}
BUILD_DEPENDS+=	${LOCALBASE}/include/linux/joystick.h:${PORTSDIR}/devel/linux-js
RUN_DEPENDS+=	${LOCALBASE}/include/linux/joystick.h:${PORTSDIR}/devel/linux-js
.endif

post-extract:
.for e in ${EXTRAS}
	@cd ${WRKDIR} && ${GZIP_CMD} -dc \
		${_DISTDIR}/eboard-extras-${e}.tar.gz | ${TAR} -xf -
.endfor

post-patch:
	@${REINPLACE_CMD} -e 's,g++,${CXX},' -e 's,-O6,${CXXFLAGS},' \
		${WRKSRC}/configure

.if empty(PORT_OPTIONS:MJOYSTICK)
post-configure:
	@${REINPLACE_CMD} -e '/^#define HAVE_LINUX_JOYSTICK_H 1/ d' \
		${WRKSRC}/config.h
.endif

post-install:
	${LN} -sf ${LOCALBASE}/bin/timeseal ${DATADIR}/timeseal.FreeBSD
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.for file in Crafty.txt FICS-Timeseal.txt GNUChess4.txt GNUChess5.txt \
	Scripts.txt Sjeng.txt Themes.txt
	${INSTALL_DATA} ${WRKSRC}/Documentation/${file} ${DOCSDIR}
.endfor
.endif
.for extra in ${EXTRAS}
	@cd ${WRKDIR}/eboard-extras-${extra} && EBOARDCONFIG=${PREFIX}/bin/eboard-config ./${CONFIGURE_SCRIPT} --prefix=${PREFIX}
	@cd ${WRKDIR}/eboard-extras-${extra} && ${SETENV} ${MAKE_ENV} ${MAKE} install
.endfor
	${MKDIR} ${PREFIX}/share/pixmaps
	${INSTALL_DATA} ${WRKSRC}/icon-eboard.xpm ${PREFIX}/share/pixmaps/eboard.xpm
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
