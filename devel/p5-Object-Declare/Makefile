# New ports collection makefile for:	p5-Object-Declare
# Date created:		2006-07-19
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	Object-Declare
PORTVERSION=	0.08
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Object
PKGNAMEPREFIX=	p5-

MAINTAINER=	gslin@gslin.org
COMMENT=	Declarative object constructor

RUN_DEPENDS=	${SITE_PERL}/Sub/Override.pm:${PORTSDIR}/devel/p5-Sub-Override

PERL_CONFIGURE=	yes

MAN3=		Object::Declare.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600	# Inherited from p5-Sub-Override
IGNORE=		requires perl 5.6.x or later. Install lang/perl5 then try again
.endif

.include <bsd.port.post.mk>
