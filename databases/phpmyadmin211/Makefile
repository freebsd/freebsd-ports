# New ports collection makefile for: phpMyAdmin
# Date created:		19 Jan 2001
# Whom:			nbm
#
# $FreeBSD$
#

PORTNAME=	phpMyAdmin
PORTVERSION=	2.5.6
CATEGORIES=	databases www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	phpmyadmin

MAINTAINER=	m.seaman@infracaninophile.co.uk
COMMENT=	A set of PHP-scripts to adminster MySQL over the web

USE_BZIP2=	yes
USE_PHP=	yes
NO_BUILD=	yes

MYADMDIR?=	www/data/phpMyAdmin

PLIST_SUB+=	MYADMDIR=${MYADMDIR}

post-patch:
	@${MV} ${WRKSRC}/config.inc.php ${WRKSRC}/config.inc.php.sample

do-install:
	@${MKDIR} ${PREFIX}/${MYADMDIR}
	@${FIND} ${WRKSRC} ! -path '*/CVS*' ! -path '*/.cvsignore' | \
		${XARGS} -n1 ${SH} -c 'if ${TEST} -d $$0; \
			then ${MKDIR} ${PREFIX}/${MYADMDIR}$${0#${WRKSRC}}; \
			else ${INSTALL_DATA} $$0 ${PREFIX}/${MYADMDIR}$${0#${WRKSRC}}; fi'

.include <bsd.port.mk>
