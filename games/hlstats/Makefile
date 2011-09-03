# New ports collection makefile for:	HLStats
# Date created:				26 December 2003
# Whom:					Hideki Machida <hido@neojapangz.com>
#
# $FreeBSD$
#

PORTNAME=	hlstats
PORTVERSION=	1.62
CATEGORIES=	games www
MASTER_SITES=	http://www.hlstats-community.org/wordpulse/site/hlscom/upload/Multimedia/download/${PORTVERSION}/
DISTNAME=	HLStats-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A real-time statistics generator for Half-Life and its mods

LICENSE=	CDDL

RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/DBD/mysql.pm:${PORTSDIR}/databases/p5-DBD-mysql

NO_BUILD=	yes
NO_WRKSUBDIR=	yes
USE_PHP=	yes
USE_PERL5_RUN=	yes
HLSTATS?=	www/${PORTNAME}
PLIST_SUB+=	HLSTATS=${HLSTATS}

do-install:
	@${MKDIR} ${PREFIX}/${HLSTATS}
	cd ${WRKSRC} && ${TAR} cf - ChangeLog README* [a-z]* | ${TAR} xf - \
		-C ${PREFIX}/${HLSTATS}

.include <bsd.port.mk>
