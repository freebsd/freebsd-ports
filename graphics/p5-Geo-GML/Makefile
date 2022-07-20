PORTNAME=	Geo-GML
PORTVERSION=	0.18
CATEGORIES=	graphics perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl Module to Process Geography Markup Language

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Log-Report>=1.25:devel/p5-Log-Report \
		p5-XML-Compile>=1.59:textproc/p5-XML-Compile \
		p5-XML-Compile-Cache>=1.05:textproc/p5-XML-Compile-Cache

NO_ARCH=	yes
USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
