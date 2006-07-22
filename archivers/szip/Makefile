# New ports collection makefile for:	szip
# Date created:		15 January 2002
# Whom:			Igor Pokrovsky <tiamat@telegraph.spb.ru>
#
# $FreeBSD$
#

PORTNAME=	szip
PORTVERSION=	1.12b
PORTREVISION=	1
CATEGORIES=	archivers
MASTER_SITES=	http://www.compressconsult.com/szip/
DISTNAME=	sz${PORTVERSION:S/.//}_src

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A fast compression utility

USE_GMAKE=	yes

WRKSRC=		${WRKDIR}

PLIST_FILES=	bin/${PORTNAME}
PORTDOCS=	history.txt readme.txt techinfo.txt

do-build:
	${GMAKE} -C ${WRKDIR}

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/${PORTNAME} ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKDIR}/*.txt ${DOCSDIR}
.endif

.include <bsd.port.mk>
