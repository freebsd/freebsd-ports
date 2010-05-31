# Ports collection makefile for:  horde-hermes
# Date created:			  Jul 20, 2008
# Whom:				  Beech Rintoul <beech@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	hermes
PORTVERSION=	1.0.1
PORTREVISION=	1
CATEGORIES=	deskutils www

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Time tracking application

USE_HORDE=	base pkg-message
USE_GETTEXT=	yes
PORTDOCS=	README CHANGES CREDITS INSTALL TODO

BUILD_DEPENDS+=	${HORBAS}/turba/minisearch.php:${PORTSDIR}/mail/horde-turba \
		${HORBAS}/nag/data.php:${PORTSDIR}/deskutils/horde-nag \
		${HORBAS}/whups/index.php:${PORTSDIR}/devel/horde-whups

.include "${.CURDIR}/../../www/horde-base/bsd.horde.mk"
.include <bsd.port.mk>
