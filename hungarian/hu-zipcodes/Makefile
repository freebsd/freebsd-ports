# New ports collection makefile for:	Hungary zipcodes
# Date created:         2002-06-22
# Whom:                 janos.mohacsi@bsd.hu
#
# $FreeBSD$
#

PORTNAME=	zipcodes
PORTVERSION=	20020622
CATEGORIES=	hungarian misc
MASTER_SITES=	http://freebsd.ik.bme.hu/~mohacsi/downloads/
PKGNAMEPREFIX=	hu-
DISTNAME=	iranyitoszamok.2002.06.22
EXTRACT_SUFX=	.gz

MAINTAINER=	janos.mohacsi@bsd.hu
COMMENT=	Postal codes in Hungary / Magyarorszagi iranyitoszamok

PLIST_FILES=	share/misc/hu.zipcodes
NO_WRKSUBDIR=	yes
EXTRACT_CMD=	${GZCAT}
EXTRACT_BEFORE_ARGS=	# None
EXTRACT_AFTER_ARGS=	> ${WRKSRC}/hu.zipcodes
NO_BUILD=	yes

do-install:
	${INSTALL_DATA} ${WRKSRC}/hu.zipcodes ${PREFIX}/share/misc/

.include <bsd.port.mk>
