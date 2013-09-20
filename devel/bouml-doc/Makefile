# Created by: Thierry Thomas <thierry@pompo.net>
# $FreeBSD$

PORTNAME=	bouml-doc
PORTVERSION=	4.23
CATEGORIES=	devel
MASTER_SITES=	SF/bouml/doc/${PORTVERSION}_ultimate/
DISTNAME=	doc${PORTVERSION}

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Reference manual of BOUML

NO_BUILD=	yes
WRKSRC=		${WRKDIR}/doc
DOCSDIR=	${PREFIX}/share/doc/bouml

NO_STAGE=	yes
do-install:
	${MKDIR} ${DOCSDIR}
	(cd ${WRKSRC} && ${COPYTREE_SHARE} \* ${DOCSDIR})

.include <bsd.port.mk>
