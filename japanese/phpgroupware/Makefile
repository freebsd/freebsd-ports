# New ports collection makefile for:	phpgroupware
# Date created:        7 January 2001
# Whom:                Takeshi MUTOH <tmutoh@mx10.freecom.ne.jp>
#
# $FreeBSD$

PORTNAME=	phpgroupware
PORTVERSION=	0.9.12
CATEGORIES=	japanese deskutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
		${PATCH_SITE}
MASTER_SITE_SUBDIR=	phpgroupware
DISTNAME=	phpGroupWare-${PORTVERSION}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		${PATCHFILE}

MAINTAINER=	tmutoh@mx10.freecom.ne.jp

RUN_DEPENDS=	${LOCALBASE}/libexec/apache/libphp4.so:${PORTSDIR}/www/mod_php4

NO_BUILD=	yes
WRKSRC=		${WRKDIR}/phpgroupware

PATCHFILE=	phpGroupWare-${PORTVERSION}jp.tar.gz
PATCH_SITE=	http://www.itheart.com/en/phpgroupware/
EXTRA_PATCHES=	${WRKDIR}/patch.txt
PATCH_DIR=	${WRKDIR}/${PORTVERSION}jp
PATCH_STRIP=	-p1

post-extract:
		${FIND} ${WRKSRC} -name CVS -type d | ${XARGS} ${RM} -rf

post-patch:
		${FIND} ${WRKSRC} -name *.orig | ${XARGS} ${RM} -rf
		@${CP} ${PATCH_DIR}/phpgwapi/inc/class.codecv* ${WRKSRC}/phpgwapi/inc/
		@${CP} ${PATCH_DIR}/calendar/inc/class.holidaycalc* ${WRKSRC}/calendar/inc

do-install:
		@${CP} -r ${WRKSRC} ${PREFIX}/www/data/

.include <bsd.port.mk>
