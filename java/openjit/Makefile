# New ports collection makefile for:	openjit
# Date created:				26 September 2000
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	openjit
PORTVERSION=	1.1.16
PORTREVISION=	1
CATEGORIES=	java
MASTER_SITES=	http://www.openjit.org/dist/
PKGNAMESUFFIX=	-${JAVA_PORT:S,java/,,}
DISTNAME=	OpenJIT-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A high-performance reflective Java Just-In-Time bytecode compiler

USE_JAVA=	yes
JAVA_OS=	native
JAVA_VENDOR?=	bsdjava
JAVA_VERSION?=	1.3

ONLY_FOR_ARCHS=	i386

USE_REINPLACE=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--with-jdk=${JAVA_HOME}
MAKE_ARGS=	ARCH=X86

PLIST_SUB+=	JAVADIR=${JAVA_HOME:S,${PREFIX}/,,}

.include <bsd.port.pre.mk>

.if ${JAVA_PORT_VERSION} == 1.1
JDKLIBDIR=	${PREFIX}/lib/OpenJIT
PLIST_SUB+=	JAVA2:="@comment " JAVA11:=""
.else
PLIST_SUB+=	JAVA2:="" JAVA11:="@comment "
.endif

post-configure:
	@${REINPLACE_CMD} -e "s|%%PREFIX%%|${PREFIX}|g" ${WRKSRC}/INSTALL

do-install:
.if ${JAVA_PORT_VERSION} == 1.1
	@${MKDIR} ${JDKLIBDIR}
	@${INSTALL_DATA} ${WRKSRC}/libOpenJIT.so ${JDKLIBDIR}
	@${INSTALL_DATA} ${WRKSRC}/OpenJIT.jar ${JDKLIBDIR}
.else
	@${MKDIR} ${JAVA_HOME}/jre/classes
	@${INSTALL_DATA} ${WRKSRC}/libOpenJIT.so ${JAVA_HOME}/jre/lib/i386
	@cd ${WRKSRC} && ${FIND} org -name '*.class' \
	  | ${CPIO} -pdmu -R ${LIBOWN}:${LIBGRP} ${JAVA_HOME}/jre/classes > /dev/null 2>&1
	@${FIND} ${JAVA_HOME}/jre/classes -type d | ${XARGS} ${CHMOD} a+rx
.endif
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}/README
	@${INSTALL_DATA} ${WRKSRC}/INSTALL ${DOCSDIR}/INSTALL
	@${ECHO_MSG} ""
	@${ECHO_MSG} "See ${DOCSDIR}/INSTALL for usage instructions."
	@${ECHO_MSG} ""
.endif

.include <bsd.port.post.mk>
