PORTNAME=	bzip2-ruby
PORTVERSION=	0.2.7
PORTREVISION=	2
CATEGORIES=	archivers rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Ruby C bindings to libbzip2
WWW=		https://github.com/brianmario/bzip2-ruby

LICENSE=	BSD2CLAUSE RUBY
LICENSE_COMB=	dual

DEPRECATED=	Does not work with ruby32
# Sync with the removal of ruby31
EXPIRATION_DATE=	2025-03-31

USES=		gem

BROKEN_RUBY32=	yes

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD && ( ${OSVERSION} >= 1400091 || ( ${OSVERSION} >= 1302507 && ${OSVERSION} < 1400000 ))
CONFIGURE_ARGS+=	--with-cflags="-Wno-error=incompatible-function-pointer-types"
.endif

.include <bsd.port.mk>
