# Created by: Steve Wills <swills@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pygments.rb
PORTVERSION=	0.6.3
PORTREVISION=	1
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Exposes the pygments syntax highlighter to Ruby

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-posix-spawn>=0.3.6:devel/rubygem-posix-spawn \
		rubygem-yajl-ruby>=1.2.0:devel/rubygem-yajl-ruby

NO_ARCH=	yes
USE_RUBY=	yes
USES=		gem

.include <bsd.port.mk>
