# New ports collection makefile for:	MrSID
# Date created:				31 July 2002
# Whom:					Chris D. Faulhaber <jedgar@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	mrsidviewer
PORTVERSION=	2.0.32
CATEGORIES=	graphics linux
MASTER_SITES=	#
DISTNAME=	MrSID_linux${PORTVERSION}
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	jedgar@FreeBSD.org
COMMENT=	MrSID Viewer displays images compressed into the MrSID format

DOWNLOAD_URL=	http://www.lizardtech.com/includes/down.php?p=16&o=4
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/MrSID_linux${PORTVERSION}

.include <bsd.port.pre.mk>

.if !exists(${DISTDIR}/${DISTNAME}${EXTRACT_SUFX})
IGNORE=You must manually fetch the MrSID ${PORTVERSION} tarball (${DISTNAME}${EXTRACT_SUFX}) from ${DOWNLOAD_URL}, place it in ${DISTDIR} and then run make again
.endif

do-install:
	${CP} -Rv ${WRKSRC} ${PREFIX}/lib
	@${CHOWN} -R ${BINOWN}:${BINGRP} ${PREFIX}/lib/MrSID_linux${PORTVERSION}

post-install:
	@${ECHO_CMD}
	@${CAT} ${PKGMESSAGE} | ${SED} -e 's|%%PREFIX%%|${PREFIX}|'
	@${ECHO_CMD}

.include <bsd.port.post.mk>
