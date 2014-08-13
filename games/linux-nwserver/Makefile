# Created by: Igor Pokrovsky <tiamat@comset.net>
# $FreeBSD: head/games/linux-nwserver/Makefile 351187 2014-04-13 07:51:57Z xmj $

PORTNAME=	nwserver
PORTVERSION=	1.32
PORTREVISION=	3
CATEGORIES=	games linux
MASTER_SITES=	http://nwdownloads.bioware.com/neverwinternights/linux/${PORTVERSION:S/.//}/
PKGNAMEPREFIX=	linux-
DISTNAME=	linuxserver${PORTVERSION:S/.//}

MAINTAINER=	ports@freebsd.org
COMMENT=	Neverwinter Nights Linux Dedicated Server

OPTIONS_DEFINE=	DOCS

USE_LINUX=	yes
ONLY_FOR_ARCHS=	i386 amd64
WRKSRC=		${WRKDIR}

.include <bsd.port.options.mk>

do-build:
	${BRANDELF} -t Linux ${WRKDIR}/nwserver

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/fixinstall ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKDIR}/nwserver ${STAGEDIR}${PREFIX}/bin

.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKDIR}/readme.linuxserver.txt ${STAGEDIR}${DOCSDIR}
.endif

post-install:
	@${ECHO_MSG} "*******************************************************************************"
	@${ECHO_MSG} "Neverwinter Nights Dedicated Server requires original game data to run."
	@${ECHO_MSG} "Consult ${DOCSDIR}/readme.linuxserver.txt"
	@${ECHO_MSG} "for more information about required data directories."
	@${ECHO_MSG} "From directory, where you will have installed game data you can run:"
	@${ECHO_MSG} "${PREFIX}/bin/fixinstall - to check installation"
	@${ECHO_MSG} "and ${PREFIX}/bin/nwserver - to start server"
	@${ECHO_MSG} "*******************************************************************************"

.include <bsd.port.mk>
