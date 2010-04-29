# New ports collection makefile for:	pushmi
# Date created:				Dec 29 2006
# Whom:					Rong-En Fan <rafan@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	pushmi
PORTVERSION=	1.0.0
PORTREVISION=	4
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../../authors/id/C/CL/CLKAO
DISTNAME=	Pushmi-v${PORTVERSION}

MAINTAINER=	rafan@FreeBSD.org
COMMENT=	Subversion repository replication tool

RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/SVN/Core.pm:${PORTSDIR}/devel/p5-subversion \
		p5-App-CLI>=0.06:${PORTSDIR}/devel/p5-App-CLI \
		p5-Cache-Memcached>=0:${PORTSDIR}/databases/p5-Cache-Memcached \
		p5-Log-Log4perl>=0:${PORTSDIR}/devel/p5-Log-Log4perl \
		p5-YAML-Syck>=0:${PORTSDIR}/textproc/p5-YAML-Syck \
		p5-version>=0:${PORTSDIR}/devel/p5-version \
		svk>=2.0.0:${PORTSDIR}/devel/svk
BUILD_DEPENDS=	${RUN_DEPENDS} \
		p5-IPC-Run3>=0:${PORTSDIR}/devel/p5-IPC-Run3 \
		p5-RunApp>=0.13:${PORTSDIR}/devel/p5-RunApp \
		p5-Test-Output>=0:${PORTSDIR}/devel/p5-Test-Output \
		${SITE_PERL}/${PERL_ARCH}/mod_perl2.pm:${PORTSDIR}/www/mod_perl2

PERL_CONFIGURE=	yes

MAN3=		Pushmi.3 \
		Pushmi::Command::Mirror.3 \
		Pushmi::Command::Runhook.3 \
		Pushmi::Command::Sync.3 \
		Pushmi::Command::Verify.3

.include <bsd.port.mk>
