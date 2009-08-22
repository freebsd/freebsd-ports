# New ports collection makefile for:   hlstats
# Date created:        26 December 2003
# Whom:                hideki
#
# $FreeBSD$
#

PORTNAME=	hlstats
PORTVERSION=	1.38
CATEGORIES=	games www
MASTER_SITES=	SF/${PORTNAME}/HLstats/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A real-time stats parser for Half Life & its mods

RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/DBD/mysql.pm:${PORTSDIR}/databases/p5-DBD-mysql

NO_BUILD=	yes
USE_PHP=	yes
USE_PERL5_RUN=	yes
HLSTATS?=	www/${PORTNAME}
PLIST_SUB+=	HLSTATS=${HLSTATS}

do-install:
	@ ${MKDIR} ${PREFIX}/${HLSTATS}
	@ ${CP} -R ${WRKSRC}/* ${PREFIX}/${HLSTATS}
	@ ${ECHO_MSG} "*"
	@ ${ECHO_MSG} "* Files have been installed in"
	@ ${ECHO_MSG} "* ${PREFIX}/${HLSTATS}"
	@ ${ECHO_MSG} "*"
	@ ${ECHO_MSG} "* Visit http://docs.unitedadmins.com/HLstats/ for instructions on getting it running."
	@ ${ECHO_MSG} "*"

.include <bsd.port.mk>
