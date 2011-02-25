# Ports collection makefile for:  Kronolith
# Date created:			  Sun Dec 02, 2001
# Whom:				  Thierry Thomas (<thierry@thomas.as>)
#
# $FreeBSD$
#

PORTNAME=	kronolith
PORTVERSION=	2.3.5
DISTVERSIONSUFFIX=
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	deskutils www

MAINTAINER=	beech@FreeBSD.org
COMMENT=	Calendar application

RUN_DEPENDS=	${LOCALBASE}/share/pear/Date/Holidays.php:${PORTSDIR}/devel/pear-Date_Holidays

USE_HORDE=	base
USE_GETTEXT=	yes
PORTDOCS=	README CHANGES CREDITS INSTALL RELEASE_NOTES TODO UPGRADING

.include "${.CURDIR}/../../www/horde-base/bsd.horde.mk"
.include <bsd.port.mk>
