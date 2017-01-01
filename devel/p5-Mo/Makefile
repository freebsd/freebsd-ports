# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Mo
PORTVERSION=	0.40
PORTEPOCH=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:TINITA
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Micro Objects. Mo is less

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

TEST_DEPENDS=	p5-Class-XSAccessor>=0:devel/p5-Class-XSAccessor \
		p5-IO-All>=0:devel/p5-IO-All \
		p5-Moose>=0:devel/p5-Moose \
		p5-Mouse>=0:devel/p5-Mouse \
		p5-PPI>=0:textproc/p5-PPI \
		p5-Test-NoTabs>=0:devel/p5-Test-NoTabs

NO_ARCH=	yes
USE_PERL5=	configure
USES=		perl5

post-patch:
	@${RM} ${WRKSRC}/ReadMe.pod

.include <bsd.port.mk>
