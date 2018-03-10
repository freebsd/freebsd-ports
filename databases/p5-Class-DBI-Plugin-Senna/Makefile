# $FreeBSD$

PORTNAME=	Class-DBI-Plugin-Senna
PORTVERSION=	0.01
PORTREVISION=	2
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Add Instant Fulltext Search Capability With Senna to Class::DBI

BUILD_DEPENDS=	p5-Class-DBI>=0:databases/p5-Class-DBI \
	p5-Senna>=0:textproc/p5-Senna

USES=		perl5
USE_PERL5=	configure

# With $TRYBROKEN, do "perl Makefile.PL" in verbose mode.
do-configure:
	cd ${CONFIGURE_WRKSRC} && \
		${SETENV} ${CONFIGURE_ENV} \
		${PERL5} ${CONFIGURE_CMD} ${CONFIGURE_ARGS}

.include <bsd.port.mk>
