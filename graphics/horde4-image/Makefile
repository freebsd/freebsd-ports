# Ports collection makefile for:  horde4-image
# Date created:			  Mon May 23, 2011
# Whom:				  Beech Rintoul (<beech@FreeBSD.org>)
#
# $FreeBSD$
#

PORTNAME=	image
PORTVERSION=	1.0.1
DISTVERSIONPREFIX=
DISTVERSIONSUFFIX=
PORTREVISION=	1
CATEGORIES=	graphics www
MASTER_SITES=		http://pear.horde.org/get/ \
			LOCAL/beech
PKGNAMEPREFIX=	horde4-
DISTNAME=	Horde_Image-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	beech@FreeBSD.org
COMMENT=	Horde Image API, with backends for various image formats

USE_HORDE=	base
USE_GETTEXT=	yes
IMAGEDIR=	Image
HORDIR=		${HORBAS}${IMAGEDIR:S|^|/|:S|/horde||}

RUN_DEPENDS+=	${PEARDIR}/XML/SVG.php:${PORTSDIR}/devel/pear-XML_SVG

post-extract:
	@${MKDIR} ${WRKSRC}/config && touch ${WRKSRC}/config/placeholder.dist

do-install:
	@${INSTALL} -d ${HORDIR}/
	@${CP} ${WRKSRC}/lib/Horde/Image.php ${HORBAS}/
	@${CP} -Rp ${WRKSRC}/lib/Horde/Image/ ${HORDIR}/
	@${ECHO_CMD} @exec ${CHOWN} -R ${WWWOWN}:${WWWGRP} %D/${HORDIR:S|^${PREFIX}/||}/ >> ${TMPPLIST}
	@${ECHO_CMD} @exec ${CHMOD} -R o-rwx %D/${HORDIR:S|^${PREFIX}/||}/ >> ${TMPPLIST}
	@${ECHO_CMD} "@exec ${TOUCH} ${HORLOG};${CHOWN} ${WWWOWN}:${WWWGRP} ${HORLOG}" >> ${TMPPLIST}

	@${ECHO_MSG}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_MSG}

.include "${.CURDIR}/../../www/horde4-base/bsd.horde4.mk"
.include <bsd.port.mk>
