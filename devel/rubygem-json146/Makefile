# $FreeBSD$

## XXX: Legacy for rubygem DM ports

PORTNAME=	json
PORTVERSION=	1.4.6
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Parse JSON texts and generate them from ruby data structures

PORTSCOUT=	limit:^1.4
NO_LATEST_LINK=	yes

PKGNAMESUFFIX=	146

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes
PLIST_FILES=	bin/edit_json.rb bin/prettify_json.rb

DEPRECATED=	Old version no longer required by dependencies
EXPIRATION_DATE=	2014-08-28

.include <bsd.port.mk>
