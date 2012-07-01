# New ports collection makefile for:	devel/p5-String-Diff
# Date created:				29 Mar 2009
# Whom:					Lars Balker Rasmussen <lbr@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	String-Diff
PORTVERSION=	0.06
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Simple diff to String

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Algorithm-Diff>=0:${PORTSDIR}/devel/p5-Algorithm-Diff
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-Base>=0:${PORTSDIR}/devel/p5-Test-Base \
		p5-YAML>=0:${PORTSDIR}/textproc/p5-YAML

PERL_CONFIGURE=	yes

MAN3=		String::Diff.3

.include <bsd.port.mk>
