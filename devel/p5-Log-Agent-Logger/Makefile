# New ports collection makefile for:	Log-Agent-Logger
# Date created:		4 Aug 2002
# Whom:			devin@spamcop.net
#
# $FreeBSD$
#

PORTNAME=	Log-Agent-Logger
PORTVERSION=	0.1.1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Log
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@freebsd.org
COMMENT=	Log::Agent::Logger - a logging interface for perl

BUILD_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/Log/Agent.pm:${PORTSDIR}/devel/p5-Log-Agent \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/Getargs/Long.pm:${PORTSDIR}/devel/p5-Getargs-Long
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}
MAN3=		Log::Agent::Logger.3

.include <bsd.port.mk>
