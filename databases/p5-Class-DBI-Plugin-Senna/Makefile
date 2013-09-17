# Created by: Jun Kuriyama <kuriyama@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Class-DBI-Plugin-Senna
PORTVERSION=	0.01
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Add Instant Fulltext Search Capability With Senna to Class::DBI

BUILD_DEPENDS=	p5-Class-DBI>=0:${PORTSDIR}/databases/p5-Class-DBI \
	p5-Senna>=0:${PORTSDIR}/textproc/p5-Senna

USES=		perl5
USE_PERL5=	configure
MAN3=		Class::DBI::Plugin::Senna.3

.include <bsd.port.pre.mk>

.if ${ARCH} == ia64
BROKEN=		fails to configure with coredump

# With $TRYBROKEN, do "perl Makefile.PL" in verbose mode.
do-configure:
	cd ${CONFIGURE_WRKSRC} && \
		${SETENV} ${CONFIGURE_ENV} \
		${PERL5} ./${CONFIGURE_SCRIPT} ${CONFIGURE_ARGS}
.endif

.include <bsd.port.post.mk>
