# New ports collection makefile for:	p5-Log-Dispatch-FileRotate
# Date created:				Tue Jul  1 15:14:38 CEST 2003
# Whom:					Lars Thegler <lars@thegler.dk>
#
# $FreeBSD$
#

PORTNAME=	Log-Dispatch-FileRotate
PORTVERSION=	1.15
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Log
PKGNAMEPREFIX=	p5-

MAINTAINER=	lth@FreeBSD.org
COMMENT=	A Log::Dispatch plug-in for files that archive/rotate themselves

BUILD_DEPENDS=	${SITE_PERL}/Log/Dispatch.pm:${PORTSDIR}/devel/p5-Log-Dispatch \
		${SITE_PERL}/Date/Manip.pm:${PORTSDIR}/devel/p5-Date-Manip \
		${SITE_PERL}/${PERL_ARCH}/Params/Validate.pm:${PORTSDIR}/devel/p5-Params-Validate \
		${SITE_PERL}/Log/Log4perl.pm:${PORTSDIR}/devel/p5-Log-Log4perl
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Log::Dispatch::FileRotate.3

.include <bsd.port.mk>
