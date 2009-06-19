# New ports collection makefile for:	devel/p5-Class-MOP
# Date created:				14 Apr 2006
# Whom:					Lars Balker Rasmussen <lbr@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Class-MOP
PORTVERSION=	0.86
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	lbr@FreeBSD.org
COMMENT=	A Meta Object Protocol for Perl 5

BUILD_DEPENDS=	p5-Devel-GlobalDestruction>=0:${PORTSDIR}/devel/p5-Devel-GlobalDestruction \
		p5-MRO-Compat>=0.05:${PORTSDIR}/devel/p5-MRO-Compat \
		p5-Sub-Identify>=0.03:${PORTSDIR}/devel/p5-Sub-Identify \
		p5-Sub-Name>=0.04:${PORTSDIR}/devel/p5-Sub-Name \
		p5-Task-Weaken>=0:${PORTSDIR}/devel/p5-Task-Weaken
RUN_DEPENDS=	${BUILD_DEPENDS}

MAKE_JOBS_UNSAFE=	yes

MAKE_JOBS_UNSAFE=	yes

PERL_CONFIGURE=	5.8.1+
CFLAGS=		-I.

MAN3=	Class::MOP.3 \
	Class::MOP::Attribute.3 \
	Class::MOP::Class.3 \
	Class::MOP::Class::Immutable::Class::MOP::Class.3 \
	Class::MOP::Class::Immutable::Trait.3 \
	Class::MOP::Instance.3 \
	Class::MOP::Method.3 \
	Class::MOP::Method::Accessor.3 \
	Class::MOP::Method::Constructor.3 \
	Class::MOP::Method::Generated.3 \
	Class::MOP::Method::Inlined.3 \
	Class::MOP::Method::Wrapped.3 \
	Class::MOP::Module.3 \
	Class::MOP::Object.3 \
	Class::MOP::Package.3 \
	metaclass.3

post-extract:
	@${PERL} -i -ne 'print unless m,^test_req,' ${WRKSRC}/Makefile.PL

post-install:
.ifndef(NOPORTEXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}
	@${INSTALL_DATA} ${WRKSRC}/examples/* ${EXAMPLESDIR}
	@${ECHO_MSG} "===> Examples installed in ${EXAMPLESDIR}."
.endif

.include <bsd.port.mk>
