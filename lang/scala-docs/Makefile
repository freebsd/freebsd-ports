# Created by: Alex Dupre <ale@FreeBSD.org>
# $FreeBSD$

PORTNAME=	scala-docs
PORTVERSION=	2.13.1
CATEGORIES=	lang java
MASTER_SITES=	http://www.scala-lang.org/files/archive/

MAINTAINER=	ale@FreeBSD.org
COMMENT=	Documentation for the Scala libraries & compiler

LICENSE=	APACHE20

USES=		tar:txz

NO_BUILD=	yes
NO_ARCH=	yes

PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

DOCS_IGNORE_OFF=port only installs documentation

WRKSRC=		${WRKDIR}/scala-${PORTVERSION}

#PORTSCOUT=	limit:^2\.13\.

do-install:
	@${ECHO} -n ">> Installing documentation in ${DOCSDIR}..."
	@${MKDIR} ${STAGEDIR}/${DOCSDIR}
	@(cd ${WRKSRC}/api && ${COPYTREE_SHARE} \* ${STAGEDIR}/${DOCSDIR}/)
	@${ECHO} " [ DONE ]"

.include <bsd.port.mk>
