# Created by: Alex Dupre <ale@FreeBSD.org>
# $FreeBSD$

PORTNAME=	scala-docs
PORTVERSION=	2.12.3
CATEGORIES=	lang java
MASTER_SITES=	http://www.scala-lang.org/files/archive/

MAINTAINER=	ale@FreeBSD.org
COMMENT=	Documentation for the Scala libraries & compiler

USES=		tar:txz
NO_BUILD=	yes
NO_ARCH=	yes

PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

WRKSRC=		${WRKDIR}/scala-${PORTVERSION}

PORTSCOUT=	limit:^2\.12\.

.include <bsd.port.options.mk>

.if ! ${PORT_OPTIONS:MDOCS}
IGNORE=		port only installs documentation
.endif

do-install:
	@${ECHO} -n ">> Installing documentation in ${DOCSDIR}..."
	@${MKDIR} ${STAGEDIR}/${DOCSDIR}
	@(cd ${WRKSRC}/api && ${COPYTREE_SHARE} \* ${STAGEDIR}/${DOCSDIR}/)
	@${ECHO} " [ DONE ]"

.include <bsd.port.mk>
