# New ports collection makefile for:    p5-Test-Dependencies
# Date created:				2006-07-12
# Whom:	      				Jin-Shan Tseng <tjs@cdpa.nsysu.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	Test-Dependencies
PORTVERSION=	0.11
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	Ensure that your Makefile.PL specifies all module dependencies

BUILD_DEPENDS=	${SITE_PERL}/B/PerlReq.pm:${PORTSDIR}/devel/p5-rpm-build-perl \
		${SITE_PERL}/File/Find/Rule.pm:${PORTSDIR}/devel/p5-File-Find-Rule \
		${SITE_PERL}/IPC/Cmd.pm:${PORTSDIR}/devel/p5-IPC-Cmd \
		${SITE_PERL}/Module/CoreList.pm:${PORTSDIR}/devel/p5-Module-CoreList \
		${SITE_PERL}/PerlReq/Utils.pm:${PORTSDIR}/devel/p5-rpm-build-perl \
		${SITE_PERL}/Pod/Strip.pm:${PORTSDIR}/textproc/p5-Pod-Strip \
		p5-Test-Simple>=0.64:${PORTSDIR}/devel/p5-Test-Simple \
    		${SITE_PERL}/YAML.pm:${PORTSDIR}/textproc/p5-YAML
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Test::Dependencies.3 \
		Test::Dependencies::Heavy.3 \
		Test::Dependencies::Light.3

.include <bsd.port.mk>
