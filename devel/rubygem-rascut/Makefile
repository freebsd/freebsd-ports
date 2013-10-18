# $FreeBSD$

PORTNAME=	rascut
PORTVERSION=	0.2.1
PORTREVISION=	1
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Ruby ActionSCript UTility

DEPRECATED=	Does not work with Ruby 1.9
EXPIRATION_DATE=	2013-10-21

RUN_DEPENDS=	mongrel_rails:${PORTSDIR}/www/rubygem-mongrel \
		rubygem-json_pure>=0:${PORTSDIR}/devel/rubygem-json_pure \
		rackup:${PORTSDIR}/www/rubygem-rack \
		fcsh:${PORTSDIR}/devel/flex-sdk

USE_RUBY=	yes
USE_RAKE=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes
PLIST_FILES=	bin/rascut

NO_STAGE=	yes
.include <bsd.port.mk>
