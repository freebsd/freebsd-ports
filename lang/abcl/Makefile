# New ports collection makefile for:	abcl
# Date created:				22 April 2006
# Whom:					Frank Fischer
#
# $FreeBSD$
#

PORTNAME=	abcl
PORTVERSION=	1.0.1
CATEGORIES=	lang lisp java
MASTER_SITES=	http://common-lisp.net/project/armedbear/releases/${PORTVERSION}/
DISTNAME=	${PORTNAME}-src-${PORTVERSION}

MAINTAINER=	fischer.frank@gmail.com
COMMENT=	An implementation of ANSI Common Lisp in Java

PLIST_FILES=	share/java/classes/abcl.jar \
		bin/abcl

SUB_LIST+=	JAVAJARDIR="${JAVAJARDIR}"
SUB_FILES=	abcl

USE_JAVA=	yes
JAVA_VERSION=	1.5+
USE_ANT=	yes

do-install:
	@${INSTALL_DATA} -v ${WRKSRC}/dist/abcl.jar ${JAVAJARDIR}
	@${INSTALL_SCRIPT} ${WRKDIR}/abcl ${PREFIX}/bin/abcl

.include <bsd.port.mk>
