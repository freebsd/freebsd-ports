PORTNAME=	iconv
PORTVERSION=	1.0.8
CATEGORIES=	converters rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	iconv wrapper library
WWW=		https://github.com/ruby/iconv

LICENSE=	BSD2CLAUSE RUBY
LICENSE_COMB=	dual
LICENSE_FILE_BSD2CLAUSE=${WRKSRC}/BSDL
LICENSE_FILE_RUBY=	${WRKSRC}/LICENSE.txt

USES=		gem iconv

CONFIGURE_ARGS=	--with-cflags=-Wno-incompatible-function-pointer-types

.include <bsd.port.mk>
