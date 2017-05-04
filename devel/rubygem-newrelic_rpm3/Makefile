# $FreeBSD$

PORTNAME=	newrelic_rpm
PORTVERSION=	3.18.1.330
PORTREVISION=	1
CATEGORIES=	devel rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	3

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Performance management system for Rails applications

LICENSE=	MIT NEWRELIC RUBY
LICENSE_COMB=	multi
LICENSE_NAME_NEWRELIC=	New Relic License
LICENSE_FILE_NEWRELIC=	${WRKSRC}/LICENSE
LICENSE_PERMS_NEWRELIC=	dist-mirror no-dist-sell pkg-mirror no-pkg-sell auto-accept

PORTSCOUT=	limit:^3\.

NO_ARCH=	yes
USE_RUBY=	yes
USES=		gem shebangfix

PLIST_FILES=	bin/mongrel_rpm bin/newrelic bin/newrelic_cmd bin/nrdebug

SHEBANG_FILES=	test/script/*.sh test/script/before_*/*.sh

.include <bsd.port.mk>
