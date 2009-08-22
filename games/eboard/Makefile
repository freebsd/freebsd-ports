# New ports collection makefile for:	eboard
# Date created:				22 June 2001
# Whom:					petef@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	eboard
PORTVERSION=	1.1.1
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	SF
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} eboard-extras-1pl2.tar.gz eboard-extras-2.tar.gz
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	johans@stack.nl
COMMENT=	GTK+ chess board interface (mainly for FICS and chessd)

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

OPTIONS=	JOYSTICK "joystick support" off

DESKTOP_ENTRIES="eboard" \
		"Play chess" \
		"eboard.xpm" \
		"eboard" \
		"Application;Game;" \
		true

.include <bsd.port.pre.mk>

.if defined(WITH_JOYSTICK)
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

.if !defined(WITH_JOYSTICK)
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

.include <bsd.port.post.mk>
