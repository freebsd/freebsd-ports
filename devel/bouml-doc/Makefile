# Created by: Thierry Thomas <thierry@pompo.net>
# $FreeBSD$

PORTNAME=	bouml-doc
PORTVERSION=	4.23
CATEGORIES=	devel
MASTER_SITES=	http://www.bouml.fr/ \
		http://bouml.free.fr/
DISTNAME=	doc${PORTVERSION}

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Reference manual of BOUML

NO_BUILD=	yes
WRKSRC=		${WRKDIR}/doc
DOCSDIR=	${PREFIX}/share/doc/bouml

do-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${COPYTREE_SHARE} \* ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
