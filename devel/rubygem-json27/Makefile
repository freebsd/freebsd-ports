PORTNAME=	json
PORTVERSION=	2.7.6
CATEGORIES=	devel rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	27

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	JSON implementation as a Ruby extension in C
WWW=		https://ruby.github.io/json/ \
		https://github.com/ruby/json/releases

LICENSE=	BSD2CLAUSE RUBY
LICENSE_COMB=	dual
LICENSE_FILE_BSD2CLAUSE=${WRKSRC}/BSDL
LICENSE_FILE_RUBY=	${WRKSRC}/COPYING

USES=		gem

PORTSCOUT=	limit:^2\.7\.

.include <bsd.port.mk>
