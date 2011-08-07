# New ports collection makefile for:	devel/p5-POE-Component-Syndicator
# Date created:	   2011-05-03
# Whom:		   Jase Thew <freebsd@beardz.net>
#
# $FreeBSD$
#

PORTNAME=	POE-Component-Syndicator
PORTVERSION=	0.06
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:HINRIK
PKGNAMEPREFIX=	p5-

MAINTAINER=	freebsd@beardz.net
COMMENT=	A POE component base class which implements the Observer pattern

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-POE>=1.311:${PORTSDIR}/devel/p5-POE \
		p5-Object-Pluggable>=1.29:${PORTSDIR}/devel/p5-Object-Pluggable \
		p5-Test-Simple>=0:${PORTSDIR}/devel/p5-Test-Simple
RUN_DEPENDS:=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		POE::Component::Syndicator.3

.include <bsd.port.mk>
