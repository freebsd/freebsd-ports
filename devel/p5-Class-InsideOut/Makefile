# New ports collection makefile for:	p5-Class-InsideOut
# Date created:		2006-07-20
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	Class-InsideOut
PORTVERSION=	1.00
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Class
PKGNAMEPREFIX=	p5-

MAINTAINER=	gslin@gslin.org
COMMENT=	A safe, simple inside-out object construction kit

PERL_CONFIGURE=	yes

MAN3=		Class::InsideOut::Manual::About.3 Class::InsideOut.3 \
		Class::InsideOut::Manual::Advanced.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500701
RUN_DEPENDS+=	${SITE_PERL}/Class/ISA.pm:${PORTSDIR}/devel/p5-Class-ISA
.endif

.if ${PERL_LEVEL} < 500702
RUN_DEPENDS+=	${SITE_PERL}/Scalar/Util.pm:${PORTSDIR}/lang/p5-Scalar-List-Utils
.endif

.include <bsd.port.post.mk>
