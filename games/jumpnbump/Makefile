# New ports collection makefile for:	jumpnbump
# Date created:				23 September 2002
# Whom:					Alessandro Gatti <a.gatti@tiscali.it>
#
# $FreeBSD$
#

PORTNAME=	jumpnbump
PORTVERSION=	1.41
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	http://www.jumpbump.mine.nu/port/ \
	http://www.vlaadworld.net/jumpnbump/ \
	http://jumpnbump.linuxsys.de/

MAINTAINER=	gurkan@linuks.mine.nu
COMMENT=	A fun multiplayer game with cute fluffy bunnies and bloody explosions

USE_SDL=	mixer sdl

.if !defined (WITHOUT_TCL)
RUN_DEPENDS+=	wish8.0:${PORTSDIR}/x11-toolkits/tk80
PLIST_SUB +=	WITH_TCL=""
.else
PLIST_SUB +=	WITH_TCL="@comment "
.endif

MAN6=	jumpnbump.6

.include <bsd.port.pre.mk>

.if ${ARCH} == "alpha"
BROKEN=		"Does not compile on alpha"
.endif

.if !defined (WITHOUT_TCL)
pre-everything::
	@${ECHO_MSG} "Define WITHOUT_TCL to disable the X11 frontend."
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/jumpnbump ${PREFIX}/bin/
	${INSTALL_PROGRAM} ${WRKSRC}/gobpack ${PREFIX}/bin/
	${INSTALL_PROGRAM} ${WRKSRC}/jnbpack ${PREFIX}/bin/
	${INSTALL_PROGRAM} ${WRKSRC}/jnbunpack ${PREFIX}/bin/
	${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/data/jumpbump.dat ${DATADIR}/
.if !defined(WITHOUT_TCL)
	${INSTALL_SCRIPT} ${WRKSRC}/jnbmenu.tcl ${PREFIX}/bin/jnbmenu
.endif
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/jumpnbump.6 ${MANPREFIX}/man/man6/
	${INSTALL_MAN} ${WRKSRC}/jumpnbump.html ${DOCSDIR}
.for i in jumpnbump_levelmaking.htm level.pcx making1.gif making2.gif \
	making3.gif pack.gif
	${INSTALL_MAN} ${WRKSRC}/levelmaking/$i ${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>
