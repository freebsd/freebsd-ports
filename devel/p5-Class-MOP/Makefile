# New ports collection makefile for:	devel/p5-Class-MOP
# Date created:				14 Apr 2006
# Whom:					Lars Balker Rasmussen <lbr@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Class-MOP
PORTVERSION=	0.31
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	../by-authors/id/S/ST/STEVAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	lbr@FreeBSD.org
COMMENT=	A Meta Object Protocol for Perl 5

BUILD_DEPENDS=	${RUN_DEPENDS} \
	p5-Test-Simple>=0.62:${PORTSDIR}/devel/p5-Test-Simple \
	p5-Test-Exception>=0.21:${PORTSDIR}/devel/p5-Test-Exception
RUN_DEPENDS=	\
	p5-Scalar-List-Utils>=1.18:${PORTSDIR}/lang/p5-Scalar-List-Utils \
	p5-Sub-Name>=0.02:${PORTSDIR}/devel/p5-Sub-Name

PERL_MODBUILD=	yes

MAN3=	Class::MOP.3 \
	Class::MOP::Attribute.3 \
	Class::MOP::Class.3 \
	Class::MOP::Class::Immutable.3 \
	Class::MOP::Instance.3 \
	Class::MOP::Method.3 \
	Class::MOP::Module.3 \
	Class::MOP::Package.3 \
	metaclass.3

post-install:
	@${MKDIR} ${EXAMPLESDIR}
	@${INSTALL_DATA} ${WRKSRC}/examples/* ${EXAMPLESDIR}
	@${ECHO_MSG} "===> Examples installed in ${EXAMPLESDIR}."

.include <bsd.port.pre.mk>
.if ${PERL_LEVEL} < 500800
IGNORE=	requires perl 5.8.0 or later. Install lang/perl5.8 and try again
.endif
.include <bsd.port.post.mk>
