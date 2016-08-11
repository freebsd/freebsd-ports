# Created by: Jason Bacon <bacon4000@gmail.com>
# $FreeBSD$

PORTNAME=	slclust
PORTVERSION=	2010.02.02
CATEGORIES=	biology
MASTER_SITES=	SF/slclust/slclust
DISTNAME=	${PORTNAME}_02022010

MAINTAINER=	bacon4000@gmail.com
COMMENT=	Single-linkage clustering with Jaccard similarity

LICENSE=	ART10

WRKSRC=		${WRKDIR}/${PORTNAME}

PLIST_FILES=	bin/slclust

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/slclust ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
