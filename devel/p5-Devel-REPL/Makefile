# Created by: Ashish SHUKLA <wahjava@gmail.com>
# $FreeBSD$

PORTNAME=	Devel-REPL
PORTVERSION=	1.003025
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	ashish@FreeBSD.org
COMMENT=	Modern Perl interactive shell

BUILD_DEPENDS=	p5-Moose>=0.93:${PORTSDIR}/devel/p5-Moose \
	p5-MooseX-Object-Pluggable>=0.0009:${PORTSDIR}/devel/p5-MooseX-Object-Pluggable \
	p5-MooseX-Getopt>=0.18:${PORTSDIR}/devel/p5-MooseX-Getopt \
	p5-MooseX-AttributeHelpers>=0.16:${PORTSDIR}/devel/p5-MooseX-AttributeHelpers \
	p5-namespace-clean>0:${PORTSDIR}/devel/p5-namespace-clean \
	p5-namespace-autoclean>0:${PORTSDIR}/devel/p5-namespace-autoclean \
	p5-File-HomeDir>0:${PORTSDIR}/devel/p5-File-HomeDir \
	p5-Task-Weaken>0:${PORTSDIR}/devel/p5-Task-Weaken \
	p5-PPI>0:${PORTSDIR}/textproc/p5-PPI \
	p5-Data-Dump-Streamer>0:${PORTSDIR}/devel/p5-Data-Dump-Streamer \
	p5-Data-Dumper-Concise>0:${PORTSDIR}/devel/p5-Data-Dumper-Concise \
	p5-File-Next>0:${PORTSDIR}/sysutils/p5-File-Next \
	p5-B-Keywords>0:${PORTSDIR}/devel/p5-B-Keywords \
	p5-Lexical-Persistence>0:${PORTSDIR}/devel/p5-Lexical-Persistence \
	p5-App-Nopaste>0:${PORTSDIR}/www/p5-App-Nopaste \
	p5-Module-Refresh>0:${PORTSDIR}/devel/p5-Module-Refresh \
	p5-Sys-SigAction>0:${PORTSDIR}/devel/p5-Sys-SigAction
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
