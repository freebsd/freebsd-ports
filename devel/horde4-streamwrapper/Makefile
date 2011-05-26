# Ports collection makefile for:  horde4-streamwrapper
# Date created:			  Thu May 26, 2011
# Whom:				  Beech Rintoul (<beech@FreeBSD.org>)
#
# $FreeBSD$
#

PORTNAME=	streamwrapper
PORTVERSION=	1.0.0
DISTVERSIONPREFIX=
DISTVERSIONSUFFIX=
CATEGORIES=	devel www
MASTER_SITES=		http://pear.horde.org/get/ \
			LOCAL/beech
PKGNAMEPREFIX=	horde4-
DISTNAME=	Horde_Stream_Wrapper-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	beech@FreeBSD.org
COMMENT=	This port provides various stream wrappers

RUN_DEPENDS+=	${HORBAS}/Stream/Filter/Eol.php:${PORTSDIR}/devel/horde4-streamfilter
USE_HORDE=	base
USE_GETTEXT=	yes
STWDIR=		Stream
HORDIR+=	${HORBAS}${STWDIR:S|^|/|:S|/horde||}

post-extract:
	@${MKDIR} ${WRKSRC}/config && ${TOUCH} ${WRKSRC}/config/placeholder.dist

do-install:
	@${CP} -Rp ${WRKSRC}/lib/Horde/Stream/ ${HORDIR}/
	@${ECHO_CMD} @exec ${CHOWN} -R ${WWWOWN}:${WWWGRP} %D/${HORDIR:S|^${PREFIX}/||}/ >> ${TMPPLIST}
	@${ECHO_CMD} @exec ${CHMOD} -R o-rwx %D/${HORDIR:S|^${PREFIX}/||}/ >> ${TMPPLIST}
	@${ECHO_CMD} "@exec ${TOUCH} ${HORLOG};${CHOWN} ${WWWOWN}:${WWWGRP} ${HORLOG}" >> ${TMPPLIST}
	@${ECHO_MSG}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_MSG}

.include "${.CURDIR}/../../www/horde4-base/bsd.horde4.mk"
.include <bsd.port.mk>
