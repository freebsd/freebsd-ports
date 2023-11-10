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

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD && ((${OSVERSION} >= 1302507 && ${OSVERSION} < 1400000) || ${OSVERSION} >= 1400091)
CONFIGURE_ARGS+=--with-cflags="-Wno-error=incompatible-function-pointer-types"
.endif

.include <bsd.port.mk>
