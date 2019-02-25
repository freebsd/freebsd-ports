# Created by: Anes Mukhametov <anes@anes.su>
# $FreeBSD$

PORTNAME=	AnyEvent-Connection
PORTVERSION=	0.06
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	anes@anes.su
COMMENT=	Base class for TCP connectful clients

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	p5-AnyEvent>=5:devel/p5-AnyEvent \
		p5-Object-Event>=1.21:devel/p5-Object-Event \
		p5-common-sense>=2:devel/p5-common-sense \
		p5-Test-NoWarnings>=1.03:devel/p5-Test-NoWarnings \
		p5-Test-TCP>=0.14:devel/p5-Test-TCP \
		p5-lib-abs>=0.90:devel/p5-lib-abs
RUN_DEPENDS=	p5-AnyEvent>=5:devel/p5-AnyEvent \
		p5-Object-Event>=1.21:devel/p5-Object-Event \
		p5-common-sense>=2:devel/p5-common-sense

USES=		perl5
USE_PERL5=	configure
NO_ARCH=	yes

.include <bsd.port.mk>
