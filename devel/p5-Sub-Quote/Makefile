PORTNAME=	Sub-Quote
PORTVERSION=	2.006008
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:HAARG
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Efficient generation of subroutines via string eval
WWW=		https://metacpan.org/pod/Sub::Quote

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

CONFLICTS_INSTALL=	p5-Moo-[01]* p5-Moo-2.00[0-2]*

.include <bsd.port.mk>
