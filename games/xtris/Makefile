# New ports collection makefile for:    xtris
# Date created:         24. Sep 97
# Whom:                 sec@42.org
#
# $FreeBSD$
#

PORTNAME=	xtris
PORTVERSION=	1.15
CATEGORIES=	games ipv6
MASTER_SITES=	http://www.iagora.com/~espel/xtris/

PATCH_SITES=	ftp://ftp.42.org/pub/orphan/	
PATCHFILES=	xtris-1.15-v6-19991218.diff.gz
PATCH_DIST_STRIP=	-p1

MAINTAINER=	sec@42.org
COMMENT=	A multi-player version of a popular game for the X Window system

RESTRICTED=	"Possible trademark infringement"
WRKSRC=		${WRKDIR}/xtris

USE_X_PREFIX=	yes
MAN6=		xtris.6 xtserv.6 xtbot.6

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 400014
MAKE_ENV=	IPV6_CFLAGS="-DINET6"
.endif

.include <bsd.port.post.mk>
