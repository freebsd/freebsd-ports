# New ports collection makefile for:	devel/p5-Rcs-Agent
# Date created:				28 October 2002
# Whom:					Anton Berezin <tobez@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Rcs-Agent
PORTVERSION=	1.05
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	nick@foobar.org
COMMENT=	A perl module for RCS archive manipulation

BUILD_DEPENDS=	p5-String-ShellQuote>1.00:${PORTSDIR}/textproc/p5-String-ShellQuote
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Rcs::Agent.3

.include <bsd.port.mk>
