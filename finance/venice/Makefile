# New ports collection makefile for:	Merchant Of Venice
# Date created:		Thu Jan 20 03:24:01 UTC 2005
# Whom:                 Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	venice
DISTVERSION=	0.71beta
CATEGORIES=	finance java
MASTER_SITES=	SF/mov/${PORTNAME}/0.71%20beta
DISTNAME=	${PORTNAME}-${DISTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Merchant Of Venice, a stock market trading program

NO_BUILD=	yes
USE_JAVA=	yes
JAVA_RUN=	yes
JAVA_VERSION=	1.4+

JARFILE=	${PORTNAME}.jar

PLIST_FILES=	bin/venice \
		%%JAVAJARDIR%%/${JARFILE}

# docs
DOC_FILES=	doc/manual.txt \
		doc/manual.html \
		changelog.txt \
		readme.txt

.ifndef(NOPORTDOCS)
PORTDOCS=	*
.endif

.include <bsd.port.pre.mk>

post-patch:
	${REINPLACE_CMD} -e s,venice.jar,${JAVAJARDIR}/${JARFILE}, ${WRKSRC}/venice

do-install:
# docs
.ifndef(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for doc in ${DOC_FILES}
	@${INSTALL_DATA} ${WRKSRC}/${doc} ${DOCSDIR}
.endfor
.endif
# wrapper
	@${INSTALL_SCRIPT} ${WRKSRC}/venice ${PREFIX}/bin/
# jar
	@${MKDIR} ${JAVAJARDIR}
	@${INSTALL_DATA} ${WRKSRC}/${JARFILE} ${JAVAJARDIR}/

.include <bsd.port.post.mk>
