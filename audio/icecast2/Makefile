# New ports collection makefile for:   icecast
# Date created:		28 Jan 1999
# Whom:			Chip Marshall <chip@eboai.org>
#
# $FreeBSD$
#

PORTNAME=	icecast
PORTVERSION=	1.3.0
CATEGORIES=	audio net
MASTER_SITES=	http://www.icecast.org/releases/	\
		ftp://ftp.eboai.org/pub/icecast/

MAINTAINER=	chip@eboai.org

WRKSRC=		${WRKDIR}/icecast-1.3

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-libwrap

ALL_TARGET=	all mkpasswd

post-extract:
	@( cd ${WRKSRC}; ${RM} -f shout/calibrate shout/stresstest )

post-configure:
	@${MAKE} WRKSRC=${WRKSRC}/liveice do-configure

post-build:
	@${MAKE} WRKSRC=${WRKSRC}/liveice ALL_TARGET=all do-build

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/icecast ${PREFIX}/sbin
	${INSTALL_PROGRAM} ${WRKSRC}/mkpasswd ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/shout/listen ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/shout/shout ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/shout/calibrate ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/shout/stresstest ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/liveice/liveice ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/shout/iceplay ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/icecast
	${INSTALL_MAN} ${WRKSRC}/doc/* ${PREFIX}/share/doc/icecast
	${INSTALL_MAN} ${WRKSRC}/liveice/README.liveice ${PREFIX}/share/doc/icecast
	${INSTALL_MAN} ${WRKSRC}/liveice/README.xingmp3enc ${PREFIX}/share/doc/icecast
	${INSTALL_MAN} ${WRKSRC}/liveice/README_new_mixer.txt ${PREFIX}/share/doc/icecast
	${MKDIR} ${PREFIX}/share/examples/icecast
	${INSTALL_MAN} ${WRKSRC}/icecast.conf ${PREFIX}/share/examples/icecast
	${INSTALL_MAN} ${WRKSRC}/liveice/liveice.cfg ${PREFIX}/share/examples/icecast
	${INSTALL_MAN} ${WRKSRC}/shout/shoutrc.example ${PREFIX}/share/examples/icecast
	${INSTALL_MAN} ${WRKSRC}/shout/playlist.example ${PREFIX}/share/examples/icecast
	${INSTALL_MAN} ${WRKSRC}/shout/radio.tcl.example ${PREFIX}/share/examples/icecast
	${MKDIR} ${PREFIX}/share/examples/icecast/icedir
	${INSTALL_MAN} ${WRKSRC}/icedir/* ${PREFIX}/share/examples/icecast/icedir
	${MKDIR} ${PREFIX}/share/examples/icecast/templates
	${INSTALL_MAN} ${WRKSRC}/templates/* ${PREFIX}/share/examples/icecast/templates
	${INSTALL_MAN} ${WRKSRC}/liveice/frontend.tcl ${PREFIX}/share/examples/icecast
	${INSTALL_MAN} ${WRKSRC}/liveice/liveiceconfigure.tk ${PREFIX}/share/examples/icecast
.endif
	@${CAT} ${PKGDIR}/MESSAGE

.include <bsd.port.mk>
