# New ports collection makefile for:	devel/p5-Rcs-Agent
# Date created:				28 October 2002
# Whom:					Anton Berezin <tobez@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Rcs-Agent
PORTVERSION=	1.03
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Rcs
PKGNAMEPREFIX=	p5-

MAINTAINER=	nick@foobar.org
COMMENT=	A perl module for RCS archive manipulation

BUILD_DEPENDS=	${SITE_PERL}/String/ShellQuote.pm:${PORTSDIR}/textproc/p5-String-ShellQuote
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Rcs::Agent.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500800
BUILD_DEPENDS+=	${SITE_PERL}/File/Temp.pm:${PORTSDIR}/devel/p5-File-Temp
RUN_DEPENDS+=	${SITE_PERL}/File/Temp.pm:${PORTSDIR}/devel/p5-File-Temp
.endif

.include <bsd.port.post.mk>
