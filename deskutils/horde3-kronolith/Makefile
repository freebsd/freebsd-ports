# Created by: Thierry Thomas (<thierry@thomas.as>)
# $FreeBSD$

PORTNAME=	kronolith
PORTVERSION=	2.3.6
DISTVERSIONSUFFIX=
PORTREVISION=	2
PORTEPOCH=	1
CATEGORIES=	deskutils www

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Calendar application

RUN_DEPENDS=	${LOCALBASE}/share/pear/Date/Holidays.php:${PORTSDIR}/devel/pear-Date_Holidays

USE_HORDE=	base
USES=		gettext
PORTDOCS=	README CHANGES CREDITS INSTALL RELEASE_NOTES TODO UPGRADING

NO_STAGE=	yes
.include "${.CURDIR}/../../www/horde3-base/bsd.horde.mk"
.include <bsd.port.mk>
