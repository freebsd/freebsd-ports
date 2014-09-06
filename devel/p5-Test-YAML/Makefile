# $FreeBSD$

PORTNAME=	Test-YAML
PORTVERSION=	1.05
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	svysh.fbsd@gmail.com
COMMENT=	Testing Module for YAML Implementations

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

RUN_DEPENDS=	p5-Test-Base>=0:${PORTSDIR}/devel/p5-Test-Base \
		p5-Text-Diff>=0:${PORTSDIR}/textproc/p5-Text-Diff \
		p5-Algorithm-Diff>=0:${PORTSDIR}/devel/p5-Algorithm-Diff \
		p5-Spiffy>=0:${PORTSDIR}/devel/p5-Spiffy \
		${LOCALBASE}/bin/bash:${PORTSDIR}/shells/bash

CONFLICTS=	p5-YAML-0.*

USES=		perl5 shebangfix
USE_PERL5=	configure

SHEBANG_FILES=	bin/test-yaml
bash_OLD_CMD=	/usr/bin/bash

.include <bsd.port.mk>
