# $FreeBSD$

PORTNAME=	parser
PORTVERSION=	2.3.1.0
CATEGORIES=	devel ruby
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Ruby parser written in pure Ruby

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-ast>=2.2:devel/rubygem-ast

NO_ARCH=	yes
USE_RUBY=	yes
USES=		gem

PLIST_FILES=	bin/ruby-parse bin/ruby-rewrite

.include <bsd.port.mk>
