# New ports collection makefile for:	phpgroupware
# Date created:        27 March 2001
# Whom:                Jimmy Olgeni <olgeni@uli.it>
#
# $FreeBSD$

PORTNAME=	phpgroupware
PORTVERSION=	0.9.12
CATEGORIES=	deskutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	phpgroupware
DISTNAME=	phpGroupWare-${PORTVERSION}

MAINTAINER=	olgeni@FreeBSD.org

RUN_DEPENDS=	${LOCALBASE}/libexec/apache/libphp4.so:${PORTSDIR}/www/mod_php4

NO_BUILD=	yes
WRKSRC=		${WRKDIR}/phpgroupware

post-extract:
		find ${WRKSRC} -name CVS -type d | xargs ${RM} -rf

do-install:
		@${CP} -r ${WRKSRC} ${PREFIX}/www/data.default/

.include <bsd.port.mk>
