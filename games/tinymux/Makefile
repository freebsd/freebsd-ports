# New ports collection makefile for:	TinyMUX
# Date created:		1998/05/28
# Whom:			cjohnson
#
# $FreeBSD$
#

PORTNAME=	tinymux
PORTVERSION=	1.6p0
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	http://www.moosh.net/pub/mush/servers/tinymux/TinyMUX-1.x/

MAINTAINER=	ports@FreeBSD.org

PORTCOMMENT=	A Multi-Player FreeForm adventure Program

LIB_DEPENDS=	gdbm.2:${PORTSDIR}/databases/gdbm

WRKSRC=		${WRKDIR}/src

USE_REINPLACE=	yes
USE_AUTOCONF=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"

post-extract:
	@${RM} -f ${WRKSRC}/gdbm.h

post-patch:
	@${REINPLACE_CMD} -e 's,<malloc.h>,<stdlib.h>,' ${WRKSRC}/udb_ochunk.c

#
# Distribution does not include an install target.  So here it is.
do-install:
	${MKDIR} ${PREFIX}/games/tinymux
	${INSTALL_SCRIPT} ${WRKDIR}/game/Startmux ${PREFIX}/games/tinymux
.for file in alias.conf compat.conf mtrace.awk mux.config netmux.conf
	${INSTALL_DATA} ${WRKDIR}/game/${file} ${PREFIX}/games/tinymux
.endfor
	${MKDIR} ${PREFIX}/games/tinymux/data
.for file in db_check db_load db_unload
	${INSTALL_SCRIPT} ${WRKDIR}/game/data/${file} \
		${PREFIX}/games/tinymux/data
.endfor
	${MKDIR} ${PREFIX}/games/tinymux/text
.for file in badsite connect create_reg down full guest help motd \
	news newuser plushelp quit register wizhelp wizmotd wiznews
	${INSTALL_DATA} ${WRKDIR}/game/text/${file}.txt \
		${PREFIX}/games/tinymux/text
.endfor
	${MKDIR} ${PREFIX}/games/tinymux/bin
#	${INSTALL_PROGRAM} ${WRKSRC}/conc ${PREFIX}/games/tinymux/bin
.for file in dbconvert mkindx netmux slave
	${INSTALL_PROGRAM} ${WRKSRC}/${file} ${PREFIX}/games/tinymux/bin
.endfor
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/tinymux
.for file in README README.COMPRESSION README.GUESTS README.MEMORY \
	README.TOOLS
	${INSTALL_DATA} ${WRKDIR}/${file} ${PREFIX}/share/doc/tinymux
.endfor
.endif

.include <bsd.port.mk>
