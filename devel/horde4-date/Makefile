# Ports collection makefile for:  horde4-date
# Date created:			  Tue May 24, 2011
# Whom:				  Beech Rintoul (<beech@FreeBSD.org>)
#
# $FreeBSD$
#

PORTNAME=	date
PORTVERSION=	1.0.1
DISTVERSIONPREFIX=
DISTVERSIONSUFFIX=
CATEGORIES=	devel www
MASTER_SITES=		http://pear.horde.org/get/ \
			LOCAL/beech
PKGNAMEPREFIX=	horde4-
DISTNAME=	Horde_Date-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	beech@FreeBSD.org
COMMENT=	Horde date package

BROKEN=		Rewrite in progress
USE_HORDE=	base
USE_GETTEXT=	yes
DATEDIR=	Date
HORDIR+=	${HORBAS}${DATEDIR:S|^|/|:S|/horde||}

post-extract:
	@${MKDIR} ${WRKSRC}/config && ${TOUCH} ${WRKSRC}/config/placeholder.dist

do-install:
	@${CP} -Rp ${WRKSRC}/lib/Horde/Date.php ${HORBAS}/
	@${CP} -Rp ${WRKSRC}/lib/Horde/Date/ ${HORDIR}/
	@${ECHO_CMD} @exec ${CHOWN} -R ${WWWOWN}:${WWWGRP} %D/${HORDIR:S|^${PREFIX}/||}/ >> ${TMPPLIST}
	@${ECHO_CMD} @exec ${CHMOD} -R o-rwx %D/${HORDIR:S|^${PREFIX}/||}/ >> ${TMPPLIST}
	@${ECHO_CMD} "@exec ${TOUCH} ${HORLOG};${CHOWN} ${WWWOWN}:${WWWGRP} ${HORLOG}" >> ${TMPPLIST}
	@${ECHO_MSG}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_MSG}

.include "${.CURDIR}/../../www/horde4-base/bsd.horde4.mk"
.include <bsd.port.mk>
