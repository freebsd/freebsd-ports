# New ports collection makefile for:	szip
# Date created:		15 January 2002
# Whom:			Igor Pokrovsky <tiamat@telegraph.spb.ru>
#
# $FreeBSD$
#

PORTNAME=	szip
PORTVERSION=	1.12b
CATEGORIES=	archivers
MASTER_SITES=	http://www.compressconsult.com/szip/
DISTNAME=	${PORTNAME}_${PORTVERSION:S/.//}_FreeBSD

MAINTAINER=	tiamat@telegraph.spb.ru

NO_BUILD=	yes
ONLY_FOR_ARCHS=	i386

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/${PORTNAME} ${PREFIX}/bin
.ifndef (NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKDIR}/*.txt ${DOCSDIR}
.endif

.include <bsd.port.mk>
