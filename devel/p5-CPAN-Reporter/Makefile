# Created by: Steve Wills <swills@FreeBSD.org>
# $FreeBSD$

PORTNAME=	CPAN-Reporter
PORTVERSION=	1.2014
CATEGORIES=	devel
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:DAGOLDEN
PKGNAMEPREFIX=	p5-

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Adds CPAN Testers reporting to CPAN.pm

BUILD_DEPENDS=	p5-Capture-Tiny>0:${PORTSDIR}/devel/p5-Capture-Tiny \
		p5-Config-Tiny>0:${PORTSDIR}/devel/p5-Config-Tiny \
		p5-Devel-Autoflush>0:${PORTSDIR}/devel/p5-Devel-Autoflush \
		p5-File-HomeDir>0:${PORTSDIR}/devel/p5-File-HomeDir \
		p5-IPC-Cmd>=0.76:${PORTSDIR}/devel/p5-IPC-Cmd \
		p5-Probe-Perl>0:${PORTSDIR}/sysutils/p5-Probe-Perl \
		p5-Test-Reporter>1.54:${PORTSDIR}/devel/p5-Test-Reporter
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
