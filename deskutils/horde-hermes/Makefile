# Ports collection makefile for:  horde-hermes
# Date created:			  Jul 20, 2008
# Whom:				  Beech Rintoul <beech@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	hermes
DISTVERSION=	1.0-rc1
CATEGORIES=	deskutils www

MAINTAINER=	beech@FreeBSD.org
COMMENT=	Time tracking application

USE_HORDE=	base pkg-message
USE_GETTEXT=	yes
PORTDOCS=	README CHANGES CREDITS INSTALL TODO

BUILD_DEPENDS+=	${LOCALBASE}/www/horde/turba/minisearch.php:${PORTSDIR}/mail/horde-turba \
		${LOCALBASE}/www/horde/nag/data.php:${PORTSDIR}/deskutils/horde-nag \
		${LOCALBASE}/www/horde/whups/index.php:${PORTSDIR}/devel/horde-whups

.include "${.CURDIR}/../../www/horde-base/bsd.horde.mk"
.include <bsd.port.mk>
