PORTNAME=	atomic
PORTVERSION=	1.1.101
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Atomic reference implementation
WWW=		https://github.com/ruby-concurrency/atomic

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		gem

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD && ( ${OSVERSION} >= 1400079 || ( ${OSVERSION} >= 1302505 && ${OSVERSION} < 1400000 ))
CONFIGURE_ARGS+=	--with-cflags="-Wno-error=int-conversion"
.endif

.include <bsd.port.mk>
