# New ports collection makefile for:   slib
# Date created:        01 April 1998
# Whom:                Yukihiro Nakai <Nakai@technologist.com>
#
# $FreeBSD$
#

PORTNAME=	slib
PORTVERSION=	3a1
CATEGORIES=	lang scheme
MASTER_SITES=	http://swissnet.ai.mit.edu/ftpdir/scm/
DISTNAME=	slib${PORTVERSION}

MAINTAINER=	fuyuki@nigredo.org
COMMENT=	A portable scheme library

WRKSRC=		${WRKDIR}/slib
USE_GMAKE=	yes
ALL_TARGET=	slib.info
INFO=		slib

do-install:
	${MKDIR} ${DATADIR}
	cd ${WRKSRC}; ${INSTALL_DATA} *.scm *.init *.txt *.xyz *.ps ${DATADIR}
	${INSTALL_MAN} ${WRKSRC}/slib.info ${PREFIX}/info
	install-info ${PREFIX}/info/slib.info ${PREFIX}/info/dir
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for file in ANNOUNCE ChangeLog FAQ README
	${INSTALL_MAN} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
