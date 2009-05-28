# New ports collection makefile for:	quaqut
# Date created:				19 October 2006
# Whom:					Alexander Logvinov <ports@logvinov.com>
#
# $FreeBSD$
#

PORTNAME=	quaqut
PORTVERSION=	0.2.0
CATEGORIES=	games
MASTER_SITES=	SF

MAINTAINER=	avl@FreeBSD.org
COMMENT=	Queries information from Unreal Tournament 2004 game servers

MAKE_JOBS_SAFE=	yes

HAS_CONFIGURE=	yes
USE_RC_SUBR=	${PORTNAME}
MAN1=		${PORTNAME}.1
PORTDOCS=	AUTHORS COPYING ChangeLog README
PLIST_FILES=	bin/${PORTNAME}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/${PORTNAME} ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${MAN1} ${MAN1PREFIX}/man/man1
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for i in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
