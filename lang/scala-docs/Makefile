# Created by: Alex Dupre <ale@FreeBSD.org>
# $FreeBSD$

PORTNAME=	scala-docs
PORTVERSION=	2.10.4
CATEGORIES=	lang java
MASTER_SITES=	http://www.scala-lang.org/files/archive/
EXTRACT_SUFX=	.txz

MAINTAINER=	ale@FreeBSD.org
COMMENT=	The documentation for the Scala standard library

USES=		tar:xz
NO_BUILD=	yes

PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

.if ! ${PORT_OPTIONS:MDOCS}
IGNORE=		port only installs documentation
.endif

do-install:
	@${ECHO} -n ">> Installing documentation in ${DOCSDIR}..."
	@${MKDIR} ${STAGEDIR}/${DOCSDIR}
	@(cd ${WRKSRC}/ && ${COPYTREE_SHARE} \* ${STAGEDIR}/${DOCSDIR}/)
	@${ECHO} " [ DONE ]"

.include <bsd.port.mk>
