# New ports collection makefile for:   linux-j
# Date created:        29 September 2001
# Whom:                js@jeannot.org
#
# $FreeBSD$
#

PORTNAME=	linux-j
PORTVERSION=	502a
PORTREVISION=	2
CATEGORIES=	lang linux
MASTER_SITES=	http://www.jsoftware.com/download/
DISTNAME=	j${PORTVERSION}_linux
DIST_SUBDIR=    ${PORTNAME}/${PORTVERSION}

MAINTAINER=	js@jeannot.org
COMMENT=	A general purpose programming language

BROKEN=		Unfetchable

USE_LINUX?=	yes
USE_JAVA=	1.3+

ONLY_FOR_ARCHS= i386

NO_WRKSUBDIR=	yes

MAN1=           jconsole.1

do-build:
	@${SED} "s:PREFIX:$(PREFIX):g" < ${FILESDIR}/jconsole > ${WRKSRC}/jconsole
	@${SED} "s:PREFIX:$(PREFIX):g" < ${FILESDIR}/jw > ${WRKSRC}/jw

do-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/jconsole ${PREFIX}/bin
	@${INSTALL_SCRIPT} ${WRKSRC}/jw ${PREFIX}/bin
	@${INSTALL_MAN} ${WRKSRC}/j502a/system/extras/help/man/${MAN1} ${PREFIX}/man/man1
	@${MKDIR} ${PREFIX}/lib/j
	@cd ${WRKSRC}/j502a && \
		${TAR} -cf - system user profile.ijs readme.txt j.jar | \
			${TAR} -xf - -C ${PREFIX}/lib/j
	@${INSTALL_PROGRAM} ${WRKSRC}/j502a/jconsole ${PREFIX}/lib/j/jconsole
	@brandelf -t Linux ${PREFIX}/lib/j/jconsole

post-install:
.if !defined(BATCH)
	@${CAT} ${PKGMESSAGE}
.endif

.include <bsd.port.mk>
