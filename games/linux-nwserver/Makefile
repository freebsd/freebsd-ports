# New ports collection makefile for:	linux-nwserver
# Date created:		22 July 2002
# Whom:			Igor Pokrovsky <tiamat@telegraph.spb.ru>
#
# $FreeBSD$
#

PORTNAME=	nwserver
PORTVERSION=	1.30
CATEGORIES=	games linux
MASTER_SITES=	http://nwdownloads.bioware.com/neverwinternights/linux/${PORTVERSION:S/.//}/
PKGNAMEPREFIX=	linux-
DISTNAME=	linuxserver${PORTVERSION:S/.//}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Neverwinter Nights Linux (x86) Dedicated Server

USE_LINUX=	yes
NO_BUILD=	yes
ONLY_FOR_ARCHS=	i386
WRKSRC=		${WRKDIR}

# Linux binary should not be stripped by INSTALL_PROGRAM
# because as a side effect it brands the binary as FreeBSD.
STRIP=

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/fixinstall ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKDIR}/nwserver ${PREFIX}/bin

.ifndef (NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKDIR}/readme.linuxserver.txt ${DOCSDIR}
.endif

post-install:
	@${ECHO} "*******************************************************************************"
	@${ECHO} "Neverwinter Nights Dedicated Server requires original game data to run."
	@${ECHO} "Consult ${DOCSDIR}/readme.linuxserver.txt"
	@${ECHO} "for more information about required data directories."
	@${ECHO} "From directory, where you will have installed game data you can run:"
	@${ECHO} "${PREFIX}/bin/fixinstall - to check installation (FAILED nwserver is ok)"
	@${ECHO} "and ${PREFIX}/bin/nwserver - to start server"
	@${ECHO} "*******************************************************************************"

.include <bsd.port.mk>
