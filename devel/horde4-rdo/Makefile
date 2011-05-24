# Ports collection makefile for:  horde4-rdo
# Date created:			  Mon May 23, 2011
# Whom:				  Beech Rintoul (<beech@FreeBSD.org>)
#
# $FreeBSD$
#

PORTNAME=	rdo
PORTVERSION=	1.0.0
DISTVERSIONPREFIX=
DISTVERSIONSUFFIX=
PORTREVISION=	1
CATEGORIES=	devel www
MASTER_SITES=		http://pear.horde.org/get/ \
			LOCAL/beech
PKGNAMEPREFIX=	horde4-
DISTNAME=	Horde_Rdo-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	beech@FreeBSD.org
COMMENT=	Rampage data objects

USE_HORDE=	base
USE_GETTEXT=	yes
RDODIR=		Rdo
HORDIR=		${HORBAS}${RDODIR:S|^|/|:S|/horde||}
EXAMPLESDIR=	${PREFIX}/share/examples/horde

post-extract:
	@${MKDIR} ${WRKSRC}/config && ${TOUCH} ${WRKSRC}/config/placeholder.dist

do-install:
	@${INSTALL} -d ${HORDIR}/
	@${INSTALL} -d ${EXAMPLESDIR}/
	@${CP} ${WRKSRC}/lib/Horde/Rdo.php ${HORBAS}/
	@${CP} -Rp ${WRKSRC}/lib/Horde/Rdo/ ${HORDIR}/
	@ cd ${WRKSRC}/examples/Horde/ && ${COPYTREE_SHARE} Rdo ${EXAMPLESDIR}
	@${ECHO_CMD} @exec ${CHOWN} -R ${WWWOWN}:${WWWGRP} %D/${HORDIR:S|^${PREFIX}/||}/ >> ${TMPPLIST}
	@${ECHO_CMD} @exec ${CHMOD} -R o-rwx %D/${HORDIR:S|^${PREFIX}/||}/ >> ${TMPPLIST}
	@${ECHO_CMD} "@exec ${TOUCH} ${HORLOG};${CHOWN} ${WWWOWN}:${WWWGRP} ${HORLOG}" >> ${TMPPLIST}

	@${ECHO_MSG}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_MSG}

.include "${.CURDIR}/../../www/horde4-base/bsd.horde4.mk"
.include <bsd.port.mk>
