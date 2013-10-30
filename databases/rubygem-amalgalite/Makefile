# Created by: Eric Freeman <freebsdports@chillibear.com>
# $FreeBSD$

PORTNAME=	amalgalite
PORTVERSION=	1.1.2
CATEGORIES=	databases rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Embeds the SQLite database engine in a Ruby extension

RUN_DEPENDS=	rubygem-arrayfields>=4.7.4:${PORTSDIR}/devel/rubygem-arrayfields \
		rubygem-fastercsv>=1.5.4:${PORTSDIR}/devel/rubygem-fastercsv

USE_RUBY=		yes
USE_RUBYGEMS=		yes
RUBYGEM_AUTOPLIST=	yes

PLIST_FILES=	bin/amalgalite-pack

.include <bsd.port.mk>
