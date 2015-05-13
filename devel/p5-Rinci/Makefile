# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Rinci
PORTVERSION=	1.1.77
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:PERLANCAR
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Language-neutral metadata for your code entities

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-DefHash>=1.0.6:${PORTSDIR}/devel/p5-DefHash \
		p5-Sah>=0.9.34:${PORTSDIR}/devel/p5-Sah
RUN_DEPENDS:=	${BUILD_DEPENDS}
BUILD_DEPENDS+=	p5-Perl-osnames>=0.09:${PORTSDIR}/devel/p5-Perl-osnames

USE_PERL5=	configure
USES=		perl5

.include <bsd.port.mk>
