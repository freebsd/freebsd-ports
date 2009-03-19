# New ports collection makefile for:	linux-ePSXe
# Date created:			21 Dec 2002
# Whom:				Jean-Yves Lefort <jylefort@brutele.be>
#
# $FreeBSD$
#

PORTNAME=	epsxe
PORTVERSION=	1.6.0
PORTREVISION=	3
CATEGORIES=	emulators linux
MASTER_SITES=	http://www.epsxe.com/files/
PKGNAMEPREFIX=	linux-
DISTNAME=	epsxe160lin

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A Sony Playstation emulator (Linux version)

USE_LINUX=	yes
USE_LINUX_APPS=	gtk xorglibs
USE_ZIP=	yes
NO_WRKSUBDIR=	yes
NO_BUILD=	yes
ONLY_FOR_ARCHS=	i386 amd64

SUB_FILES=	epsxe-wrapper

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/epsxe-wrapper ${PREFIX}/bin/epsxe
	${INSTALL_PROGRAM} ${WRKSRC}/epsxe ${PREFIX}/libexec

	${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/keycodes.lst ${DATADIR}

	${MKDIR} ${DATADIR}/cheats
	${INSTALL_DATA} ${WRKSRC}/cheats/* ${DATADIR}/cheats

.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/* ${DOCSDIR}
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
