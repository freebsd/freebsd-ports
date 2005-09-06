# New ports collection makefile for:	oracle8-client
# Date created:				8 Aug 2005
# Whom:					Max Khon <fjoe@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	oracle8-client
PORTVERSION=	0.1.1
PORTREVISION=	1
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	fjoe

MAINTAINER=	fjoe@FreeBSD.org
COMMENT=	Oracle 8 client

USE_BZIP2=	yes
ONLY_FOR_ARCHS=	i386
WRKSRC=		${WRKDIR}/${PORTNAME}
ORACLE_HOME=	${PREFIX}/${PORTNAME}

NO_BUILD=	yes

do-install:
	@${MKDIR} ${ORACLE_HOME}
	cd ${WRKSRC} && ${FIND} . -print0 | ${CPIO} -dump0 -R ${SHAREOWN}:${SHAREGRP} ${ORACLE_HOME}

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
post-patch:
	@cd ${WRKSRC}/freebsd && ${MAKE} all patch clean ORACLE_HOME=${WRKSRC}
.endif

.include <bsd.port.post.mk>
