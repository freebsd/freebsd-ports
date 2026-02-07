PORTNAME=	percona-toolkit
DISTVERSION=	3.5.2
PORTREVISION=	1
CATEGORIES=	databases
MASTER_SITES=	https://www.percona.com/downloads/${PORTNAME}/${PORTVERSION}/source/tarball/

MAINTAINER=	flo@FreeBSD.org
COMMENT=	Collection of essential command-line utilities for MySQL
WWW=		https://www.percona.com/software/percona-toolkit/

LICENSE=	ARTPERL10 GPLv2
LICENSE_COMB=	dual

RUN_DEPENDS=	bash:shells/bash \
		${DBD_MYSQL} \
		p5-DBI>=1.46:databases/p5-DBI \
		p5-Term-ReadKey>=2.10:devel/p5-Term-ReadKey \
		pidof:sysutils/pidof

USES=		mysql perl5 shebangfix
USE_PERL5=	configure

SHEBANG_FILES=	bin/pt-*

CONFLICTS_INSTALL=	p5-Pipeline # lib/perl5/site_perl/Pipeline.pm

NO_ARCH=	yes

.include <bsd.port.mk>
