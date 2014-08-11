# Created by: Beech Rintoul <horde@FreeBSD.org
# $FreeBSD$

PORTNAME=	hermes
PORTVERSION=	1.0.1
PORTREVISION=	4
CATEGORIES=	deskutils www

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Time tracking application

USE_HORDE=	base pkg-message
USES=		gettext
PORTDOCS=	README CHANGES CREDITS INSTALL TODO

BUILD_DEPENDS+=	${HORBAS}/turba/minisearch.php:${PORTSDIR}/mail/horde3-turba \
		${HORBAS}/nag/data.php:${PORTSDIR}/deskutils/horde3-nag \
		${HORBAS}/whups/index.php:${PORTSDIR}/devel/horde3-whups

NO_STAGE=	yes
.include "${.CURDIR}/../../www/horde3-base/bsd.horde.mk"
.include <bsd.port.mk>
