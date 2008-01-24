# New ports collection makefile for:	php-Net_Gearman
# Date created:		2008-01-10
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	Net_Gearman
PORTVERSION=	0.0.4
CATEGORIES=	devel
MASTER_SITES=	http://bugs.joestump.net/code/Net_Gearman/
PKGNAMEPREFIX=	php-
EXTRACT_SUFX=	.tgz

MAINTAINER=	gslin@gslin.org
COMMENT=	Gearman client libraray for PHP

RUN_DEPENDS=	${LOCALBASE}/share/pear/PEAR.php:${PORTSDIR}/devel/pear

NO_BUILD=	yes
USE_PHP=	yes

do-install:
	${MKDIR} ${DATADIR}
	${CP} -R ${WRKSRC}/Net ${DATADIR}
	${MKDIR} ${EXAMPLESDIR}
	${CP} -R ${WRKSRC}/examples/ ${EXAMPLESDIR}

.include <bsd.port.mk>
