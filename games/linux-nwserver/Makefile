# Created by: Igor Pokrovsky <tiamat@comset.net>
# $FreeBSD$

PORTNAME=	nwserver
PORTVERSION=	1.32
PORTREVISION=	3
CATEGORIES=	games linux
MASTER_SITES=	http://nwdownloads.bioware.com/neverwinternights/linux/${PORTVERSION:S/.//}/
PKGNAMEPREFIX=	linux-
DISTNAME=	linuxserver${PORTVERSION:S/.//}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Neverwinter Nights Linux Dedicated Server

OPTIONS_DEFINE=	DOCS

BROKEN=		unfetchable
DEPRECATED=	Broken for more than 6 months
EXPIRATION_DATE=	2016-07-04

USE_LINUX=	yes
ONLY_FOR_ARCHS=	i386 amd64
WRKSRC=		${WRKDIR}

SUB_FILES=	pkg-message

OPTIONS_DEFINE=	DOCS

do-build:
	${BRANDELF} -t Linux ${WRKDIR}/nwserver

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/fixinstall ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKDIR}/nwserver ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKDIR}/readme.linuxserver.txt ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
