# New ports collection makefile for:	extract-xiso
# Date created:				Sun Apr 20 18:28:16 CEST 2003
# Whom:					king@v2project.com
#
# $FreeBSD$
#

PORTNAME=	extract-xiso
DISTVERSION=	2.5
CATEGORIES=	emulators
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}%20source/${PORTNAME}%20v${PORTVERSION}%20source%20code
DISTNAME=	${PORTNAME}_v${DISTVERSION}_src
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tool for extracting and creating optimised Xbox ISO images

WRKSRC=		${WRKDIR}/extract-xiso

PLIST_FILES=	bin/extract-xiso
DOC=		LICENSE.TXT

MAKE_ENV=	PTHREAD_LIBS=${PTHREAD_LIBS}

.if !defined(NOPORTDOCS)
PORTDOCS=	*
.endif

pre-configure:
	@${CP} ${FILESDIR}/Makefile ${WRKSRC}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin/${PORTNAME}
.	if !defined(NOPORTDOCS)
		${MKDIR} ${DOCSDIR}
		${INSTALL_DATA} ${WRKSRC}/LICENSE.TXT ${DOCSDIR}
.	endif

.include <bsd.port.mk>
