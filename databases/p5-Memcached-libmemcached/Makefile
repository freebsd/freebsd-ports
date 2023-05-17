PORTNAME=	Memcached-libmemcached
PORTVERSION=	1.001801
PORTREVISION=	1
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

.if ${OPSYS} == FreeBSD && ( ${OSVERSION} >= 1400079 || ( ${OSVERSION} >= 1302505 && ${OSVERSION} < 1400000 ))
CFLAGS+=       -Wno-error=int-conversion
.endif

post-extract:
	@${RM} -r ${WRKDIR}/src

post-patch:
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g' ${WRKSRC}/Makefile.PL

.include <bsd.port.post.mk>
