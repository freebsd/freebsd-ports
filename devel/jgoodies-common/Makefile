# Created by: Mikhail Teterin <mi@aldan.algebra.com>
# $FreeBSD$

PORTNAME=	jgoodies-common
PORTVERSION=	1.2.1
CATEGORIES=	devel java
MASTER_SITES=	http://www.jgoodies.com/download/libraries/common/
DISTNAME=	${PORTNAME}-${PORTVERSION:S|.|_|g}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Abstract and helper classes used by all other JGoodies libs

LICENSE=	BSD
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

.if !defined(NOPORTDOCS)
ALL_TARGET+=	javadoc
PORTDOCS=	*
.endif

NO_STAGE=	yes
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
	${INSTALL_DATA} ${WRKSRC}/build/${JARFILE} ${JAVAJARDIR}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${CP} -R ${WRKSRC}/README.html ${WRKSRC}/RELEASE-NOTES.txt ${WRKSRC}/docs ${DOCSDIR}/
	@${CP} -R ${WRKSRC}/build/docs/api ${DOCSDIR}/docs
	# Documentation, including javadoc-generated, was installed in ${DOCSDIR}.
.endif

.include <bsd.port.mk>
