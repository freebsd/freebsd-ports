# Created by: Herve Quiroz <herve.quiroz@esil.univ-mrs.fr>
# $FreeBSD$

PORTNAME=	avalon-framework
PORTVERSION=	4.2.0
PORTREVISION=	2
CATEGORIES=	devel java
MASTER_SITES=	${MASTER_SITE_APACHE}
MASTER_SITE_SUBDIR=	avalon/${PORTNAME}/binaries/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Apache Avalon core framework for component programming

USE_JAVA=	yes
JAVA_VERSION=	1.6+
NO_BUILD=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}

PORTDOCS=	api basics.html cop cvs-usage.html dependencies.html images \
		index.html issue-tracking.html license.html linkcheck.html \
		mail-lists.html maven-reports.html principals \
		project-info.html style team-list.html

JARFILES=	${PORTNAME}.jar ${PORTNAME}-api.jar ${PORTNAME}-impl.jar
PLIST_FILES+=	${JARFILES:S,^,%%JAVAJARDIR%%/,}

OPTIONS_DEFINE=	DOCS

do-install:
.for jarfile in ${JARFILES}
	${INSTALL_DATA} ${WRKSRC}/jars/${jarfile:S,.jar$,-${PORTVERSION}.jar,} \
		${STAGEDIR}${JAVAJARDIR}/${jarfile}
.endfor
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/docs && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
