# New ports collection makefile for: TinyMUX
# Version required:	1.4p13
# Date created:		1998/05/28
# Whom:			cjohnson
#
# $Id$
#

DISTNAME=	tinymux-1.4p13
CATEGORIES=	games
MASTER_SITES=	ftp://ftp.digex.net/pub/mud/tinymux/

MAINTAINER=	cjohnson@camelot.com

BUILD_DEPENDS=	${PREFIX}/lib/libgdbm.a:${PORTSDIR}/databases/gdbm

WRKSRC=		${WRKDIR}/src
#GNU_CONFIGURE=	YES
USE_AUTOCONF=	YES

#
# Distribution does not include an install target.  So here it is.
do-install:
	${MKDIR} ${PREFIX}/games/tinymux
	${INSTALL_SCRIPT} ${WRKDIR}/game/Startmux ${PREFIX}/games/tinymux
	${INSTALL_DATA} ${WRKDIR}/game/alias.conf ${PREFIX}/games/tinymux
	${INSTALL_DATA} ${WRKDIR}/game/compat.conf ${PREFIX}/games/tinymux
	${INSTALL_DATA} ${WRKDIR}/game/mtrace.awk ${PREFIX}/games/tinymux
	${INSTALL_DATA} ${WRKDIR}/game/mux.config ${PREFIX}/games/tinymux
	${INSTALL_DATA} ${WRKDIR}/game/netmux.conf ${PREFIX}/games/tinymux
	${MKDIR} ${PREFIX}/games/tinymux/data
	${INSTALL_SCRIPT} ${WRKDIR}/game/data/db_check ${PREFIX}/games/tinymux/data
	${INSTALL_SCRIPT} ${WRKDIR}/game/data/db_load ${PREFIX}/games/tinymux/data
	${INSTALL_SCRIPT} ${WRKDIR}/game/data/db_unload ${PREFIX}/games/tinymux/data
	${MKDIR} ${PREFIX}/games/tinymux/text
	${INSTALL_DATA} ${WRKDIR}/game/text/badsite.txt ${PREFIX}/games/tinymux/text
	${INSTALL_DATA} ${WRKDIR}/game/text/connect.txt ${PREFIX}/games/tinymux/text
	${INSTALL_DATA} ${WRKDIR}/game/text/create_reg.txt ${PREFIX}/games/tinymux/text
	${INSTALL_DATA} ${WRKDIR}/game/text/down.txt ${PREFIX}/games/tinymux/text
	${INSTALL_DATA} ${WRKDIR}/game/text/full.txt ${PREFIX}/games/tinymux/text
	${INSTALL_DATA} ${WRKDIR}/game/text/guest.txt ${PREFIX}/games/tinymux/text
	${INSTALL_DATA} ${WRKDIR}/game/text/help.txt ${PREFIX}/games/tinymux/text
	${INSTALL_DATA} ${WRKDIR}/game/text/motd.txt ${PREFIX}/games/tinymux/text
	${INSTALL_DATA} ${WRKDIR}/game/text/news.txt ${PREFIX}/games/tinymux/text
	${INSTALL_DATA} ${WRKDIR}/game/text/newuser.txt ${PREFIX}/games/tinymux/text
	${INSTALL_DATA} ${WRKDIR}/game/text/plushelp.txt ${PREFIX}/games/tinymux/text
	${INSTALL_DATA} ${WRKDIR}/game/text/quit.txt ${PREFIX}/games/tinymux/text
	${INSTALL_DATA} ${WRKDIR}/game/text/register.txt ${PREFIX}/games/tinymux/text
	${INSTALL_DATA} ${WRKDIR}/game/text/wizhelp.txt ${PREFIX}/games/tinymux/text
	${INSTALL_DATA} ${WRKDIR}/game/text/wizmotd.txt ${PREFIX}/games/tinymux/text
	${INSTALL_DATA} ${WRKDIR}/game/text/wiznews.txt ${PREFIX}/games/tinymux/text
	${MKDIR} ${PREFIX}/games/tinymux/bin
#	${INSTALL_PROGRAM} ${WRKSRC}/conc ${PREFIX}/games/tinymux/bin
	${INSTALL_PROGRAM} ${WRKSRC}/dbconvert ${PREFIX}/games/tinymux/bin
	${INSTALL_PROGRAM} ${WRKSRC}/mkindx ${PREFIX}/games/tinymux/bin
	${INSTALL_PROGRAM} ${WRKSRC}/netmux ${PREFIX}/games/tinymux/bin
	${INSTALL_PROGRAM} ${WRKSRC}/slave ${PREFIX}/games/tinymux/bin
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/tinymux
	${INSTALL_DATA} ${WRKDIR}/README ${PREFIX}/share/doc/tinymux
	${INSTALL_DATA} ${WRKDIR}/README.COMPRESSION ${PREFIX}/share/doc/tinymux
	${INSTALL_DATA} ${WRKDIR}/README.GUESTS ${PREFIX}/share/doc/tinymux
	${INSTALL_DATA} ${WRKDIR}/README.MEMORY ${PREFIX}/share/doc/tinymux
	${INSTALL_DATA} ${WRKDIR}/README.TOOLS ${PREFIX}/share/doc/tinymux
.endif

.include <bsd.port.mk>
