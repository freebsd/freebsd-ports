# New ports collection makefile for:   icecast
# Version required:	1.1.0
# Date created:		28 Jan 1999
# Whom:			Chip Marshall <chip@eboai.org>
#
# $Id$
#

DISTNAME=	icecast-1.1.0
CATEGORIES=	audio net
MASTER_SITES=	http://icecast.linuxpower.org/releases/	\
		ftp://ftp.eboai.org/pub/icecast/

MAINTAINER=	chip@eboai.org

GNU_CONFIGURE=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/icecast ${PREFIX}/sbin
	${INSTALL_PROGRAM} ${WRKSRC}/iceplay/listen ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/iceplay/shout ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/iceplay/iceplay ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/icecast
	${INSTALL_MAN} ${WRKSRC}/doc/* ${PREFIX}/share/doc/icecast
	${MKDIR} ${PREFIX}/share/examples/icecast
	${INSTALL_MAN} ${WRKSRC}/iceplay/shoutrc.example ${PREFIX}/share/examples/icecast
	${INSTALL_MAN} ${WRKSRC}/iceplay/playlist.example ${PREFIX}/share/examples/icecast
	${INSTALL_MAN} ${WRKSRC}/iceplay/radio.tcl.example ${PREFIX}/share/examples/icecast
	${MKDIR} ${PREFIX}/share/examples/icecast/icedir
	${INSTALL_MAN} ${WRKSRC}/icedir/* ${PREFIX}/share/examples/icecast/icedir
.endif

.include <bsd.port.mk>
