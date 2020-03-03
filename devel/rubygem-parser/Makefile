# $FreeBSD$

PORTNAME=	parser
PORTVERSION=	2.7.0.4
CATEGORIES=	devel ruby
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Ruby parser written in pure Ruby

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-ast>=2.4.0<2.5:devel/rubygem-ast

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

PLIST_FILES=	bin/ruby-parse bin/ruby-rewrite

.include <bsd.port.mk>
