# New ports collection makefile for:   linux-j
# Date created:        29 September 2001
# Whom:                js@jeannot.org
#
# $FreeBSD$
#

PORTNAME=	linux-j
PORTVERSION=	504b
CATEGORIES=	lang linux java
MASTER_SITES=	http://www.jsoftware.com/download/
DISTNAME=	j${PORTVERSION}_linux32
DIST_SUBDIR=	${PORTNAME}/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A general purpose programming language

RUN_DEPENDS=	java:${PORTSDIR}/java/javavmwrapper

USE_LINUX=	yes
USE_JAVA=	yes
JAVA_VERSION=	1.3+

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
	${INSTALL_PROGRAM} ${WRKSRC}/j${PORTVERSION:S/b//g}/jconsole ${PREFIX}/lib/j/jconsole
	${BRANDELF} -t Linux ${PREFIX}/lib/j/jconsole

post-install:
.if !defined(BATCH)
	@${CAT} ${PKGMESSAGE}
.endif

.include <bsd.port.mk>
