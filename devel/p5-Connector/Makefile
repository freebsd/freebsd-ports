# Created by: Sergei Vyshenski <svysh.fbsd@gmail.com>
# $FreeBSD$

PORTNAME=	Connector
PORTVERSION=	1.15
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	svysh.fbsd@gmail.com
COMMENT=	Generic connection to a hierarchical-structured data set

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	\
		p5-Config-GitLike>=0:${PORTSDIR}/devel/p5-Config-GitLike \
		${LOCALBASE}/bin/bash:${PORTSDIR}/shells/bash \
		p5-YAML>=1.06:${PORTSDIR}/textproc/p5-YAML \
		p5-Template-Toolkit>=0:${PORTSDIR}/www/p5-Template-Toolkit \
		p5-AppConfig>=0:${PORTSDIR}/devel/p5-AppConfig \
		p5-Config-Versioned>=1.01:${PORTSDIR}/devel/p5-Config-Versioned \
		p5-Log-Log4perl>=0:${PORTSDIR}/devel/p5-Log-Log4perl \
		p5-Module-Install>=0:${PORTSDIR}/devel/p5-Module-Install \
		p5-Moose>=0:${PORTSDIR}/devel/p5-Moose \
		p5-perl-ldap>=0:${PORTSDIR}/net/p5-perl-ldap \
		p5-Text-CSV_XS>=0:${PORTSDIR}/textproc/p5-Text-CSV_XS \
		p5-Proc-SafeExec>=0:${PORTSDIR}/devel/p5-Proc-SafeExec \

RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure
NO_ARCH=	yes

#pre-install:	test

.include <bsd.port.mk>
