# New ports collection makefile for:   Log-Dispatch-FileShared
# Date created:           3 February 2007
# Whom:                   Craig Manley
#
# $FreeBSD$
#

PORTNAME=	Log-Dispatch-FileShared
PORTVERSION=	1.02
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	A Log::Dispatch output class for logging to shared files

BUILD_DEPENDS=	${SITE_PERL}/Log/Dispatch.pm:${PORTSDIR}/devel/p5-Log-Dispatch \
		p5-Params-Validate>=0:${PORTSDIR}/devel/p5-Params-Validate
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Log::Dispatch::FileShared.3

.include <bsd.port.mk>
