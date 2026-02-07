PORTNAME=	iconv
PORTVERSION=	1.1.1
CATEGORIES=	converters rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	iconv wrapper library
WWW=		https://github.com/ruby/iconv

LICENSE=	BSD2CLAUSE RUBY
LICENSE_COMB=	dual
LICENSE_FILE_BSD2CLAUSE=${WRKSRC}/BSDL
LICENSE_FILE_RUBY=	${WRKSRC}/COPYING

USES=		gem iconv

CONFIGURE_ARGS=	--with-cflags=-Wno-incompatible-function-pointer-types

.include <bsd.port.mk>
