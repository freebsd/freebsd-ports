# New ports collection makefile for:	merlin
# Date created:				12 August 1998
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

PORTNAME=	merlin
PORTVERSION=	1.0
CATEGORIES=	games
MASTER_SITES=	http://www.doc.ic.ac.uk/~np2/software/download/
DISTNAME=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A pointless puzzle game for Tcl/Tk

RUN_DEPENDS=	wish8.2:${PORTSDIR}/x11-toolkits/tk82

NO_WRKSUBDIR=	yes
NO_BUILD=	yes
USE_X_PREFIX=	yes

post-patch:
	@${SED} -e "s:%%LOCALBASE%%:${LOCALBASE}:g" \
		${WRKSRC}/merlin.tcl > ${WRKSRC}/merlin

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/merlin ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/merlin
	${INSTALL_DATA} ${WRKSRC}/merlin.README.txt ${PREFIX}/share/doc/merlin/README
.endif

.include <bsd.port.mk>
