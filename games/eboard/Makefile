# New ports collection makefile for:	eboard
# Date created:				22 June 2001
# Whom:					petef@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	eboard
PORTVERSION=	0.9.5
PORTREVISION=	4
EXTRAS=		1pl2 2
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} eboard-extras-1pl2.tar.gz eboard-extras-2.tar.gz

MAINTAINER=	jylefort@FreeBSD.org
COMMENT=	GTK+ chess board interface (mainly for FICS and chessd)

HAS_CONFIGURE=	yes
USE_GNOME=	imlib
USE_X_PREFIX=	yes

CONFIGURE_ARGS=	--prefix=${PREFIX} --extra-inc=${LOCALBASE}/include:${X11BASE}/include --extra-ld=${LOCALBASE}/lib:${X11BASE}/lib

INSTALL_TARGET=	install install-man

MAN1=	eboard-config.1 eboard-addtheme.1
MAN6=	eboard.6

DESKTOP_ENTRIES="eboard" \
		"Play chess" \
		"eboard.xpm" \
		"eboard" \
		"Application;Game;" \
		false

post-patch:
	@${REINPLACE_CMD} -e 's,g++,${CXX},' -e 's,-O6,${CXXFLAGS},' \
		${WRKSRC}/configure

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
	@cd ${WRKDIR}/eboard-extras-${extra} && ./${CONFIGURE_SCRIPT} --prefix=${PREFIX}
	@cd ${WRKDIR}/eboard-extras-${extra} && ${SETENV} ${MAKE_ENV} ${MAKE} install
.endfor
	${MKDIR} ${PREFIX}/share/pixmaps
	${INSTALL_DATA} ${WRKSRC}/icon-eboard.xpm ${PREFIX}/share/pixmaps/eboard.xpm
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
