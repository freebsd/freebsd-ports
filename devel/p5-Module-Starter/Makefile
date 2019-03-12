# Created by: clsung
# $FreeBSD$

PORTNAME=	Module-Starter
PORTVERSION=	1.76
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Simple starter kit for any Perl module

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Module-Runtime>=0:devel/p5-Module-Runtime \
		p5-Software-License>=0.103005:misc/p5-Software-License

PORTSCOUT=	skipv:1.470

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
