# New ports collection makefile for:	Log::Any::App
# Date created:		22 Mar 2011
# Whom:			Evgeniy Kosov <evgeniy@kosov.su>
#
# $FreeBSD$
#

PORTNAME=	Log-Any-App
PORTVERSION=	0.35
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	An easy way to use Log::Any in applications

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-File-HomeDir>=0:${PORTSDIR}/devel/p5-File-HomeDir \
		p5-File-Slurp>=0:${PORTSDIR}/devel/p5-File-Slurp \
		p5-Log-Any>=0.11:${PORTSDIR}/devel/p5-Log-Any \
		p5-Log-Any-Adapter>=0:${PORTSDIR}/devel/p5-Log-Any-Adapter \
		p5-Log-Any-Adapter-Log4perl>=0:${PORTSDIR}/devel/p5-Log-Any-Adapter-Log4perl \
		p5-Log-Dispatch>=0:${PORTSDIR}/devel/p5-Log-Dispatch \
		p5-Log-Dispatch-Dir>=0.08:${PORTSDIR}/devel/p5-Log-Dispatch-Dir \
		p5-Log-Dispatch-FileRotate>=0:${PORTSDIR}/devel/p5-Log-Dispatch-FileRotate \
		p5-Log-Log4perl>=0:${PORTSDIR}/devel/p5-Log-Log4perl
RUN_DEPENDS:=	${BUILD_DEPENDS}

PERL_MODBUILD=	yes

MAN3=		Log::Any::App.3

.include <bsd.port.mk>
