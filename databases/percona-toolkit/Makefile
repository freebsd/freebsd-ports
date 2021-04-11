PORTNAME=	percona-toolkit
PORTVERSION=	3.3.0
CATEGORIES=	databases
MASTER_SITES=	https://www.percona.com/downloads/${PORTNAME}/${PORTVERSION}/source/tarball/

MAINTAINER=	flo@FreeBSD.org
COMMENT=	Collection of essential command-line utilities for MySQL

LICENSE=	ARTPERL10 GPLv2
LICENSE_COMB=	dual

RUN_DEPENDS=	bash:shells/bash \
		p5-DBD-mysql>=3:databases/p5-DBD-mysql \
		p5-DBI>=1.46:databases/p5-DBI \
		p5-Term-ReadKey>=2.10:devel/p5-Term-ReadKey

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
