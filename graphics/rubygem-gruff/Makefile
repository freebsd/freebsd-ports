# Created by: ijliao
# $FreeBSD$

PORTNAME=	gruff
PORTVERSION=	0.7.0
PORTREVISION=	1
CATEGORIES=	graphics rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Beautiful graphing library for Ruby using RMagick

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS=	rubygem-rmagick>=2.13.4<3:graphics/rubygem-rmagick

USES=		gem shebangfix
USE_RUBY=	yes

NO_ARCH=	yes

SHEBANG_FILES=	test/image_compare.rb
ruby_OLD_CMD=	ruby

.include <bsd.port.mk>
