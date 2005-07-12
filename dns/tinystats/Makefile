# New ports collection makefile for:	tinystats
# Date created:				07 July 2005
# Whom:				Filippo Natali <filippo.natali@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	tinystats
PORTVERSION=	1.0
CATEGORIES=	dns
MASTER_SITES=	http://www.morettoni.net/bsd/

MAINTAINER=	filippo.natali@gmail.com
COMMENT=	DJB's tinydns statistics generator

WRKSRC=		${WRKDIR}/${PORTNAME}
ALL_TARGET=

PLIST_FILES=	bin/tinystats \
		%%EXAMPLESDIR%%/tinydns.log.run.sample \
		%%EXAMPLESDIR%%/tinydns.sh.sample
PLIST_DIRS=	%%EXAMPLESDIR%%
PORTDOCS=	README

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tinystats ${PREFIX}/bin
	${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/tinydns.sh.sample ${WRKSRC}/tinydns.log.run.sample ${EXAMPLESDIR}
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
