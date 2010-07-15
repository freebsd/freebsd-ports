# New ports collection makefile for:	pipestatus
# Date created:				2008/01/26
# Whom:					chinsan
#
# $FreeBSD$
#

PORTNAME=	pipestatus
PORTVERSION=	0.6.0
CATEGORIES=	devel
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	UNIX/POSIX shell helper for running pipes safely

NO_BUILD=	yes

PORTDOCS=	ChangeLog README NEWS
PLIST_FILES=	bin/${PORTNAME}

do-install:
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for doc in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${doc} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
