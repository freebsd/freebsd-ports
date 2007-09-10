# New ports collection makefile for:	xfce4-dev-tools
# Date created:		19 April 2006
# Whom:			Oliver Lehmann <oliver@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	xfce4-dev-tools
PORTVERSION=	4.4.0
PORTREVISION=	1
CATEGORIES=	devel xfce
MASTER_SITES=	${MASTER_SITES_XFCE}
DIST_SUBDIR=	xfce4

MAINTAINER=	oliver@FreeBSD.org
COMMENT=	XFce 4 development tools

USE_AUTOTOOLS=	autotools:run
GNU_CONFIGURE=	yes
USE_BZIP2=	yes
USE_XFCE=	configenv	# to get MASTER_SITE_SUBDIR something has to be defined

.include <bsd.port.mk>
