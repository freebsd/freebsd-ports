# New ports collection makefile for:	linux-ePSXe
# Date created:			21 Dec 2002
# Whom:				Jean-Yves Lefort <jylefort@brutele.be>
#
# $FreeBSD$
#

PORTNAME=	epsxe
PORTVERSION=	1.6.0
PORTREVISION=	1
CATEGORIES=	emulators linux
MASTER_SITES=	http://www.epsxe.com/files/
PKGNAMEPREFIX=	linux-
DISTNAME=	epsxe160lin

MAINTAINER=	jylefort@FreeBSD.org
COMMENT=	A Sony Playstation emulator (Linux version)

RUN_DEPENDS=	${LINUXBASE}/usr/lib/libgtk-1.2.so.0:${PORTSDIR}/x11-toolkits/linux-gtk

USE_LINUX=	8	# the epsxe binary is linked against glibc 2.3
USE_X_PREFIX=	yes
USE_ZIP=	yes
NO_WRKSUBDIR=	yes
NO_BUILD=	yes
ONLY_FOR_ARCHS=	i386

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
