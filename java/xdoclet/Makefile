# New ports collection makefile for:	xdoclet
# Date created:				Feb 25 2003
# Whom:					Sheldon Hearn <sheldonh@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	xdoclet
PORTVERSION=	1.2b3
CATEGORIES=	java devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}-bin-${PORTVERSION}
DISTFILES=	${DISTNAME}.zip xjavadoc-${XJAVADOC_VER}.zip

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Java attribute-oriented code generation engine

RUN_DEPENDS=	${LOCALBASE}/bin/ant:${PORTSDIR}/devel/apache-ant

USE_JAVA=	1.2+
USE_ZIP=	yes
NO_WRKSUBDIR=	yes
NO_BUILD=	yes
NO_BUILD_DEPENDS_JAVA=	yes

CLASSDIR=	${PREFIX}/share/java/classes
XJAVADOC_VER=	1.0

PLIST_SUB+=	XJAVADOC_VER="${XJAVADOC_VER}"

post-extract:
	${RMDIR} ${WRKSRC}/docs/stylesheets

do-install:
	${MKDIR} ${CLASSDIR} ${DOCSDIR} ${EXAMPLESDIR}
	cd ${WRKSRC} && ${FIND} lib -name '*xdoclet*' -exec \
	    ${INSTALL_DATA} \{} ${CLASSDIR} \;
	cd ${WRKSRC}/samples && ${FIND} . -type d -exec \
	    ${MKDIR} ${EXAMPLESDIR}/\{} \;
	cd ${WRKSRC}/samples && ${FIND} . -type f -exec \
	    ${INSTALL_DATA} \{} ${EXAMPLESDIR}/\{} \;
	${INSTALL_DATA} \
	    ${WRKSRC}/xjavadoc-${XJAVADOC_VER}/xjavadoc-${XJAVADOC_VER}.jar \
	    ${CLASSDIR}
.if !defined(NOPORTDOCS)
	cd ${WRKSRC}/docs && ${FIND} . -type d -exec \
	    ${MKDIR} ${DOCSDIR}/\{} \;
	cd ${WRKSRC}/docs && ${FIND} . -type f -exec \
	    ${INSTALL_DATA} \{} ${DOCSDIR}/\{} \;
.endif

.include <bsd.port.mk>
