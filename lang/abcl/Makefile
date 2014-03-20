# Created by: Frank Fischer
# $FreeBSD$

PORTNAME=	abcl
PORTVERSION=	1.2.1
CATEGORIES=	lang lisp java
MASTER_SITES=	http://abcl.org/releases/${PORTVERSION}/
DISTNAME=	${PORTNAME}-src-${PORTVERSION}

MAINTAINER=	fischer.frank@gmail.com
COMMENT=	An implementation of ANSI Common Lisp in Java

PLIST_FILES=	share/java/classes/abcl.jar \
		bin/abcl

SUB_LIST+=	JAVAJARDIR="${JAVAJARDIR}"
SUB_FILES=	abcl

USE_JAVA=	yes
JAVA_VERSION=	1.6+
USE_ANT=	yes

do-install:
	${INSTALL_DATA} -v ${WRKSRC}/dist/abcl.jar ${STAGEDIR}${JAVAJARDIR}
	${INSTALL_SCRIPT} ${WRKDIR}/abcl ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
