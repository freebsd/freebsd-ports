# New ports collection makefile for:	Ruby replacement for json
# Date created:		June 23, 2011
# Whom:			Philip M. Gollucci <pgollucci@p6m7g8.com>
#
# $FreeBSD$
#

## XXX: Legacy for rubygem DM ports

PORTNAME=	json
PORTVERSION=	1.4.6
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Parse JSON texts and generate them from ruby data structures

DEPRECATED=	No longer needed to support DM ports
EXPIRATION_DATE=2011-11-27

PORTSCOUT=	limit:^1.4
NO_LATEST_LINK=	yes

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes
PLIST_FILES=	bin/edit_json.rb bin/prettify_json.rb

.include <bsd.port.mk>
