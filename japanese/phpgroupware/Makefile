# New ports collection makefile for:	phpgroupware
# Date created:        7 January 2001
# Whom:                Takeshi MUTOH <tmutoh@mx10.freecom.ne.jp>
#
# $FreeBSD$

PORTNAME=	phpgroupware
PORTVERSION=	0.9.16.003
CATEGORIES=	japanese deskutils
MASTER_SITES=   ${MASTER_SITE_SOURCEFORGE_JP}
MASTER_SITE_SUBDIR=     phpgwjp/12593
DISTNAME=	phpgroupware-jp-${PORTVERSION}-pre1
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		phpgroupware-doc-jp-${PORTVERSION}-pre1${EXTRACT_SUFX}

MAINTAINER=	mutoh@openedu.org
COMMENT=	A web based GroupWare system

NO_BUILD=	yes
WRKSRC=		${WRKDIR}/phpgroupware
INSTALLDIR=	${PREFIX}/www/data/phpgroupware

USE_PHP=	mbstring
USE_BZIP2=	yes

do-install:
		@${CP} -r ${WRKSRC} ${PREFIX}/www/data/
		@${CHOWN} -R www:www ${INSTALLDIR}
		@${CHMOD} -R 770 ${INSTALLDIR}

.include <bsd.port.mk>
