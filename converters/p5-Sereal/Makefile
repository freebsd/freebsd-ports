# $FreeBSD$

PORTNAME?=	Sereal
PORTVERSION=	4.012
CATEGORIES=	converters perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:YVES
PKGNAMEPREFIX=	p5-

MAINTAINER=	adamw@FreeBSD.org
COMMENT?=	Perl extension for fast, compact, powerful binary (de-)serialization

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

TEST_DEPENDS=	p5-Test-Deep>=0:devel/p5-Test-Deep \
		p5-Test-LongString>=0:devel/p5-Test-LongString \
		p5-Test-Warn>=0:devel/p5-Test-Warn

USES=		perl5
USE_PERL5=	configure
MAKE_JOBS_UNSAFE=	yes

.if empty(SLAVE_PORT)
BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Sereal-Decoder>=${PORTVERSION}:converters/p5-Sereal-Decoder \
		p5-Sereal-Encoder>=${PORTVERSION}:converters/p5-Sereal-Encoder

NO_ARCH=	yes

.else
LIB_DEPENDS=	libzstd.so:archivers/zstd

MAKE_ENV+=	PASTHRU_DEFINE="-I${LOCALBASE}/include"

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/Sereal/${PORTNAME:C/Sereal-//}/*.so
.endif

.include <bsd.port.mk>
