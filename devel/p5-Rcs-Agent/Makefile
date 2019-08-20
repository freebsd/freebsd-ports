# Created by: Anton Berezin <tobez@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Rcs-Agent
PORTVERSION=	1.05
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	mats@dufberg.se
COMMENT=	Perl module for RCS archive manipulation

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-String-ShellQuote>1.00:textproc/p5-String-ShellQuote
.if !exists(/usr/bin/rcs)
RUN_DEPENDS+=	rcs:devel/rcs57
.endif

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
