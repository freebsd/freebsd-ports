# Ports collection makefile for:  horde4-dateparser
# Date created:			  Tue May 24, 2011
# Whom:				  Beech Rintoul (<beech@FreeBSD.org>)
#
# $FreeBSD$
#

PORTNAME=	dateparser
PORTVERSION=	1.0.0
DISTVERSIONPREFIX=
DISTVERSIONSUFFIX=
CATEGORIES=	devel www
MASTER_SITES=		http://pear.horde.org/get/ \
			LOCAL/beech
PKGNAMEPREFIX=	horde4-
DISTNAME=	Horde_Date_Parser-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	beech@FreeBSD.org
COMMENT=	Library for natural-language date parsing

BROKEN=		Rewrite in progress
USE_HORDE=	base
USE_GETTEXT=	yes
DATEDIR=	Date
HORDIR+=	${HORBAS}${DATEDIR:S|^|/|:S|/horde||}
EXAMPLESDIR=	${PREFIX}/share/examples/horde

RUN_DEPENDS+=	${HORBAS}/Date.php:${PORTSDIR}/devel/horde4-date

post-extract:
	@${MKDIR} ${WRKSRC}/config && ${TOUCH} ${WRKSRC}/config/placeholder.dist

do-install:
	@${INSTALL} -d ${HORDIR}/
	@${INSTALL} -d ${EXAMPLESDIR}/
	@${CP} ${WRKSRC}/lib/Horde/Date/Parser.php ${HORDIR}/
	@${CP} -Rp ${WRKSRC}/lib/Horde/Date/Parser ${HORDIR}/
	cd ${WRKSRC}/examples/Horde/ && ${COPYTREE_SHARE} Date ${EXAMPLESDIR}
	@${ECHO_CMD} @exec ${CHOWN} -R ${WWWOWN}:${WWWGRP} %D/${HORDIR:S|^${PREFIX}/||}/ >> ${TMPPLIST}
	@${ECHO_CMD} @exec ${CHMOD} -R o-rwx %D/${HORDIR:S|^${PREFIX}/||}/ >> ${TMPPLIST}
	@${ECHO_CMD} "@exec ${TOUCH} ${HORLOG};${CHOWN} ${WWWOWN}:${WWWGRP} ${HORLOG}" >> ${TMPPLIST}

	@${ECHO_MSG}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_MSG}

.include "${.CURDIR}/../../www/horde4-base/bsd.horde4.mk"
.include <bsd.port.mk>
