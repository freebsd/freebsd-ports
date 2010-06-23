# New ports collection makefile for:	Ditz
# Date created:		8 Mar 2009
# Whom:			Jun Kuriyama <kuriyama@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	ditz
PORTVERSION=	0.5
PORTREVISION=	1
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Simple, light-weight distributed issue tracker

RUN_DEPENDS=	rubygem-trollop>0:${PORTSDIR}/devel/rubygem-trollop

USE_RUBY=	yes
USE_RAKE=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes
PLIST_FILES=	bin/ditz

.include <bsd.port.mk>
