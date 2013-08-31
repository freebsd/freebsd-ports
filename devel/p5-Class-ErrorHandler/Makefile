# $FreeBSD$

PORTNAME=	Class-ErrorHandler
PORTVERSION=	0.03
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	lth@FreeBSD.org
COMMENT=	Base class for error handling

USES=		perl5
USE_PERL5=	modbuild

MAN3=	Class::ErrorHandler.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 501400
BUILD_DEPENDS+=	p5-CPAN-Meta>=0:${PORTSDIR}/devel/p5-CPAN-Meta
RUN_DEPENDS+=	p5-CPAN-Meta>=0:${PORTSDIR}/devel/p5-CPAN-Meta
.endif

.include <bsd.port.post.mk>
