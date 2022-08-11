PORTNAME=	je
PORTVERSION=	7.5.11
CATEGORIES=	java databases
MASTER_SITES=	http://download.oracle.com/berkeley-db/	\
		http://download-east.oracle.com/berkeley-db/	\
		http://download-west.oracle.com/berkeley-db/

MAINTAINER=	mi@aldan.algebra.com
COMMENT=	Berkeley DB Java Edition

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${JAVALIBDIR}/junit.jar:java/junit

OPTIONS_DEFINE=	DOCS EXAMPLES TEST

USE_JAVA=	8
USE_ANT=	yes
MAKE_ENV+=	JAVALIBDIR="${JAVALIBDIR}"
MAKE_ARGS+=	-cp ${JAVALIBDIR}/junit.jar
EXTRACT_AFTER_ARGS+=	--exclude '*.jar'

PLIST_FILES=	${JAVAJARDIR:S,^${PREFIX}/,,}/je-${PORTVERSION}.jar \
		${JAVAJARDIR:S,^${PREFIX}/,,}/je.jar
PORTDOCS=	*
PORTEXAMPLES=	*

regression-test check test: build
	#
	# Running the vendor-provided self-tests. This may take a while
	#
	@if ! (cd ${BUILD_WRKSRC} ; ${MAKE_ENV} ${ANT} ${MAKE_ARGS} test) ; \
	then	\
		${ECHO_MSG} Please, review test failures and consider \
			reporting them via \
			http://forums.oracle.com/forums/forum.jspa?forumID=273 ; \
		${FALSE} ; \
	fi

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MTEST}
post-build:	test
	#
	# Please, review the reported failures (if any) and consider
	# reporting them to the developers via:
	#	http://forums.oracle.com/forums/forum.jspa?forumID=273
	# You can re-run the tests without rebuilding the port by
	# simply doing `make test'
	#
.else
post-build:
	#
	# Doing `make test' now might be useful (if time-consuming).
	# Please, review the reported failures (if any) and consider
	# reporting them via
	#	http://forums.oracle.com/forums/forum.jspa?forumID=273
	#
.endif

post-patch:
	@${REINPLACE_CMD} "s,/usr/local,${PREFIX}," ${WRKSRC}/build.xml
	${FIND} ${WRKSRC} -type f -name \*.java | ${XARGS} \
	    ${REINPLACE_CMD} -i "" -E 's,[^[:print:]]+, ,g'

do-install:
	${INSTALL_DATA} ${WRKSRC}/build/lib/je.jar ${STAGEDIR}${JAVAJARDIR}/je-${PORTVERSION}.jar
	${LN} -s -f je-${PORTVERSION}.jar ${STAGEDIR}${JAVAJARDIR}/je.jar

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@(cd ${WRKSRC}/docs/ && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR})

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	@(cd ${WRKSRC}/examples/ && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR})

.include <bsd.port.mk>
