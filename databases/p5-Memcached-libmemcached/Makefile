PORTNAME=	Memcached-libmemcached
PORTVERSION=	1.001801
PORTREVISION=	2
CATEGORIES=	databases devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Thin fast full interface to the libmemcached client API
WWW=		https://metacpan.org/release/Memcached-libmemcached

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

LIB_DEPENDS=	libmemcached.so:databases/libmemcached

USES=		perl5
USE_PERL5=	configure
USE_LDCONFIG=	yes

.include <bsd.port.pre.mk>

.if ${OPSYS} == FreeBSD
CFLAGS+=       -Wno-error=int-conversion
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g' ${WRKSRC}/Makefile.PL
	@${RM} -r ${WRKDIR}/src

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/Memcached/libmemcached/libmemcached.so

.include <bsd.port.post.mk>
