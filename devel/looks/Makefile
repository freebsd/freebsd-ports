# Created by: Thierry Thomas <thierry@pompo.net>
# $FreeBSD$

PORTNAME=	looks
PORTVERSION=	2.5.2
PORTREVISION=	1
CATEGORIES=	devel java
MASTER_SITES=	http://www.jgoodies.com/download/libraries/${PORTNAME}/
DISTNAME=	jgoodies-${PORTNAME}-${PORTVERSION:S|.|_|g}
EXTRACT_SUFX=	.zip

MAINTAINER=	ports@FreeBSD.org
COMMENT=	JGoodies Looks improve the appearance of your Java applications

OPTIONS_DEFINE=	DOCS

LICENSE=	BSD3CLAUSE

USE_JAVA=	yes
JAVA_VERSION=	1.6+
NO_BUILD=	yes

WRKSRC=		${WRKDIR}/jgoodies-${PORTNAME}-${PORTVERSION}

JARFILE=	jgoodies-${PORTNAME}-${PORTVERSION}.jar

PLIST_FILES=	%%JAVAJARDIR%%/${JARFILE} \
		%%JAVAJARDIR%%/looks.jar
DOCFILES=	README.html RELEASE-NOTES.txt
PORTDOCS=	*

do-install:
	${INSTALL_DATA} ${WRKSRC}/${JARFILE} ${STAGEDIR}${JAVAJARDIR}
	${LN} -sf ${JARFILE} ${STAGEDIR}${JAVAJARDIR}/looks.jar
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@${INSTALL_DATA} ${DOCFILES:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}
	@(cd ${WRKSRC}/docs/ && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
