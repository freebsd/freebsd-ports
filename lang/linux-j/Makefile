# New ports collection makefile for:   linux-j
# Date created:        29 September 2001
# Whom:                js@jeannot.org
#
# $FreeBSD$
#

PORTNAME=	linux-j
PORTVERSION=	501a
CATEGORIES=	lang linux
MASTER_SITES=	http://www.jsoftware.com/download/
DISTNAME=	j501a_linux
DIST_SUBDIR=    ${PORTNAME}/${PORTVERSION}

MAINTAINER=	js@jeannot.org

USE_LINUX=	yes

ONLY_FOR_ARCHS= i386

NO_WRKSUBDIR=	yes

MAN1=           jconsole.1

do-build:
	@sed "s:PREFIX:$(PREFIX):" < ${FILESDIR}/jconsole > ${WRKSRC}/jconsole

do-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/jconsole ${PREFIX}/bin
	@${INSTALL_MAN} ${WRKSRC}/j501a/system/extras/help/man/${MAN1} ${PREFIX}/man/man1
	@${MKDIR} ${PREFIX}/lib/j
	@cd ${WRKSRC}/j501a && tar -cf - system user profile.ijs readme.txt | tar -xf - -C ${PREFIX}/lib/j
	@${INSTALL_PROGRAM} ${WRKSRC}/j501a/jconsole ${PREFIX}/lib/j/jconsole
	@brandelf -t Linux ${PREFIX}/lib/j/jconsole

post-install:
.if !defined(BATCH)
	@${CAT} ${PKGMESSAGE}
.endif

.include <bsd.port.mk>
