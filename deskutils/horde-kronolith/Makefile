# Ports collection makefile for:  Kronolith
# Date created:			  Sun Dec 02, 2001
# Whom:				  Thierry Thomas (<thierry@thomas.as>)
#
# $FreeBSD$
#

PORTNAME=	kronolith
PORTVERSION=	2.3.4
DISTVERSIONSUFFIX=
PORTEPOCH=	1
CATEGORIES=	deskutils www

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Calendar application

USE_HORDE=	base
USE_GETTEXT=	yes
PORTDOCS=	README CHANGES CREDITS INSTALL RELEASE_NOTES TODO UPGRADING
RUN_DEPENDS=	${LOCALBASE}/share/pear/Date/Holidays.php:${PORTSDIR}/devel/pear-Date_Holidays

.include "${.CURDIR}/../../www/horde-base/bsd.horde.mk"
.include <bsd.port.mk>
