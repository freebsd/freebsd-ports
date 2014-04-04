# Created by: Mikhail Teterin <mi@aldan.algebra.com>
# $FreeBSD$

PORTNAME=	jgoodies-common
PORTVERSION=	1.2.1
CATEGORIES=	devel java
MASTER_SITES=	http://www.jgoodies.com/download/libraries/common/
DISTNAME=	${PORTNAME}-${PORTVERSION:S|.|_|g}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Abstract and helper classes used by all other JGoodies libs

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	${JAVALIBDIR}/junit.jar:${PORTSDIR}/java/junit

USES=		dos2unix zip:infozip
USE_JAVA=	yes
JAVA_VERSION=	1.6+
USE_ANT=	yes
MAKE_ARGS+=	-Djunit4.jar=${LOCALBASE}/share/java/classes/junit.jar
ALL_TARGET=	jar test
EXTRACT_AFTER_ARGS=-d ${WRKDIR} -x '*/api/*' '*.jar'
REINPLACE_ARGS=	-i ""

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

JARFILE=	${PORTNAME}.jar
PLIST_FILES=	%%JAVAJARDIR%%/${JARFILE}
PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}
ALL_TARGET+=	javadoc
.endif

post-patch:
	${REINPLACE_CMD} 's|haltonfailure="no"|haltonfailure="yes"|' \
		${WRKSRC}/build.xml
	${FIND} ${WRKSRC} -type f -not -name '*.gif' | ${XARGS} \
		${REINPLACE_CMD} -E 's|[[:blank:]]+$$||'
.if defined(NO_LICENSES_INSTALL) || defined(DISABLE_LICENSES)
	${REINPLACE_CMD} -E 's|<a .[^>]+>License</a>|<abbr title="BSD 3-clause. License-file installation disabled">License</abbr>|'\
		${WRKSRC}/README.html
.else
	${REINPLACE_CMD} -E 's|href="LICENSE.txt"|href="../../../${_LICENSE_DIR_REL}/BSD"|' \
		${WRKSRC}/README.html
.endif

do-install:
	${INSTALL_DATA} ${WRKSRC}/build/${JARFILE} ${STAGEDIR}${JAVAJARDIR}
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} README.html RELEASE-NOTES.txt \
		${STAGEDIR}${DOCSDIR})	
	(cd ${WRKSRC} && ${COPYTREE_SHARE} docs ${STAGEDIR}${DOCSDIR})
	(cd ${WRKSRC}/build/docs && ${COPYTREE_SHARE} api \
		${STAGEDIR}${DOCSDIR}/docs)
.endif

.include <bsd.port.mk>
