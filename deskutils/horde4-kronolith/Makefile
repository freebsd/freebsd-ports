# Ports collection makefile for:  Kronolith
# Date created:			  Sun Dec 02, 2001
# Whom:				  Thierry Thomas (<thierry@thomas.as>)
#
# $FreeBSD$
#

PORTNAME=	kronolith
PORTVERSION=	3.0.2
DISTVERSIONPREFIX=
DISTVERSIONSUFFIX=
CATEGORIES=	deskutils www
MASTER_SITES=		http://pear.horde.org/get/ \
			LOCAL/beech
PKGNAMEPREFIX=	horde4-
EXTRACT_SUFX=	.tgz

MAINTAINER=	beech@FreeBSD.org
COMMENT=	Calendar application

RUN_DEPENDS+=	${LOCALBASE}/share/pear/Date/Holidays.php:${PORTSDIR}/devel/pear-Date_Holidays \
		${HORBAS}/Rdo.php:${PORTSDIR}/devel/horde4-rdo \
		${HORBAS}/content/Application.php:${PORTSDIR}/devel/horde4-content

CONFLICTS=	kronolith-2.*
USE_HORDE=	base
USE_GETTEXT=	yes
PORTDOCS=	README CHANGES CREDITS INSTALL RELEASE_NOTES UPGRADING TODO \
		lighttpd-kronolith.conf

.include "${.CURDIR}/../../www/horde4-base/bsd.horde4.mk"
.include <bsd.port.mk>
