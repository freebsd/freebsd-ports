# Created by: Frederic Culot <culot@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Future
PORTVERSION=	0.07
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:PEVANS
PKGNAMEPREFIX=	p5-

MAINTAINER=	culot@FreeBSD.org
COMMENT=	Build objects representing outstanding operations

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

TEST_DEPENDS=	p5-Test-Fatal>0:${PORTSDIR}/devel/p5-Test-Fatal \
		p5-Test-Identity>0:${PORTSDIR}/devel/p5-Test-Identity \
		p5-Test-Refcount>0:${PORTSDIR}/devel/p5-Test-Refcount

PERL_MODBUILD=	yes

MAN3=		Future.3

PLIST_FILES=	%%SITE_PERL%%/Future.pm

.include <bsd.port.mk>
