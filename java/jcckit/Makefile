# Created by: ijliao
# $FreeBSD$

PORTNAME=	jcckit
PORTVERSION=	1.1
PORTREVISION=	2
CATEGORIES=	java graphics
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/JCCKit%20${PORTVERSION}
DISTNAME=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Java Chart Construction Kit

USES=		zip
USE_JAVA=	yes
WRKSRC=		${WRKDIR}/JCCKit
NO_BUILD=	yes

PLIST_FILES=	%%JAVAJARDIR%%/${PORTNAME}.jar
PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.jar ${STAGEDIR}${JAVAJARDIR}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for file in LICENSE.txt README.html docs
	${CP} -R ${WRKSRC}/${file} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
