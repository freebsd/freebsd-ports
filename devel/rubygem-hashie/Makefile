# Created by: Cheng-Lung Sung <clsung@FreeBSD.org>
# $FreeBSD$

PORTNAME=	hashie
PORTVERSION=	3.4.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

PATCHFILES=	09821f3c90755d019c5083174ab42f442e182767.diff
PATCH_SITES=	https://github.com/intridea/hashie/commit/
PATCH_DIST_STRIP=-p1 -S +	# We don't care to patch CHANGELOG.md

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Hashie is a simple collection of useful Hash extensions

LICENSE=	MIT

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=yes

.include <bsd.port.mk>
