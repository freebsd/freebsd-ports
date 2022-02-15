# Created by: Sergei Vyshenski <svysh.fbsd@gmail.com>

PORTNAME=	Connector
DISTVERSION=	1.44
CATEGORIES=	devel perl5
PKGNAMEPREFIX=	p5-

MAINTAINER=	svysh.fbsd@gmail.com
COMMENT=	Generic connection to a hierarchical-structured data set

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	bash:shells/bash \
		p5-AppConfig>=0:devel/p5-AppConfig \
		p5-Config-GitLike>=0:devel/p5-Config-GitLike \
		p5-Config-Std>=0:devel/p5-Config-Std \
		p5-Config-Versioned>=1.01:devel/p5-Config-Versioned \
		p5-Crypt-SSLeay>=0:security/p5-Crypt-SSLeay \
		p5-DBI>=0:databases/p5-DBI \
		p5-libwww>=0:www/p5-libwww \
		p5-Log-Log4perl>=0:devel/p5-Log-Log4perl \
		p5-Module-Install>=0:devel/p5-Module-Install \
		p5-Moose>=0:devel/p5-Moose \
		p5-perl-ldap>=0:net/p5-perl-ldap \
		p5-Proc-SafeExec>=0:devel/p5-Proc-SafeExec \
		p5-Template-Toolkit>=0:www/p5-Template-Toolkit \
		p5-Text-CSV_XS>=0:textproc/p5-Text-CSV_XS \
		p5-YAML>=1.06:textproc/p5-YAML
TEST_DEPENDS=	p5-Config-Merge>=0:devel/p5-Config-Merge \
		p5-DBD-SQLite>=0:databases/p5-DBD-SQLite

USES=		perl5
USE_GITHUB=	yes
GH_ACCOUNT=	mrscotty
GH_PROJECT=	${PORTNAME:tl}
USE_PERL5=	modbuildtiny
NO_ARCH=	yes

.include <bsd.port.mk>
