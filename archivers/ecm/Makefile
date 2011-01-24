# New ports collection makefile for:	ecm
# Date created:				9 Aug 2005
# Whom:					Emanuel Haupt <ehaupt@critical.ch>
#
# $FreeBSD$
#

PORTNAME=	ecm
PORTVERSION=	1.0
CATEGORIES=	archivers
MASTER_SITES=	CRITICAL

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Compresses CD images by stripping unnecessary EDC/ECC data

MAKE_JOBS_SAFE=	yes

LICENSE=	GPLv2
PLIST_FILES=	bin/ecm bin/unecm
PORTDOCS=	format.txt

do-install:
.for f in ${PORTNAME} un${PORTNAME}
	${INSTALL_PROGRAM} ${WRKSRC}/${f} ${PREFIX}/bin
.endfor

.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTDOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
