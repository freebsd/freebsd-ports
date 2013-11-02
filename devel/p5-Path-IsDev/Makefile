# $FreeBSD$

PORTNAME=	Path-IsDev
PORTVERSION=	1.000000
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:KENTNL
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension to determine if path resembles dev source tree

RUN_DEPENDS=	\
	p5-Class-Tiny>=0.010:${PORTSDIR}/devel/p5-Class-Tiny \
	p5-File-HomeDir>0:${PORTSDIR}/devel/p5-File-HomeDir \
	p5-Module-Runtime>0:${PORTSDIR}/devel/p5-Module-Runtime \
	p5-Role-Tiny>0:${PORTSDIR}/devel/p5-Role-Tiny \
	p5-Sub-Exporter>0:${PORTSDIR}/devel/p5-Sub-Exporter
BUILD_DEPENDS=	${RUN_DEPENDS}

USES=		perl5
USE_PERL5=	modbuild

.include <bsd.port.mk>
