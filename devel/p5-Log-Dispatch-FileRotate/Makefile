# New ports collection makefile for:	p5-Log-Dispatch-FileRotate
# Date created:				Tue Jul  1 15:14:38 CEST 2003
# Whom:					Lars Thegler <lars@thegler.dk>
#
# $FreeBSD$
#

PORTNAME=	Log-Dispatch-FileRotate
PORTVERSION=	1.19
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	lth@FreeBSD.org
COMMENT=	A Log::Dispatch plug-in for files that archive/rotate themselves

BUILD_DEPENDS=	p5-Log-Dispatch>=0:${PORTSDIR}/devel/p5-Log-Dispatch \
		p5-Date-Manip>=0:${PORTSDIR}/devel/p5-Date-Manip \
		p5-Params-Validate>=0:${PORTSDIR}/devel/p5-Params-Validate \
		p5-Log-Log4perl>=0:${PORTSDIR}/devel/p5-Log-Log4perl
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

MAN3=		Log::Dispatch::FileRotate.3

.include <bsd.port.mk>
