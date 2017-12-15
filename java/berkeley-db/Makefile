# Created by: Mikhail Teterin
# $FreeBSD$

PORTNAME=	je
PORTVERSION=	6.2.31
CATEGORIES=	java databases
MASTER_SITES=	http://download.oracle.com/berkeley-db/	\
		http://download-east.oracle.com/berkeley-db/	\
		http://download-west.oracle.com/berkeley-db/

MAINTAINER=	mi@aldan.algebra.com
COMMENT=	Berkeley DB Java Edition

BUILD_DEPENDS=	${JAVALIBDIR}/junit.jar:java/junit

BROKEN_armv6=		fails to build: build.xml: Java returned: 1
BROKEN_armv7=		fails to build: build.xml: Java returned: 1

OPTIONS_DEFINE=	DOCS EXAMPLES TEST

USE_JAVA=	yes
JAVA_VERSION=	1.7+
USE_ANT=	yes
MAKE_ENV+=	JAVALIBDIR="${JAVALIBDIR}"
MAKE_ARGS+=	-cp ${JAVALIBDIR}/junit.jar

PLIST_FILES=	%%JAVAJARDIR%%/je.jar

PORTDOCS=	*
PORTEXAMPLES=	*

regression-test check test: build
	#
	# Running the vendor-provided self-tests. This may take a while
	#
	if ! (cd ${BUILD_WRKSRC} ; ${MAKE_ENV} ${ANT} ${MAKE_ARGS} test) ; \
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

do-install:
	${INSTALL_DATA} ${WRKSRC}/build/lib/je.jar ${STAGEDIR}${JAVAJARDIR}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@(cd ${WRKSRC}/docs/ && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR})
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	@(cd ${WRKSRC}/examples/ && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR})

.include <bsd.port.mk>
