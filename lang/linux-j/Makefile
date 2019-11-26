# Created by: js@jeannot.org
# $FreeBSD$

PORTNAME=	j
PORTVERSION=	504b
PORTREVISION=	4
CATEGORIES=	lang linux java
MASTER_SITES=	http://www.jsoftware.com/download/
PKGNAMEPREFIX=	linux-
DISTNAME=	j${PORTVERSION}_linux32
DIST_SUBDIR=	${PKGNAMEPREFIX}${PORTNAME}/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	General purpose programming language

LICENSE=	JSoftware
LICENSE_NAME=	JSoftware End User License Agreement
LICENSE_FILE=	${FILESDIR}/license.txt
LICENSE_PERMS=	auto-accept dist-mirror pkg-mirror

USES=		linux
USE_JAVA=	yes

ONLY_FOR_ARCHS=	i386 amd64

NO_WRKSUBDIR=	yes
NO_BUILD=	yes

SUB_FILES=	j-jconsole.sh jw.sh
SUB_LIST=	PORTVERSION=${PORTVERSION:S/b//g}

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/j-jconsole.sh ${STAGEDIR}${PREFIX}/bin/j-jconsole
	${INSTALL_SCRIPT} ${WRKDIR}/jw.sh ${STAGEDIR}${PREFIX}/bin/jw
	${INSTALL_MAN} ${WRKSRC}/j${PORTVERSION:S/b//g}/system/extras/help/man/jconsole.1 ${STAGEDIR}${PREFIX}/man/man1/${MAN1}
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/j
	cd ${WRKSRC}/j${PORTVERSION:S/b//g} && \
		${COPYTREE_SHARE} "system user profile.ijs j.jar" \
			${STAGEDIR}${PREFIX}/lib/j
	${BRANDELF} -t Linux ${WRKSRC}/j${PORTVERSION:S/b//g}/jconsole
	${INSTALL_PROGRAM} ${WRKSRC}/j${PORTVERSION:S/b//g}/jconsole ${STAGEDIR}${PREFIX}/lib/j/jconsole

	${MV} ${STAGEDIR}${PREFIX}/man/man1/jconsole.1 ${STAGEDIR}${PREFIX}/man/man1/j-jconsole.1

.include <bsd.port.mk>
