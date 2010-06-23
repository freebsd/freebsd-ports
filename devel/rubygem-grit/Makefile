# Ports collection makefile for:	rubygem-grit
# Date created:				2008-11-05
# Whom:					Daniel Roethlisberger <daniel@roe.ch>
#
# $FreeBSD$

PORTNAME=	grit
PORTVERSION=	1.1.1
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	An object-oriented ruby library to access git repositories

RUN_DEPENDS=	rubygem-diff-lcs>=1.1.2:${PORTSDIR}/textproc/rubygem-diff-lcs \
		rubygem-mime-types>=1.15:${PORTSDIR}/misc/rubygem-mime-types

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.mk>
