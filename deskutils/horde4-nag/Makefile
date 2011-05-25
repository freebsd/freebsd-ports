# Ports collection makefile for:	nag
# Date created:			Sun Dec 14, 2001
# Whom:				Thierry Thomas (<thierry@pompo.net>)
#
# $FreeBSD$
#

PORTNAME=	nag
PORTVERSION=	3.0.1
DISTVERSIONPREFIX=
DISTVERSIONSUFFIX=
CATEGORIES=	deskutils www
MASTER_SITES=		http://pear.horde.org/get/ \
			LOCAL/beech
PKGNAMEPREFIX=	horde4-
EXTRACT_SUFX=	.tgz

MAINTAINER=	beech@FreeBSD.org
COMMENT=	Simple multiuser task list manager

CONFLICTS=	nag-2.*
USE_HORDE=	base
USE_GETTEXT=	yes
PORTDOCS=	README CHANGES CREDITS INSTALL \
		RELEASE_NOTES UPGRADING
LATEST_LINK=	horde4-nag

.include "${.CURDIR}/../../www/horde4-base/bsd.horde4.mk"
.include <bsd.port.mk>