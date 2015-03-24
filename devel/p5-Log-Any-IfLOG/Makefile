# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Log-Any-IfLOG
PORTVERSION=	0.02
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Load Log::Any only if LOG environment variable is true

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Log-Any>=0:${PORTSDIR}/devel/p5-Log-Any \
		p5-Perl-osnames>=0.09:${PORTSDIR}/devel/p5-Perl-osnames
RUN_DEPENDS=	p5-Log-Any>=0:${PORTSDIR}/devel/p5-Log-Any

USE_PERL5=	configure
USES=		perl5

.include <bsd.port.mk>
