# Created by: courou <courou@users.sourceforge.net>
# $FreeBSD$

PORTNAME=	myphpmoney
PORTVERSION=	1.3.r3
PORTEPOCH=	1
CATEGORIES=	finance www
MASTER_SITES=	SF/${PORTNAME}/MyPhpMoney/1.3RC3
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.r/RC/}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	PHP script for managing your accounts

WEBOWN?=	www
WEBGRP?=	www
APACHEDIR=	${PREFIX}/www/data
INSTALLDIR=	${APACHEDIR}/myphpmoney
USES=		php:web tar:bzip2
NO_BUILD=	yes

PLIST_SUB+=	INSTALLDIR=${INSTALLDIR:S,^${PREFIX}/,,} WWWOWN="${WEBOWN}" WWWGRP="${WEBGRP}"

do-install:
	${MKDIR} ${STAGEDIR}${INSTALLDIR}
	cd ${WRKSRC}; ${FIND} .  | ${CPIO} -pdm ${STAGEDIR}${INSTALLDIR}
	${CHMOD} -R ${BINMODE} ${STAGEDIR}${INSTALLDIR}
	${CHMOD} 777 ${STAGEDIR}${INSTALLDIR}/public_html/dump
	${FIND} ${STAGEDIR}${INSTALLDIR} ! -type d | ${XARGS} ${CHMOD} ${NOBINMODE}

.include <bsd.port.mk>
