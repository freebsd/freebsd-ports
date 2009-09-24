# New ports collection makefile for:	p5-pip
# Date created:				September 21st 2009
# Whom:	      				Cezary Morga <cm@therek.net>
#
# $FreeBSD$
#

PORTNAME=	pip
PORTVERSION=	0.13
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../by-authors/id/A/AD/ADAMK
PKGNAMEPREFIX=	p5-

MAINTAINER=	cm@therek.net
COMMENT=	Perl Installation Program

BUILD_DEPENDS=	p5-CPAN-Inject>=0.07:${PORTSDIR}/devel/p5-CPAN-Inject \
		p5-File-Which>=0.05:${PORTSDIR}/sysutils/p5-File-Which \
		p5-File-pushd>=0.32:${PORTSDIR}/devel/p5-File-pushd \
		p5-Params-Util>=0.21:${PORTSDIR}/devel/p5-Params-Util \
		p5-URI>=0:${PORTSDIR}/net/p5-URI \
		p5-libwww>=0:${PORTSDIR}/www/p5-libwww
RUN_DEPENDS:=	${BUILD_DEPENDS}

PERL_CONFIGURE=	YES

MAN3=		Module::Plan::Base.3 \
		Module::Plan::Lite.3 \
		pip.3

.include <bsd.port.mk>
