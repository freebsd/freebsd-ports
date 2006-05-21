# New ports collection makefile for:	phpgroupware
# Date created:        27 March 2001
# Whom:                Jimmy Olgeni <olgeni@uli.it>
#
# $FreeBSD$

PORTNAME=	phpgroupware
PORTVERSION=	0.9.16.010
CATEGORIES=	deskutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	phpgroupware
DISTNAME=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	A web based GroupWare system

BROKEN=		Incorrect pkg-plist

USE_BZIP2=	yes
USE_PHP=	yes
WANT_PHP_MOD=	yes

NO_BUILD=	yes
WRKSRC=		${WRKDIR}/phpgroupware

post-extract:
		@${FIND} ${WRKSRC} -name CVS -type d | ${XARGS} ${RM} -rf

do-install:
		@${CP} -r ${WRKSRC} ${PREFIX}/www/data-dist/

.include <bsd.port.mk>
