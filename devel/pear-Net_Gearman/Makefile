# New ports collection makefile for:	php-Net_Gearman
# Date created:		2008-01-10
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	Net_Gearman
PORTVERSION=	0.2.3
CATEGORIES=	devel pear

MAINTAINER=	gslin@gslin.org
COMMENT=	Gearman client libraray for PHP

BUILD_DEPENDS=	${LOCALBASE}/share/pear/PEAR.php:${PORTSDIR}/devel/pear
RUN_DEPENDS:=	${BUILD_DEPENDS}

USE_PHP=	json mbstring

FILES=		Net/Gearman/Client.php Net/Gearman/Connection.php Net/Gearman/Exception.php \
		Net/Gearman/Job.php Net/Gearman/Manager.php Net/Gearman/Set.php \
		Net/Gearman/Task.php Net/Gearman/Worker.php \
		Net/Gearman/Job/Common.php Net/Gearman/Job/Exception.php
EXAMPLES=	SQL.php Sum.php tasks.php worker.php

.include <bsd.port.pre.mk>

.include "${PORTSDIR}/devel/pear/bsd.pear.mk"

.include <bsd.port.post.mk>
