# New ports collection makefile for:   icecast
# Version required:	1.1.4
# Date created:		28 Jan 1999
# Whom:			Chip Marshall <chip@eboai.org>
#
# $FreeBSD$
#

DISTNAME=	icecast-1.1.4
CATEGORIES=	audio net
MASTER_SITES=	http://icecast.linuxpower.org/releases/	\
		ftp://ftp.eboai.org/pub/icecast/

MAINTAINER=	chip@eboai.org

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-crypt --with-libwrap

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/icecast ${PREFIX}/sbin
	${INSTALL_PROGRAM} ${WRKSRC}/shout/listen ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/shout/shout ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/liveice/liveice ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/misc/iceplay ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/icecast
	${INSTALL_MAN} ${WRKSRC}/doc/* ${PREFIX}/share/doc/icecast
	${MKDIR} ${PREFIX}/share/examples/icecast
	${INSTALL_MAN} ${WRKSRC}/liveice/liveice.cfg ${PREFIX}/share/examples/icecast
	${INSTALL_MAN} ${WRKSRC}/shout/shoutrc.example ${PREFIX}/share/examples/icecast
	${INSTALL_MAN} ${WRKSRC}/shout/playlist.example ${PREFIX}/share/examples/icecast
	${INSTALL_MAN} ${WRKSRC}/shout/radio.tcl.example ${PREFIX}/share/examples/icecast
	${MKDIR} ${PREFIX}/share/examples/icecast/icedir
	${INSTALL_MAN} ${WRKSRC}/icedir/* ${PREFIX}/share/examples/icecast/icedir
.endif

.include <bsd.port.mk>
