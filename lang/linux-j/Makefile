# Created by: js@jeannot.org
# $FreeBSD$

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

LICENSE=	JSoftware
LICENSE_NAME=	JSoftware End User License Agreement
LICENSE_FILE=	${FILESDIR}/license.txt
LICENSE_PERMS=	auto-accept dist-mirror pkg-mirror

RUN_DEPENDS=	javavm:${PORTSDIR}/java/javavmwrapper

USE_LINUX=	yes
USE_JAVA=	yes
JAVA_VERSION=	1.6+

ONLY_FOR_ARCHS=	i386 amd64

NO_WRKSUBDIR=	yes
NO_BUILD=	yes

SUB_FILES=	j-jconsole.sh jw.sh
SUB_LIST=	PORTVERSION=${PORTVERSION:S/b//g}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/j-jconsole.sh ${STAGEDIR}${PREFIX}/bin/j-jconsole
	${INSTALL_SCRIPT} ${WRKSRC}/jw.sh ${STAGEDIR}${PREFIX}/bin/jw
	${INSTALL_MAN} ${WRKSRC}/j${PORTVERSION:S/b//g}/system/extras/help/man/jconsole.1 ${STAGEDIR}${PREFIX}/man/man1/${MAN1}
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/j
	cd ${WRKSRC}/j${PORTVERSION:S/b//g} && \
		${TAR} -cf - system user profile.ijs j.jar | \
			${TAR} -xf - -C ${STAGEDIR}${PREFIX}/lib/j
	@${FIND} ${STAGEDIR}${PREFIX}/lib/j/ -type f -exec ${CHMOD} ${SHAREMODE} {} \;
	@${FIND} ${STAGEDIR}${PREFIX}/lib/j/ -type f -exec ${CHOWN} ${SHAREOWN} {} \;
	${INSTALL_PROGRAM} ${WRKSRC}/j${PORTVERSION:S/b//g}/jconsole ${STAGEDIR}${PREFIX}/lib/j/jconsole
	${BRANDELF} -t Linux ${STAGEDIR}${PREFIX}/lib/j/jconsole

post-install:
	${MV} ${STAGEDIR}${PREFIX}/man/man1/jconsole.1 ${STAGEDIR}${PREFIX}/man/man1/j-jconsole.1

post-install:
.if !defined(BATCH)
	@${CAT} ${PKGMESSAGE}
.endif

.include <bsd.port.mk>
