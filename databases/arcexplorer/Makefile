# New ports collection makefile for:	arcexplorer
# Date created:				09 July 2002
# Whom:					Chris D. Faulhaber <jedgar@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	arcexplorer
PORTVERSION=	4.0
CATEGORIES=	databases java
MASTER_SITES=	#
DISTNAME=	Linux_ArcExplorer${PORTVERSION}
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	jedgar@FreeBSD.org
COMMENT=	Lightweight java-based GIS data viewer

USE_JAVA=	1.2+

DOWNLOAD_URL=	http://www.esri.com/software/arcexplorer/download4.html
NO_BUILD=	yes
NO_BUILD_DEPENDS_JAVA= yes
USE_REINPLACE=	yes
WRKSRC=		${WRKDIR}/ArcExplorer${PORTVERSION}

.include <bsd.port.pre.mk>

.if !exists(${DISTDIR}/${DISTNAME}${EXTRACT_SUFX})
IGNORE=You must manually fetch the ArcExplorer 4.0 tarball (${DISTNAME}${EXTRACT_SUFX}) from ${DOWNLOAD_URL}, place it in ${DISTDIR} and then run make again
.endif

do-install:
	${TAR} -xvf ${WRKSRC}/02.tar -C ${PREFIX}/lib
	@${CHOWN} -R ${BINOWN}:${BINGRP} ${PREFIX}/lib/aej40exe
	@${REINPLACE_CMD} -e 's|/bin/ksh|/bin/sh|' \
		${PREFIX}/lib/aej40exe/bin/aejava
	@${RM} ${PREFIX}/lib/aej40exe/bin/aejava.bak

post-install:
	@${ECHO_CMD}
	@${CAT} ${PKGMESSAGE} | ${SED} -e 's|%%PREFIX%%|${PREFIX}|'
	@${ECHO_CMD}

.include <bsd.port.post.mk>
