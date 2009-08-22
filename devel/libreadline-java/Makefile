# New ports collection makefile for:   libreadline-java
# Date created:                20 September 2007
# Whom:                        Martin Kammerhofer <mkamm@gmx.net>
#
# $FreeBSD$
#

PORTNAME=		libreadline-java
PORTVERSION=		0.8.0
DISTVERSIONSUFFIX=	-src
PORTREVISION=	1
CATEGORIES=		devel java
MASTER_SITES=		SF/java-readline/java-readline/${PORTVERSION}

MAINTAINER=	mkamm@gmx.net
COMMENT=	JNI wrapper around GNU Readline / libedit / libgetline

BUILD_DEPENDS=	${LOCALBASE}/include/editline/readline.h:${PORTSDIR}/devel/libedit
RUN_DEPENDS=	${LOCALBASE}/include/editline/readline.h:${PORTSDIR}/devel/libedit

ALL_TARGET=	# empty
MAKE_ENV=	JAVA_HOME="${JAVA_HOME}" JAVA="${JAVA}" JAVAC="${JAVAC}" \
		JAVAH="${JAVAH}" JAR_="${JAR}"
PKGMESSAGE=	${WRKDIR}/pkg-message
PLIST_FILES=	%%JAVAJARDIR%%/libreadline-java.jar lib/libJavaReadline.so \
		lib/libJavaEditline.so lib/libJavaGetline.so
.if !defined(NOPORTDOCS)
PLIST_FILES+=	%%DOCSDIR%%/README.1st %%DOCSDIR%%/README \
		%%DOCSDIR%%/jython.sh %%DOCSDIR%%/JReadlineCompleter.py \
		@dirrm\ %%DOCSDIR%%
.endif
USE_GMAKE=	yes
USE_JAVA=	yes
USE_LDCONFIG=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

do-install:
	${INSTALL_DATA} ${WRKSRC}/libreadline-java.jar ${JAVAJARDIR}
	${INSTALL_DATA} ${WRKSRC}/libJavaReadline.so ${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/libJavaEditline.so ${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/libJavaGetline.so ${PREFIX}/lib
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.1st ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
	${INSTALL_DATA} ${FILESDIR}/jython.sh ${DOCSDIR}
	${INSTALL_DATA} ${FILESDIR}/JReadlineCompleter.py ${DOCSDIR}
.endif

post-install:
	@${SED} -e 's|%%JAVAJARDIR%%|${JAVAJARDIR}|g' -- \
		${.CURDIR}/pkg-message >${PKGMESSAGE}
	@${CAT} ${PKGMESSAGE}

.if !defined(BATCH)
test:
	cd ${WRKSRC} && ${MAKE_ENV} ${GMAKE} test  # Now type something!
.endif

.include <bsd.port.mk>
