# New ports collection makefile for:	nspmod-0.1
# Version required:			0.1
# Date created:				1 Jun 1997
# Whom:					jmg
#
#	$Id$
#

DISTNAME=	nspmod-0.1
CATEGORIES=	audio
MASTER_SITE_SUBDIR=	apps/sound/players
MASTER_SITES=	http://www.jeton.or.jp/users/toru/www/orgsoft/nspmod/	\
		${MASTER_SITE_SUNSITE}

MAINTAINER=	jmg@FreeBSD.ORG

MAN1=		nspmod.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/nspmod ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/nspmod.1 ${MANPREFIX}/man/man1

.include <bsd.port.mk>
