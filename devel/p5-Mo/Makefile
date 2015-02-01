# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Mo
PORTVERSION=	0.39
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:INGY
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Micro Objects. Mo is less

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

TEST_DEPENDS=	p5-Class-XSAccessor>=0:${PORTSDIR}/devel/p5-Class-XSAccessor \
		p5-IO-All>=0:${PORTSDIR}/devel/p5-IO-All \
		p5-Moose>=0:${PORTSDIR}/devel/p5-Moose \
		p5-Mouse>=0:${PORTSDIR}/devel/p5-Mouse \
		p5-PPI>=0:${PORTSDIR}/textproc/p5-PPI \
		p5-Test-NoTabs>=0:${PORTSDIR}/devel/p5-Test-NoTabs

USE_PERL5=	configure
USES=		perl5

post-install:
	# These are essentially just copies of Mo.3.gz
	@${FIND} ${STAGEDIR} -type f -name 'ReadMe*' -delete

.include <bsd.port.mk>
