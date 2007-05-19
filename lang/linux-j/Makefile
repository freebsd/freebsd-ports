# New ports collection makefile for:   linux-j
# Date created:        29 September 2001
# Whom:                js@jeannot.org
#
# $FreeBSD$
#

PORTNAME=	j
PORTVERSION=	504b
PORTREVISION=	2
CATEGORIES=	lang linux java
MASTER_SITES=	http://www.jsoftware.com/download/
PKGNAMEPREFIX=	linux-
DISTNAME=	j${PORTVERSION}_linux32
DIST_SUBDIR=	${PKGNAMEPREFIX}${PORTNAME}/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A general purpose programming language

RUN_DEPENDS=	javavm:${PORTSDIR}/java/javavmwrapper

# Java 1.5 JDKs install ${PREFIX}/bin/jconsole
CONFLICTS=	diablo-jdk-1.5.0* jdk-1.5.0* linux-sun-jdk-1.5.0*

USE_LINUX=	yes
USE_JAVA=	yes
JAVA_VERSION=	1.3 1.4

ONLY_FOR_ARCHS=	i386

NO_WRKSUBDIR=	yes
NO_BUILD=	yes

MAN1=		jconsole.1

SUB_FILES=	jconsole.sh jw.sh
SUB_LIST=	PORTVERSION=${PORTVERSION:S/b//g}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/jconsole.sh ${PREFIX}/bin/jconsole
	${INSTALL_SCRIPT} ${WRKSRC}/jw.sh ${PREFIX}/bin/jw
	${INSTALL_MAN} ${WRKSRC}/j${PORTVERSION:S/b//g}/system/extras/help/man/${MAN1} ${PREFIX}/man/man1
	@${MKDIR} ${PREFIX}/lib/j
	cd ${WRKSRC}/j${PORTVERSION:S/b//g} && \
		${TAR} -cf - system user profile.ijs j.jar | \
			${TAR} -xf - -C ${PREFIX}/lib/j
	@${FIND} ${PREFIX}/lib/j/ -type f -exec ${CHMOD} ${SHAREMODE} {} \;
	@${FIND} ${PREFIX}/lib/j/ -type f -exec ${CHOWN} ${SHAREOWN} {} \;
	${INSTALL_PROGRAM} ${WRKSRC}/j${PORTVERSION:S/b//g}/jconsole ${PREFIX}/lib/j/jconsole
	${BRANDELF} -t Linux ${PREFIX}/lib/j/jconsole

post-install:
.if !defined(BATCH)
	@${CAT} ${PKGMESSAGE}
.endif

.include <bsd.port.mk>
