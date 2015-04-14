# $FreeBSD$

PORTNAME=	percona-toolkit
PORTVERSION=	2.2.11
PORTREVISION=	1
CATEGORIES=	databases
MASTER_SITES=	http://www.percona.com/downloads/${PORTNAME}/${PORTVERSION}/tarball/

MAINTAINER=	flo@FreeBSD.org
COMMENT=	Collection of essential command-line utilities for MySQL

LICENSE=	ARTPERL10 GPLv2
LICENSE_COMB=	dual

RUN_DEPENDS=	bash:${PORTSDIR}/shells/bash \
		p5-DBD-mysql>=3:${PORTSDIR}/databases/p5-DBD-mysql \
		p5-DBI>=1.46:${PORTSDIR}/databases/p5-DBI \
		p5-Term-ReadKey>=2.10:${PORTSDIR}/devel/p5-Term-ReadKey

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
