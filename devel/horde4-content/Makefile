# Ports collection makefile for:  horde4-content
# Date created:			  Mon May 23, 2011
# Whom:				  Beech Rintoul (<beech@FreeBSD.org>)
#
# $FreeBSD$
#

PORTNAME=	content
PORTVERSION=	1.0.0
DISTVERSIONPREFIX=
DISTVERSIONSUFFIX=
CATEGORIES=	devel www
MASTER_SITES=		http://pear.horde.org/get/ \
			LOCAL/beech
PKGNAMEPREFIX=	horde4-
DISTNAME=	content-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	beech@FreeBSD.org
COMMENT=	Horde tagging application

BROKEN=		Rewrite in progress
USE_HORDE=	base
USE_GETTEXT=	yes

post-extract:
	@${MKDIR} ${WRKSRC}/config && ${TOUCH} ${WRKSRC}/config/placeholder.dist

do-install:
	@${INSTALL} -d ${HORDIR}/
#	@${CP} ${WRKSRC}/lib/Horde/content.php ${HORBAS}/
	@${CP} -Rp ${WRKSRC}/app/ ${HORDIR}/
	@${CP} -Rp ${WRKSRC}/config/ ${HORDIR}/
	@${CP} -Rp ${WRKSRC}/lib/ ${HORDIR}/
	@${CP} -Rp ${WRKSRC}/migration/ ${HORDIR}/	
	@${ECHO_CMD} @exec ${CHOWN} -R ${WWWOWN}:${WWWGRP} %D/${HORDIR:S|^${PREFIX}/||}/ >> ${TMPPLIST}
	@${ECHO_CMD} @exec ${CHMOD} -R o-rwx %D/${HORDIR:S|^${PREFIX}/||}/ >> ${TMPPLIST}
	@${ECHO_CMD} "@exec ${TOUCH} ${HORLOG};${CHOWN} ${WWWOWN}:${WWWGRP} ${HORLOG}" >> ${TMPPLIST}

	@${ECHO_MSG}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_MSG}

.include "${.CURDIR}/../../www/horde4-base/bsd.horde4.mk"
.include <bsd.port.mk>
