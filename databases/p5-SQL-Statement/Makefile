PORTNAME=	SQL-Statement
PORTVERSION=	1.414
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl5 module for SQL parsing and processing

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE_ART10=	${WRKSRC}/ARTISTIC-1.0
LICENSE_FILE_GPLv1+ =	${WRKSRC}/GPL-1

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Clone>=0.30:devel/p5-Clone \
		p5-Module-Runtime>=0:devel/p5-Module-Runtime \
		p5-Params-Util>=1.00:devel/p5-Params-Util

NO_ARCH=	yes
USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
