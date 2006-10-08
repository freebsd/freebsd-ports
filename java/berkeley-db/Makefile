# New ports collection makefile for:	Berkeley DB Java
# Date created:		Feb 2, 2005
# Whom:			Mikhail Teterin
#
# $FreeBSD$
#

PORTNAME=	je
PORTVERSION=	3.1.0
CATEGORIES=	java databases
MASTER_SITES=	http://download.oracle.com/berkeley-db/

MAINTAINER=	mi@aldan.algebra.com
COMMENT=	Berkeley DB Java Edition

OPTIONS=	TEST "Run the self-tests after building automatically" on

BUILD_DEPENDS=	${JAVALIBDIR}/junit.jar:${PORTSDIR}/java/junit

USE_JAVA=	yes
JAVA_VERSION=	1.5+
USE_ANT=	yes
MAKE_ENV+=	JAVALIBDIR="${JAVALIBDIR}"
MAKE_ARGS+=	-cp ${JAVALIBDIR}/junit.jar
USE_DOS2UNIX=	build.xml

PLIST_FILES=	%%JAVAJARDIR%%/je.jar

.if !defined(NOPORTDOCS)
PORTDOCS=	*
.endif

test:
	#
	# Running the vendor-provided self-tests. This may take a while
	#
	@cd ${BUILD_WRKSRC} && \
	    ${MAKE_ENV} ${ANT} ${MAKE_ARGS} ${.TARGET} || \
		${ECHO_MSG} Please, review test failures and consider \
			reporting them via \
			http://forums.oracle.com/forums/forum.jspa?forumID=273 \
			&& ${FALSE}

.include <bsd.port.pre.mk>

.if defined(WITH_TEST)
post-build:	test
	#
	# Please, review the reported failures (if any) and consider
	# reporting them to the developers at support@sleepycat.com
	# You can re-run the tests without rebuilding the port by
	# simply doing `make test'
	#
.else
post-build:
	#
	# Doing `make test' now might be useful (if time-consuming)
	# Please, review the reported failures (if any) and consider
	# reporting them via
	# 	http://forums.oracle.com/forums/forum.jspa?forumID=273
	#
.endif


post-patch:
	@${REINPLACE_CMD} "s,/usr/local,${TARGETDIR}," ${WRKSRC}/build.xml

do-install:
	@${INSTALL_DATA} ${WRKSRC}/build/lib/je.jar ${JAVAJARDIR}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${CP} -R ${WRKSRC}/docs/ ${DOCSDIR}
	@${MKDIR} ${EXAMPLESDIR}
	@${CP} -R ${WRKSRC}/examples/ ${EXAMPLESDIR}

post-install:
	@${FIND} ${EXAMPLESDIR} ! -type d | \
		${SED} -e "s,^${PREFIX}/,," >> ${TMPPLIST}
	@${FIND} ${EXAMPLESDIR} -type d | ${SORT} -r | \
		${SED} -e "s,^${PREFIX}/,@dirrm ," >> ${TMPPLIST}
.endif

.include <bsd.port.post.mk>
