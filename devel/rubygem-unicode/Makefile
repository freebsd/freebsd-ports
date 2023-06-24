PORTNAME=	unicode
PORTVERSION=	0.4.4.4
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Unicode string manipulation library for Ruby
WWW=		http://www.yoshidam.net/Ruby.html #unicode

LICENSE=	RUBY

USES=		gem

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD && ${OSVERSION} >= 1400091
CONFIGURE_ARGS+=	--with-cflags="-Wno-error=incompatible-function-pointer-types"
.endif

.include <bsd.port.mk>
