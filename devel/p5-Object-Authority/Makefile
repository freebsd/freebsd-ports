# New ports collection makefile for:	p5-object-authority
# Date created:		2012-02-29
# Whom:			Steve Wills <swills@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Object-AUTHORITY
PORTVERSION=	0.004
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl module that adds an AUTHORITY method to your class

BUILD_DEPENDS=	p5-Object-Role>=0:${PORTSDIR}/devel/p5-Object-Role
RUN_DEPENDS=	p5-Object-Role>=0:${PORTSDIR}/devel/p5-Object-Role
TEST_DEPENDS=	p5-Test-Exception>=0:${PORTSDIR}/devel/p5-Test-Exception

PERL_CONFIGURE=	yes

MAN3=	Object::AUTHORITY.3

.include <bsd.port.mk>
