# New ports collection makefile for:   hlstats
# Date created:        26 December 2003
# Whom:                hideki
#
# $FreeBSD$
#

PORTNAME=	hlstats
PORTVERSION=	1.20
CATEGORIES=	games www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	hido@coreblack.com
COMMENT=	A real-time stats parser for Half Life & its mods

RUN_DEPENDS=	php-config:${PORTSDIR}/www/mod_php4 \
		${SITE_PERL}/${PERL_ARCH}/Mysql.pm:${PORTSDIR}/databases/p5-DBD-mysql

NO_BUILD=	yes
USE_APACHE=	yes
USE_PERL5_RUN=	yes

do-install:
	@ ${MKDIR} ${PREFIX}/www/data/${PORTNAME}
	@ ${CP} -R ${WRKSRC}/* ${PREFIX}/www/data/${PORTNAME}
	@ ${ECHO_MSG} "*"
	@ ${ECHO_MSG} "* Files have been installed in"
	@ ${ECHO_MSG} "* ${PREFIX}/www/data/${PORTNAME}"
	@ ${ECHO_MSG} "*"
	@ ${ECHO_MSG} "* Visit http://docs.unitedadmins.com/HLstats/ for instructions on getting it running."
	@ ${ECHO_MSG} "*"

.include <bsd.port.mk>
